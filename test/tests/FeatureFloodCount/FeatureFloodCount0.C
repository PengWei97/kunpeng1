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