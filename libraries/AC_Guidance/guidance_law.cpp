//
// File: guidance_law.cpp
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
#include "rtwtypes.h"
#include "guidance_law_private.h"
#include <cmath>
#include "rt_defines.h"

extern "C"
{

#include "rt_nonfinite.h"

}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaNF);
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real32_T>(tmp), static_cast<real32_T>(tmp_0));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

// Model step function
void guidance_law::step(real32_T arg_POS_M[3], real32_T arg_POS_T[3], real_T
  *arg_Az_cmd, real_T *arg_Ay_cmd)
{
  real32_T rtb_Diff_d;
  real32_T rtb_TSamp;
  real32_T rtb_TSamp_h;
  real32_T rtb_TSamp_p;
  real32_T rtb_ytym;

  // Sum: '<S2>/zt-zm' incorporates:
  //   Gain: '<S2>/Gain1'
  //   Inport: '<Root>/POS_M'
  //   Inport: '<Root>/POS_T'

  rtb_Diff_d = arg_POS_T[2] - guidance_law_P.Gain1_Gain * arg_POS_M[2];

  // Sum: '<S2>/xt-xm' incorporates:
  //   Inport: '<Root>/POS_M'
  //   Inport: '<Root>/POS_T'
  //   Sum: '<S1>/xt-xm'

  rtb_TSamp_h = arg_POS_T[0] - arg_POS_M[0];

  // SampleTimeMath: '<S5>/TSamp' incorporates:
  //   Sum: '<S2>/xt-xm'
  //   Trigonometry: '<S2>/LOS'
  //
  //  About '<S5>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp = rt_atan2f_snf(rtb_Diff_d, rtb_TSamp_h) * guidance_law_P.TSamp_WtEt;

  // Math: '<S2>/dx^2' incorporates:
  //   Math: '<S1>/dx^2'
  //   Sum: '<S2>/xt-xm'

  rtb_TSamp_p = rtb_TSamp_h * rtb_TSamp_h;

  // SampleTimeMath: '<S6>/TSamp' incorporates:
  //   Math: '<S2>/dx^2'
  //   Math: '<S2>/dz^2'
  //   Sqrt: '<S2>/RANGE'
  //   Sum: '<S2>/sum'
  //
  //  About '<S6>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_Diff_d = std::sqrt(rtb_Diff_d * rtb_Diff_d + rtb_TSamp_p) *
    guidance_law_P.TSamp_WtEt_m;

  // Outport: '<Root>/Az_cmd' incorporates:
  //   Constant: '<S2>/N' (PN const)'
  //   Gain: '<S2>/Gain'
  //   Product: '<S2>/N*d(LOS)//dt'
  //   Product: '<S2>/Product'
  //   Sum: '<S5>/Diff'
  //   Sum: '<S6>/Diff'
  //   UnitDelay: '<S5>/UD'
  //   UnitDelay: '<S6>/UD'
  //
  //  Block description for '<S5>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S6>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S5>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S6>/UD':
  //
  //   Store in Global RAM

  *arg_Az_cmd = (rtb_TSamp - guidance_law_DW.UD_DSTATE) *
    guidance_law_P.NPNconst_Value * ((rtb_Diff_d - guidance_law_DW.UD_DSTATE_n) *
    guidance_law_P.Gain_Gain);

  // Sum: '<S1>/yt-ym' incorporates:
  //   Inport: '<Root>/POS_M'
  //   Inport: '<Root>/POS_T'

  rtb_ytym = arg_POS_T[1] - arg_POS_M[1];

  // SampleTimeMath: '<S3>/TSamp' incorporates:
  //   Trigonometry: '<S1>/LOS'
  //
  //  About '<S3>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp_h = rt_atan2f_snf(rtb_TSamp_h, rtb_ytym) *
    guidance_law_P.TSamp_WtEt_l;

  // SampleTimeMath: '<S4>/TSamp' incorporates:
  //   Math: '<S1>/dy^2'
  //   Sqrt: '<S1>/Cross-range'
  //   Sum: '<S1>/sum'
  //
  //  About '<S4>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp_p = std::sqrt(rtb_ytym * rtb_ytym + rtb_TSamp_p) *
    guidance_law_P.TSamp_WtEt_h;

  // Outport: '<Root>/Ay_cmd' incorporates:
  //   Constant: '<S1>/N''
  //   Gain: '<S1>/Gain'
  //   Product: '<S1>/N*d(LOS)//dt'
  //   Product: '<S1>/Product'
  //   Sum: '<S3>/Diff'
  //   Sum: '<S4>/Diff'
  //   UnitDelay: '<S3>/UD'
  //   UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S3>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S4>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  *arg_Ay_cmd = (rtb_TSamp_h - guidance_law_DW.UD_DSTATE_b) *
    guidance_law_P.N_Value * ((rtb_TSamp_p - guidance_law_DW.UD_DSTATE_bn) *
    guidance_law_P.Gain_Gain_c);

  // Update for UnitDelay: '<S5>/UD'
  //
  //  Block description for '<S5>/UD':
  //
  //   Store in Global RAM

  guidance_law_DW.UD_DSTATE = rtb_TSamp;

  // Update for UnitDelay: '<S6>/UD'
  //
  //  Block description for '<S6>/UD':
  //
  //   Store in Global RAM

  guidance_law_DW.UD_DSTATE_n = rtb_Diff_d;

  // Update for UnitDelay: '<S3>/UD'
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  guidance_law_DW.UD_DSTATE_b = rtb_TSamp_h;

  // Update for UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  guidance_law_DW.UD_DSTATE_bn = rtb_TSamp_p;
}

// Model initialize function
void guidance_law::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // InitializeConditions for UnitDelay: '<S5>/UD'
  //
  //  Block description for '<S5>/UD':
  //
  //   Store in Global RAM

  guidance_law_DW.UD_DSTATE = guidance_law_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for UnitDelay: '<S6>/UD'
  //
  //  Block description for '<S6>/UD':
  //
  //   Store in Global RAM

  guidance_law_DW.UD_DSTATE_n = guidance_law_P.DiscreteDerivative1_ICPrevScale;

  // InitializeConditions for UnitDelay: '<S3>/UD'
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  guidance_law_DW.UD_DSTATE_b = guidance_law_P.DiscreteDerivative_ICPrevScal_g;

  // InitializeConditions for UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  guidance_law_DW.UD_DSTATE_bn = guidance_law_P.DiscreteDerivative1_ICPrevSca_e;
}

// Model terminate function
void guidance_law::terminate()
{
  // (no terminate code required)
}

// Constructor
guidance_law::guidance_law() :
  guidance_law_DW(),
  guidance_law_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
guidance_law::~guidance_law() = default;

// Real-Time Model get method
guidance_law::RT_MODEL_guidance_law_T * guidance_law::getRTM()
{
  return (&guidance_law_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
