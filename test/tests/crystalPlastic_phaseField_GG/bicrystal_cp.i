[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 3
  xmax = 1000
  ymax = 1000
  elem_type = QUAD4
  uniform_refine = 2
  skip_partitioning = true
  displacements = 'disp_x disp_y'
[]

[GlobalParams]
  op_num = 2
  var_name_base = gr
  volumetric_locking_correction = true
  use_displaced_mesh = true
[]

[Variables]
  [./PolycrystalVariables]
  [../]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
[]

[ICs]
  [./PolycrystalICs]
    [./BicrystalBoundingBoxIC]
      x1 = 0
      y1 = 0
      x2 = 500
      y2 = 1000
    [../]
  [../]
[]

[Functions]
  [./tdisp]
    type = ParsedFunction
    value = 0.01*t
  [../]
[]

[AuxVariables]
  # [./bnds]
  #   order = FIRST
  #   family = LAGRANGE
  # [../]
  # [./elastic_strain11]
  #   order = CONSTANT
  #   family = MONOMIAL
  # [../]
  # [./elastic_strain22]
  #   order = CONSTANT
  #   family = MONOMIAL
  # [../]
  # [./elastic_strain12]
  #   order = CONSTANT
  #   family = MONOMIAL
  # [../]
  # [./unique_grains]
  #   order = CONSTANT
  #   family = MONOMIAL
  # [../]
  # [./var_indices]
  #   order = CONSTANT
  #   family = MONOMIAL
  # [../]
  # [./C1111]
  #   order = CONSTANT
  #   family = MONOMIAL
  # [../]
  # [./active_bounds_elemental]
  #   # ？？
  #   order = CONSTANT
  #   family = MONOMIAL
  # [../]
  # [./euler_angle]
  #   order = CONSTANT
  #   family = MONOMIAL
  # [../]
[]

[Kernels]
  [./PolycrystalKernel]
  [../]
  [./PolycrystalElasticDrivingForce]
    # adds the elastic driving force for each order parameter
    # get:_elastic_strain<--ComputeSmallStrain
    # Input:op_num = 2,var_name_base = gr
    # output:D_stiff_name = delasticity_tensor/dgr0
    # call:ACGrGrElasticDrivingForce
      # Calculates the porton of the Allen-Cahn equation that results from the deformation energy.
      # public ACBulk
      # Input:_D_elastic_tensor,_elastic_strain
        # get：_D_elastic_tensor,
        # get:_elastic_strain<--ComputeSmallStrain
  [../]
  [./TensorMechanics]
    displacements = 'disp_x disp_y'
  [../]
[]

[AuxKernels]
  # [./bnds_aux]
  #   type = BndsCalcAux
  #   variable = bnds
  #   execute_on = timestep_end
  # [../]
  # [./elastic_strain11]
  #   type = RankTwoAux
  #   variable = elastic_strain11
  #   rank_two_tensor = elastic_strain
  #   index_i = 0
  #   index_j = 0
  #   execute_on = timestep_end
  # [../]
  # [./elastic_strain22]
  #   type = RankTwoAux
  #   variable = elastic_strain22
  #   rank_two_tensor = elastic_strain
  #   index_i = 1
  #   index_j = 1
  #   execute_on = timestep_end
  # [../]
  # [./elastic_strain12]
  #   type = RankTwoAux
  #   variable = elastic_strain12
  #   rank_two_tensor = elastic_strain
  #   index_i = 0
  #   index_j = 1
  #   execute_on = timestep_end
  # [../]
  # [./unique_grains]
  #   type = FeatureFloodCountAux
  #   variable = unique_grains
  #   flood_counter = grain_tracker
  #   execute_on = 'initial timestep_begin'
  #   field_display = UNIQUE_REGION
  # [../]
  # [./var_indices]
  #   type = FeatureFloodCountAux
  #   variable = var_indices
  #   flood_counter = grain_tracker
  #   execute_on = 'initial timestep_begin'
  #   field_display = VARIABLE_COLORING
  # [../]
  # [./C1111]
  #   type = RankFourAux
  #   variable = C1111
  #   rank_four_tensor = elasticity_tensor
  #   index_l = 0
  #   index_j = 0
  #   index_k = 0
  #   index_i = 0
  #   execute_on = timestep_end
  # [../]
  # [./active_bounds_elemental]
  #   type = FeatureFloodCountAux
  #   variable = active_bounds_elemental
  #   field_display = ACTIVE_BOUNDS
  #   execute_on = 'initial timestep_begin'
  #   flood_counter = grain_tracker
  # [../]
  # [./euler_angle]
  #   type = OutputEulerAngles
  #   variable = euler_angle
  #   euler_angle_provider = euler_angle_file
  #   # Name of Euler angle provider user object
  #   grain_tracker = grain_tracker
  #   # The GrainTracker UserObject to get values from.
  #   output_euler_angle = 'phi1'
  #   # "phi1 Phi phi2
  # [../]
[]

[BCs]
  [./fix_x]
    type = DirichletBC
    variable = disp_x
    boundary = 'left'
    value = 0
  [../]
  [./fix_y]
    type = DirichletBC
    variable = disp_y
    boundary = 'bottom'
    value = 0
  [../]
  [./tdisp]
    type = FunctionDirichletBC
    variable = disp_y
    boundary = top
    function = tdisp
  [../]
[]

[Materials]
  [./Copper]
    type = GBEvolution
    block = 0
    T = 500 # K
    wGB = 75 # nm
    GBmob0 = 2.5e-6 #m^4/(Js) from Schoenfelder 1997
    Q = 0.23 #Migration energy in eV
    GBenergy = 0.708 #GB energy in J/m^2
    # No need to change material parameters
    time_scale = 1.0e-6 # μs
    # length_scale = 1.0e-9 # nm
  [../]
  [./ElasticityTensor]
    type = ComputePolycrystalElasticityTensor
    # Compute an evolving elasticity tensor coupled to a grain growth phase field model.
    # public：ComputeElasticityTensorBase
    # length_scale = 1.0e-9
    # pressure_scale = 1.0e6
    grain_tracker = grain_tracker
    # Name of GrainTracker user object that provides RankFourTensors
    # outputs = exodus
    # input：grain_tracker,c_ijkl no_rotationed,length_scale,pressure_scale,v
    # output：elasticity_tensor81,dElasticity_Tensor/dgr0_81，dElasticity_Tensor/dgr1_81
  [../]
  [./strain] # ok
    # type = ComputeSmallStrain
    type = ComputeFiniteStrain
    # type = ComputeFiniteStrain
    # ComputeSmallStrain,ComputeSmallStrain\ComputeFiniteStrain,ComputeSmallStrain\ComputeIncrementalSmallStrain
    block = 0
    displacements = 'disp_x disp_y'
    # outputs = exodus
    # output:elastic_strain11,12,22
  [../]
  [./stress]
    # type = ComputeLinearElasticStress
    type = ComputeFiniteStrainElasticStress
    # ComputeLinearElasticStress computes the stress following linear elasticity theory (small strains)
    block = 0
    # outputs = exodus
    # output:elastic_strain,mechanical_strain,total_strain
    # stress,jocabian_mult
  [../]
[]

[UserObjects]
  [./euler_angle_file]
    type = EulerAngleFileReader
    file_name = test.tex
  [../]
  [./grain_tracker]
    type = GrainTrackerElasticity
    # Manage a list of elasticity tensors for the grains
    # 从自定义对象模块输入初始欧拉角，之后旋转弹性张量并赋予给每个晶粒
    connecting_threshold = 0.05
    compute_var_to_feature_map = true
    flood_entity_type = elemental
    execute_on = 'initial timestep_begin'

    euler_angle_provider = euler_angle_file
    # <--UserObjects/euler_angle_file
    fill_method = symmetric9
    C_ijkl = '1.27e5 0.708e5 0.708e5 1.27e5 0.708e5 1.27e5 0.7355e5 0.7355e5 0.7355e5'
    # output:C_ijkl rotationed for every grain

    # outputs = none
    # outputs = exodus # do not output anything
  [../]
[]

[UserObjects]
  [./slip_rate_gss]
    type = CrystalPlasticitySlipRateGSS
    variable_size = 12
    slip_sys_file_name = input_slip_sys.txt
    num_slip_sys_flowrate_props = 2
    flowprops = '1 4 0.001 0.1 5 8 0.001 0.1 9 12 0.001 0.1'
    uo_state_var_name = state_var_gss
  [../]
  [./slip_resistance_gss]
    type = CrystalPlasticitySlipResistanceGSS
    variable_size = 12
    uo_state_var_name = state_var_gss
  [../]
  [./state_var_gss]
    type = CrystalPlasticityStateVariable
    variable_size = 12
    groups = '0 4 8 12'
    group_values = '60.8 60.8 60.8'
    uo_state_var_evol_rate_comp_name = state_var_evol_rate_comp_gss
    scale_factor = 1.0
  [../]
  [./state_var_evol_rate_comp_gss]
    type = CrystalPlasticityStateVarRateComponentGSS
    variable_size = 12
    hprops = '1.0 541.5 109.8 2.5'
    uo_slip_rate_name = slip_rate_gss
    uo_state_var_name = state_var_gss
  [../]
[]

[Postprocessors]
  [./dt]
    type = TimestepSize
  [../]
  [./gr0_area]
    type = ElementIntegralVariablePostprocessor
    variable = gr0
  [../]
  [./run_time]
    type = PerfGraphData
    section_name = "Root"
    data_type = total
  [../]
[]

[Preconditioning]
  [./SMP]
   type = SMP
   coupled_groups = 'gr0,gr1 disp_x,disp_y'
  [../]
[]

[Executioner]
  type = Transient

  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart -pc_hypre_boomeramg_strong_threshold'
  petsc_options_value = 'hypre boomeramg 31 0.7'

  l_max_its = 30
  l_tol = 1e-4
  nl_max_its = 30
  nl_rel_tol = 1e-9

  start_time = 0.0
  num_steps = 3
  dt = 0.2

  [./Adaptivity]
   initial_adaptivity = 2
    refine_fraction = 0.7
    coarsen_fraction = 0.1
    max_h_level = 2
  [../]
[]

[Outputs]
  execute_on = 'timestep_end'
  exodus = true
[]

