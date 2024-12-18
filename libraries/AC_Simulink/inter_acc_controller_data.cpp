//
// File: inter_acc_controller_data.cpp
//
// Code generated for Simulink model 'inter_acc_controller'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Thu Dec 12 21:26:49 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "inter_acc_controller.h"

// Block parameters (default storage)
inter_acc_controller::P_inter_acc_controller_T inter_acc_controller::
  inter_acc_controller_P{
  // Expression: -9.81
  //  Referenced by: '<Root>/g_const'

  -9.81,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<Root>/Saturation'

  40.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<Root>/Saturation'

  -40.0F,

  // Computed Parameter: Kp_Az_Gain
  //  Referenced by: '<Root>/Kp_Az'

  -0.02F,

  // Computed Parameter: Ki_pd_tableData
  //  Referenced by: '<S3>/Ki_pd'

  { 0.0F, 0.0F, 1.1F, 0.45F, 0.35F, 0.2F, 0.1F, 0.08F, 0.06F, 0.05F, 0.03F },

  // Computed Parameter: Ki_pd_bp01Data
  //  Referenced by: '<S3>/Ki_pd'

  { 25.0F, 50.0F, 100.0F, 150.0F, 160.0F, 170.0F, 200.0F, 250.0F, 300.0F, 400.0F,
    450.0F },

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S3>/Integrator'

  0.01F,

  // Computed Parameter: Integrator_IC
  //  Referenced by: '<S3>/Integrator'

  0.0F,

  // Computed Parameter: Integrator_UpperSat
  //  Referenced by: '<S3>/Integrator'

  0.0872664601F,

  // Computed Parameter: Integrator_LowerSat
  //  Referenced by: '<S3>/Integrator'

  -0.0872664601F,

  // Computed Parameter: Kp_pd_tableData
  //  Referenced by: '<S3>/Kp_pd'

  { 0.75F, 1.2F, 0.3F, 0.15F, 0.15F, 0.06F, 0.015F, 0.015F, 0.015F, 0.015F,
    0.015F },

  // Computed Parameter: Kp_pd_bp01Data
  //  Referenced by: '<S3>/Kp_pd'

  { 25.0F, 50.0F, 100.0F, 160.0F, 170.0F, 200.0F, 250.0F, 275.0F, 290.0F, 350.0F,
    450.0F },

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S3>/Gain'

  -1.0F,

  // Computed Parameter: Integrator_gainval_d
  //  Referenced by: '<S4>/Integrator'

  0.01F,

  // Computed Parameter: Integrator_IC_n
  //  Referenced by: '<S4>/Integrator'

  0.0F,

  // Computed Parameter: Kp_tableData
  //  Referenced by: '<S4>/Kp'

  { 0.5F, 0.8F, 0.2F, 0.1F, 0.1F, 0.035F, 0.025F, 0.015F, 0.0125F, 0.0115F,
    0.0105F },

  // Computed Parameter: Kp_bp01Data
  //  Referenced by: '<S4>/Kp'

  { 25.0F, 50.0F, 100.0F, 160.0F, 170.0F, 200.0F, 250.0F, 275.0F, 290.0F, 350.0F,
    450.0F },

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<Root>/Saturation1'

  40.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<Root>/Saturation1'

  -40.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<Root>/Gain3'

  0.4F,

  // Computed Parameter: Kd_Ay_Gain
  //  Referenced by: '<Root>/Kd_Ay'

  0.001F,

  // Computed Parameter: Gain5_Gain
  //  Referenced by: '<Root>/Gain5'

  1.0F,

  // Computed Parameter: DiscreteTransferFcn_NumCoef
  //  Referenced by: '<S1>/Discrete Transfer Fcn'

  { 200.0F, -200.0F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef
  //  Referenced by: '<S1>/Discrete Transfer Fcn'

  { 1.0F, 1.0F },

  // Computed Parameter: DiscreteTransferFcn_InitialStat
  //  Referenced by: '<S1>/Discrete Transfer Fcn'

  0.0F,

  // Computed Parameter: Kp_Ay_Gain
  //  Referenced by: '<Root>/Kp_Ay'

  0.010737F,

  // Computed Parameter: Ki_tableData
  //  Referenced by: '<S4>/Ki'

  { 0.0F, 0.0F, 1.1F, 0.65F, 0.55F, 0.4F, 0.2F, 0.1F, 0.1F, 0.1F, 0.1F },

  // Computed Parameter: Ki_bp01Data
  //  Referenced by: '<S4>/Ki'

  { 25.0F, 50.0F, 100.0F, 150.0F, 160.0F, 170.0F, 200.0F, 250.0F, 300.0F, 400.0F,
    450.0F }
};

//
// File trailer for generated code.
//
// [EOF]
//
