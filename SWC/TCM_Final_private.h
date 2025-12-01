/*
 * File: TCM_Final_private.h
 *
 * Code generated for Simulink model 'TCM_Final'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Nov 28 02:40:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef TCM_Final_private_h_
#define TCM_Final_private_h_
#include "rtwtypes.h"
#include "TCM_Final_types.h"
#include "TCM_Final.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern uint16_T look2_iu8lu32n16tu16_binlcse(uint8_T u0, uint8_T u1, const
  uint8_T bp0[], const uint8_T bp1[], const uint16_T table[], const uint32_T
  maxIndex[], uint32_T stride);
extern real_T look2_is8bdtd_binlcpw(int8_T u0, int8_T u1, const real_T bp0[],
  const real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T
  stride);
extern real_T look2_is16bdtd_binlcpw(int16_T u0, int16_T u1, const real_T bp0[],
  const real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T
  stride);
extern real_T look2_binlcpw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
extern int16_T look2_is16bu8s16lu32n1_I4aWljRd(int16_T u0, int16_T u1, const
  uint8_T bp0[], const int16_T bp1[], const int16_T table[], const uint32_T
  maxIndex[], uint32_T stride);
extern int16_T look2_is16bdlu32n16Ds3_dIbdfcxG(int16_T u0, int16_T u1, const
  real_T bp0[], const real_T bp1[], const int16_T table[], const uint32_T
  maxIndex[], uint32_T stride);
extern uint16_T look2_iu16lu32n16_binlcse(uint16_T u0, uint16_T u1, const
  uint16_T bp0[], const uint16_T bp1[], const uint16_T table[], const uint32_T
  maxIndex[], uint32_T stride);
extern uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator,
  uint32_T nRepeatSub);

#endif                                 /* TCM_Final_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
