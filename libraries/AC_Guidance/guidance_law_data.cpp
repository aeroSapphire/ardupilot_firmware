//
// File: guidance_law_data.cpp
//
// Code generated for Simulink model 'guidance_law'.
//
// Model version                  : 1.1
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Mon Dec 16 21:47:01 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "guidance_law.h"

// Block parameters (default storage)
guidance_law::P_guidance_law_T guidance_law::guidance_law_P{
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S5>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S6>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_g
  //  Referenced by: '<S3>/UD'

  0.0F,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_e
  //  Referenced by: '<S4>/UD'

  0.0F,

  // Expression: -5
  //  Referenced by: '<S2>/N' (PN const)'

  -5.0,

  // Expression: -3
  //  Referenced by: '<S1>/N''

  -3.0,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S2>/Gain1'

  -1.0F,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S5>/TSamp'

  400.0F,

  // Computed Parameter: TSamp_WtEt_m
  //  Referenced by: '<S6>/TSamp'

  400.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S2>/Gain'

  -1.0F,

  // Computed Parameter: TSamp_WtEt_l
  //  Referenced by: '<S3>/TSamp'

  400.0F,

  // Computed Parameter: TSamp_WtEt_h
  //  Referenced by: '<S4>/TSamp'

  400.0F,

  // Computed Parameter: Gain_Gain_c
  //  Referenced by: '<S1>/Gain'

  -1.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
