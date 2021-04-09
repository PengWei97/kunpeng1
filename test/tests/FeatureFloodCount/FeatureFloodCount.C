// Example
{
  ./modules/phase_field/examples/grain_growth/grain_growth_2D_random.i:    type = FeatureFloodCount
  Postprocessors
  [./num_grains]
    type = FeatureFloodCount
    variable = bnds
    threshold = 0.7
  [../]

  feature_volume_vpp_test.i
  [./flood_count]
    type = FeatureFloodCount
    variable = c
    # Must be turned out to build data structures necessary for FeatureVolumeVPP
    compute_var_to_feature_map = true
    threshold = 0.5
    outputs = none
    execute_on = INITIAL
  [../]

  {
    AuxKernels
  [./unique_grains] // 唯一的晶粒着色图
    type = FeatureFloodCountAux
    variable = unique_grains
    flood_counter = grain_tracker
    field_display = UNIQUE_REGION // unique_region
    execute_on = 'initial timestep_end'
  [../]
  [./var_indices] // 序参数索引
    type = FeatureFloodCountAux
    variable = var_indices
    flood_counter = grain_tracker
    field_display = VARIABLE_COLORING // variable_coloring
    execute_on = 'initial timestep_end'
  [../]
  [./ghosted_entities] // ??
    type = FeatureFloodCountAux
    variable = ghost_regions
    flood_counter = grain_tracker
    field_display = GHOSTED_ENTITIES // ghosted_
    execute_on = 'initial timestep_end'
  [../]
  [./halos] // 光晕渲染
    type = FeatureFloodCountAux
    variable = halos
    flood_counter = grain_tracker
    field_display = HALOS
    execute_on = 'initial timestep_end'
  [../]
  }


}

// combined
{
./modules/combined/examples/phase_field-mechanics/grain_texture.i:    type = FeatureFloodCountAux
./modules/combined/examples/phase_field-mechanics/grain_texture.i:    type = FeatureFloodCountAux
./modules/combined/examples/phase_field-mechanics/hex_grain_growth_2D_eldrforce.i:    type = FeatureFloodCountAux
./modules/combined/examples/phase_field-mechanics/hex_grain_growth_2D_eldrforce.i:    type = FeatureFloodCountAux
./modules/combined/examples/phase_field-mechanics/poly_grain_growth_2D_eldrforce.i:    type = FeatureFloodCountAux
./modules/combined/examples/phase_field-mechanics/poly_grain_growth_2D_eldrforce.i:    type = FeatureFloodCountAux
./modules/combined/examples/phase_field-mechanics/poly_grain_growth_2D_eldrforce.i:    type = FeatureFloodCount
./modules/combined/examples/phase_field-mechanics/EBSD_reconstruction_grain_growth_mech.i:    type = FeatureFloodCountAux
./modules/combined/examples/phase_field-mechanics/EBSD_reconstruction_grain_growth_mech.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/feature_volume_fraction/feature_volume_fraction.i:    type = FeatureFloodCount
./modules/combined/test/tests/feature_volume_fraction/Avrami.i:    type = FeatureFloodCount
./modules/combined/test/tests/grain_texture/random_grain_orientation.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/random_grain_orientation.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/random_grain_orientation.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/grain_texture_test_2.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/EulerAngleProvider2RGBAux_bicrystal.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/EulerAngleProvider2RGBAux_bicrystal.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/EulerAngleProvider2RGBAux_bicrystal.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/EulerAngle2RGBAction.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/EulerAngle2RGBAction.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/EulerAngle2RGBAction.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/grain_texture/grain_texture_test_1.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/ACGrGrElasticDrivingForce/bicrystal.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/ACGrGrElasticDrivingForce/bicrystal.i:    type = FeatureFloodCountAux
./modules/combined/test/tests/ACGrGrElasticDrivingForce/bicrystal.i:    type = FeatureFloodCountAux
}

{  
  ./modules/phase_field/tutorials/spinodal_decomposition/s5_energycurve.i:    type = FeatureFloodCount
  ./modules/phase_field/examples/rigidbodymotion/grain_motion_GT.i:    type = FeatureFloodCountAux
  ./modules/phase_field/examples/rigidbodymotion/grain_motion_GT.i:    type = FeatureFloodCountAux
  ./modules/phase_field/examples/rigidbodymotion/grain_motion_GT.i:    type = FeatureFloodCountAux
  ./modules/phase_field/examples/ebsd_reconstruction/IN100-111grn.i:    type = FeatureFloodCountAux
  ./modules/phase_field/examples/ebsd_reconstruction/IN100-111grn.i:    type = FeatureFloodCountAux
  ./modules/phase_field/examples/ebsd_reconstruction/IN100-111grn.i:    type = FeatureFloodCountAux
  ./modules/phase_field/examples/ebsd_reconstruction/IN100-111grn.i:    type = FeatureFloodCountAux
  ./modules/phase_field/examples/ebsd_reconstruction/IN100-111grn.i:    type = FeatureFloodCountAux
  ./modules/phase_field/examples/ebsd_reconstruction/IN100-111grn.i:    type = FeatureFloodCountAux
}

./modules/phase_field/examples/grain_growth/grain_growth_2D_random.i:    type = FeatureFloodCount
./modules/phase_field/examples/grain_growth/grain_growth_2D_graintracker.i:    type = FeatureFloodCountAux
./modules/phase_field/examples/grain_growth/grain_growth_3D.i:    type = FeatureFloodCountAux
./modules/phase_field/examples/grain_growth/3D_6000_gr.i:    type = FeatureFloodCountAux
./modules/phase_field/examples/grain_growth/3D_6000_gr.i:    type = FeatureFloodCountAux
./modules/phase_field/examples/grain_growth/3D_6000_gr.i:    type = FeatureFloodCountAux
./modules/phase_field/examples/grain_growth/3D_6000_gr.i:    type = FeatureFloodCountAux
// ./modules/phase_field/test/tests/initial_conditions/polycrystal_BndsCalcIC.i:    type = FeatureFloodCount
// ./modules/phase_field/test/tests/feature_volume_vpp_test/feature_volume_vpp_test.i:    type = FeatureFloodCount
// ./modules/phase_field/test/tests/feature_volume_vpp_test/boundary_area_3D.i:    type = FeatureFloodCount
// ./modules/phase_field/test/tests/feature_volume_vpp_test/percolation_test.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/feature_volume_vpp_test/boundary_area_2D.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/feature_volume_vpp_test/boundary_area_2D.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/feature_volume_vpp_test/boundary_area_3D_single.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/feature_volume_vpp_test/boundary_area_2D_single.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/feature_volume_vpp_test/boundary_area_2D_single.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/flood_counter_aux_test/flood_aux_elemental.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/flood_counter_aux_test/flood_aux_elemental.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/flood_counter_aux_test/flood_aux.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/flood_counter_aux_test/flood_aux.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/flood_counter_aux_test/flood_counter_boundary_restrictable.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/flood_counter_aux_test/flood_counter_boundary_restrictable.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/flood_counter_aux_test/simple.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/flood_counter_aux_test/simple.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/flood_counter_aux_test/simple.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/flood_counter_aux_test/nodal_flood_periodic_2var.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/flood_counter_aux_test/nodal_flood_periodic_2var.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/flood_counter_aux_test/nodal_flood_periodic_2var.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/boundary_intersecting_features/boundary_intersecting_features.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/boundary_intersecting_features/boundary_intersecting_features.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/boundary_intersecting_features/boundary_intersecting_features.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/rigidbodymotion/update_orientation.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/update_orientation.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/update_orientation.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/update_orientation_verify.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/update_orientation_verify.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/update_orientation_verify.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/grain_forcedensity.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/grain_forcedensity.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/grain_forcedensity.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/polycrystal_action.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/polycrystal_action.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/polycrystal_action.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/grain_motion_fauxGT.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/grain_motion_fauxGT.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/grain_motion_fauxGT.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/grain_motion2.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/rigidbodymotion/grain_motion2.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/reconstruction/2phase_reconstruction4.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/reconstruction/1phase_reconstruction.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/reconstruction/1phase_reconstruction.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/reconstruction/1phase_reconstruction.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/reconstruction/1phase_reconstruction.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/reconstruction/1phase_reconstruction.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/reconstruction/1phase_reconstruction.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/reconstruction/euler2rgb_no_grain_region.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/reconstruction/euler2rgb_no_grain_region.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/flood_counter_periodic_test/nodal_flood_periodic.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/MultiSmoothCircleIC/latticesmoothcircleIC_test.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/MultiSmoothCircleIC/multismoothcircleIC_normal_test.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/MultiSmoothCircleIC/test_problem.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/MultiSmoothCircleIC/test_problem.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/MultiSmoothCircleIC/test_problem.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/MultiSmoothCircleIC/test_problem.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/MultiSmoothCircleIC/latticesmoothcircleIC_normal_test.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/MultiSmoothCircleIC/multismoothcircleIC_test.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/MultiSmoothCircleIC/specifiedsmoothcircleIC_test.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_advanced_op.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/one_grain.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_volume_changing.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/distributed_poly_ic.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_halo_over_bc.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_nodal.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_nodal.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_remapping_test.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_ebsd.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_ebsd.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_ebsd.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_ebsd.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_ebsd.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_ebsd.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_test_elemental.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/grain_tracker_test_elemental.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/split_grain.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/split_grain.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/split_grain.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/grain_tracker_test/split_grain.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/feature_flood_test/parallel_feature_count.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/feature_flood_test/parallel_feature_count.i:    type = FeatureFloodCountAux
./modules/phase_field/test/tests/feature_flood_test/parallel_feature_count.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/grain_growth/voronoi_adaptivity_ghost.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/grain_growth/voronoi_adaptivity.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/grain_growth/voronoi_columnar_3D.i:    type = FeatureFloodCount
./modules/phase_field/test/tests/grain_growth/voronoi.i:    type = FeatureFloodCount
