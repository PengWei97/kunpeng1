//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ComputePolycrystalElasticityTensor.h"
#include "RotationTensor.h"

registerMooseObject("PhaseFieldApp", ComputePolycrystalElasticityTensor);

InputParameters
ComputePolycrystalElasticityTensor::validParams()
{
  InputParameters params = ComputeElasticityTensorBase::validParams();
  params.addClassDescription(
      "Compute an evolving elasticity tensor coupled to a grain growth phase field model.");
  params.addRequiredParam<UserObjectName>(
      "grain_tracker", "Name of GrainTracker user object that provides RankFourTensors");
  params.addParam<Real>("length_scale", 1.0e-9, "Length scale of the problem, in meters");
  params.addParam<Real>("pressure_scale", 1.0e6, "Pressure scale of the problem, in pa");
  params.addRequiredCoupledVarWithAutoBuild(
      "v", "var_name_base", "op_num", "Array of coupled variables");
      // These methods add a coupled variable name pair.
      // This version of the method will build a vector if the given 
      // the base_name and num_name parameters exist in the input file
      // var_name_base = gr op_num = 2
      // (gr0,r1)
  return params;
}

ComputePolycrystalElasticityTensor::ComputePolycrystalElasticityTensor(
    const InputParameters & parameters)
  : ComputeElasticityTensorBase(parameters),
    _length_scale(getParam<Real>("length_scale")),
    _pressure_scale(getParam<Real>("pressure_scale")),
    _grain_tracker(getUserObject<GrainDataTracker<RankFourTensor>>("grain_tracker")),
    _op_num(coupledComponents("v")),
    // coupledComponents:number of components this variable has (usually 1)
    _vals(coupledValues("v")),
    // Vector of VariableValue pointers for each component of var_name
    _R(_Euler_angles)
    
    _D_elastic_tensor(_op_num),
    _JtoeV(6.24150974e18)
{
  // Loop over variables (ops)
  for (MooseIndex(_op_num) op_index = 0; op_index < _op_num; ++op_index)
  {
    // declare elasticity tensor derivative properties
    _D_elastic_tensor[op_index] = &declarePropertyDerivative<RankFourTensor>(
        _elasticity_tensor_name, getVar("v", op_index)->name());
        // delastic_tensor/dgr0,delastic_tensor/dgr1
  }
}

void
ComputePolycrystalElasticityTensor::computeQpElasticityTensor()
{
  // Get list of active order parameters from grain tracker
  const auto & op_to_grains = _grain_tracker.getVarToFeatureVector(_current_elem->id());
  // Returns a list of active unique feature ids for a particular element.
  // op_to_grains = 2

  // Calculate elasticity tensor
  _elasticity_tensor[_qp].zero();
  Real sum_h = 0.0;
  for (MooseIndex(op_to_grains) op_index = 0; op_index < op_to_grains.size(); ++op_index)
  {
    auto grain_id = op_to_grains[op_index];
    if (grain_id == FeatureFloodCount::invalid_id)
      continue;

    // Interpolation factor for elasticity tensors
    Real h = (1.0 + std::sin(libMesh::pi * ((*_vals[op_index])[_qp] - 0.5))) / 2.0;
    // if _val = 1, h = 1
    // if _val = 0.5, h = 0.5
    // if _val = 0, h = 0

    // Sum all rotated elasticity tensors
    _elasticity_tensor[_qp] += _grain_tracker.getData(grain_id) * h;
    // Used to transition the elastic tensor at the grain boundary
    sum_h += h;
  }

  const Real tol = 1.0e-10;
  sum_h = std::max(sum_h, tol);
  _elasticity_tensor[_qp] /= sum_h;

  _R.update(_Euler_angles_mat_prop[_qp]);
  _crysrot[_qp] = _R.transpose();

  // Calculate elasticity tensor derivative: Cderiv = dhdopi/sum_h * (Cop - _Cijkl)
  for (MooseIndex(_op_num) op_index = 0; op_index < _op_num; ++op_index)
    (*_D_elastic_tensor[op_index])[_qp].zero();

  for (MooseIndex(op_to_grains) op_index = 0; op_index < op_to_grains.size(); ++op_index)
  {
    auto grain_id = op_to_grains[op_index];
    if (grain_id == FeatureFloodCount::invalid_id)
      continue;

    Real dhdopi = libMesh::pi * std::cos(libMesh::pi * ((*_vals[op_index])[_qp] - 0.5)) / 2.0;
    RankFourTensor & C_deriv = (*_D_elastic_tensor[op_index])[_qp];

    C_deriv = (_grain_tracker.getData(grain_id) - _elasticity_tensor[_qp]) * dhdopi / sum_h;

    // Convert from XPa to eV/(xm)^3, where X is pressure scale and x is length scale;
    C_deriv *= _JtoeV * (_length_scale * _length_scale * _length_scale) * _pressure_scale;
  }
}
