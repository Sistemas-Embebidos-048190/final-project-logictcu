/*
 * File: TCM_Final.c
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

#include "TCM_Final.h"
#include "TCM.h"
#include "TCM_Final_private.h"

/* Block signals (default storage) */
B_TCM_Final_T TCM_Final_B;

/* Block states (default storage) */
DW_TCM_Final_T TCM_Final_DW;

/* External inputs (root inport signals with default storage) */
ExtU_TCM_Final_T TCM_Final_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TCM_Final_T TCM_Final_Y;

/* Real-time model */
static RT_MODEL_TCM_Final_T TCM_Final_M_;
RT_MODEL_TCM_Final_T *const TCM_Final_M = &TCM_Final_M_;
uint16_T look2_iu8lu32n16tu16_binlcse(uint8_T u0, uint8_T u1, const uint8_T bp0[],
  const uint8_T bp1[], const uint16_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  uint32_T bpIndices[2];
  uint32_T fractions[2];
  uint32_T bpIdx;
  uint32_T frac;
  uint32_T iLeft;
  uint16_T y;
  uint16_T yL_0d0;
  uint16_T yL_1d;
  uint16_T yR_0d0;
  uint8_T bpLeftVar;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    frac = maxIndex[0U];
    while (frac - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (frac + iLeft) >> 1U;
    }

    bpLeftVar = bp0[iLeft];
    frac = (((uint32_T)u0 - bpLeftVar) << 16) / ((uint32_T)bp0[iLeft + 1U] -
      bpLeftVar);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 65536U;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    frac = maxIndex[1U];
    while (frac - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (frac + iLeft) >> 1U;
    }

    bpLeftVar = bp1[iLeft];
    frac = (((uint32_T)u1 - bpLeftVar) << 16) / ((uint32_T)bp1[iLeft + 1U] -
      bpLeftVar);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 65536U;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yR_0d0 = table[bpIdx + 1U];
  yL_0d0 = table[bpIdx];
  if (yR_0d0 >= yL_0d0) {
    yL_1d = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)yR_0d0 -
      yL_0d0) * fractions[0U]) >> 16) + yL_0d0);
  } else {
    yL_1d = (uint16_T)((uint32_T)yL_0d0 - (uint16_T)(((uint16_T)((uint32_T)
      yL_0d0 - yR_0d0) * fractions[0U]) >> 16));
  }

  bpIdx += stride;
  yR_0d0 = table[bpIdx + 1U];
  yL_0d0 = table[bpIdx];
  if (yR_0d0 >= yL_0d0) {
    yR_0d0 = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)yR_0d0 -
      yL_0d0) * fractions[0U]) >> 16) + yL_0d0);
  } else {
    yR_0d0 = (uint16_T)((uint32_T)yL_0d0 - (uint16_T)(((uint16_T)((uint32_T)
      yL_0d0 - yR_0d0) * fractions[0U]) >> 16));
  }

  if (yR_0d0 >= yL_1d) {
    y = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)yR_0d0 - yL_1d) *
      frac) >> 16) + yL_1d);
  } else {
    y = (uint16_T)((uint32_T)yL_1d - (uint16_T)(((uint16_T)((uint32_T)yL_1d -
      yR_0d0) * frac) >> 16));
  }

  return y;
}

real_T look2_is8bdtd_binlcpw(int8_T u0, int8_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 < bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = ((real_T)u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 1.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 < bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = ((real_T)u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

real_T look2_is16bdtd_binlcpw(int16_T u0, int16_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 < bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = ((real_T)u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 1.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 < bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = ((real_T)u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

real_T look2_binlcpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 1.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

int16_T look2_is16bu8s16lu32n1_I4aWljRd(int16_T u0, int16_T u1, const uint8_T
  bp0[], const int16_T bp1[], const int16_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  uint32_T bpIndices[2];
  uint32_T fractions[2];
  uint32_T bpIdx;
  uint32_T frac;
  uint32_T iLeft;
  int16_T bpLeftVar;
  int16_T yL_0d1;

  /* Column-major Lookup 2-D
     Canonical function name: look2_is16bu8s16lu32n16Ds32ds32_binlcs
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  bpLeftVar = u0;
  if (u0 < 0) {
    bpLeftVar = 0;
  } else if (u0 > 255) {
    bpLeftVar = 255;
  }

  if (u0 < bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if ((uint8_T)bpLeftVar < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    frac = maxIndex[0U];
    while (frac - iLeft > 1U) {
      if ((uint8_T)bpLeftVar < bp0[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (frac + iLeft) >> 1U;
    }

    frac = div_nzp_repeat_u32((uint32_T)u0 - bp0[iLeft], (uint32_T)bp0[iLeft +
      1U] - bp0[iLeft], 16U);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 65536U;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    frac = maxIndex[1U];
    while (frac - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (frac + iLeft) >> 1U;
    }

    bpLeftVar = bp1[iLeft];
    frac = ((uint32_T)(u1 - bpLeftVar) << 16) / (uint32_T)(bp1[iLeft + 1U] -
      bpLeftVar);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 65536U;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  bpLeftVar = table[bpIdx];
  bpLeftVar += (int16_T)(((table[bpIdx + 1U] - bpLeftVar) * (int32_T)fractions
    [0U]) >> 16);
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (int16_T)((int16_T)((((int16_T)((int16_T)(((table[bpIdx + 1U] - yL_0d1)
    * (int32_T)fractions[0U]) >> 16) + yL_0d1) - bpLeftVar) * (int32_T)frac) >>
    16) + bpLeftVar);
}

int16_T look2_is16bdlu32n16Ds3_dIbdfcxG(int16_T u0, int16_T u1, const real_T
  bp0[], const real_T bp1[], const int16_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  uint32_T bpIndices[2];
  uint32_T fractions[2];
  uint32_T bpIdx;
  uint32_T frac;
  uint32_T iLeft;
  int16_T yL_0d0;
  int16_T yL_0d1;

  /* Column-major Lookup 2-D
     Canonical function name: look2_is16bdlu32n16Ds32ds32_binlcs
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 < bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    frac = maxIndex[0U];
    while (frac - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (frac + iLeft) >> 1U;
    }

    frac = (uint32_T)(((real_T)u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft])
                      * 65536.0);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 65536U;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u1 < bp1[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    frac = maxIndex[1U];
    while (frac - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (frac + iLeft) >> 1U;
    }

    frac = (uint32_T)(((real_T)u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft])
                      * 65536.0);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 65536U;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (int16_T)(((table[bpIdx + 1U] - yL_0d0) * (int32_T)fractions[0U]) >>
                      16);
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (int16_T)((int16_T)((((int16_T)((int16_T)(((table[bpIdx + 1U] - yL_0d1)
    * (int32_T)fractions[0U]) >> 16) + yL_0d1) - yL_0d0) * (int32_T)frac) >> 16)
                   + yL_0d0);
}

uint16_T look2_iu16lu32n16_binlcse(uint16_T u0, uint16_T u1, const uint16_T bp0[],
  const uint16_T bp1[], const uint16_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  uint32_T bpIndices[2];
  uint32_T fractions[2];
  uint32_T bpIdx;
  uint32_T frac;
  uint32_T iLeft;
  uint16_T bpLeftVar;
  uint16_T y;
  uint16_T yL_0d0;
  uint16_T yL_1d;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    frac = maxIndex[0U];
    while (frac - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (frac + iLeft) >> 1U;
    }

    bpLeftVar = bp0[iLeft];
    frac = (((uint32_T)u0 - bpLeftVar) << 16) / ((uint32_T)bp0[iLeft + 1U] -
      bpLeftVar);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 65536U;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    frac = maxIndex[1U];
    while (frac - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        frac = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (frac + iLeft) >> 1U;
    }

    bpLeftVar = bp1[iLeft];
    frac = (((uint32_T)u1 - bpLeftVar) << 16) / ((uint32_T)bp1[iLeft + 1U] -
      bpLeftVar);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 65536U;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  bpLeftVar = table[bpIdx + 1U];
  yL_0d0 = table[bpIdx];
  if (bpLeftVar >= yL_0d0) {
    yL_1d = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)bpLeftVar -
      yL_0d0) * fractions[0U]) >> 16) + yL_0d0);
  } else {
    yL_1d = (uint16_T)((uint32_T)yL_0d0 - (uint16_T)(((uint16_T)((uint32_T)
      yL_0d0 - bpLeftVar) * fractions[0U]) >> 16));
  }

  bpIdx += stride;
  bpLeftVar = table[bpIdx + 1U];
  yL_0d0 = table[bpIdx];
  if (bpLeftVar >= yL_0d0) {
    bpLeftVar = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)bpLeftVar
      - yL_0d0) * fractions[0U]) >> 16) + yL_0d0);
  } else {
    bpLeftVar = (uint16_T)((uint32_T)yL_0d0 - (uint16_T)(((uint16_T)((uint32_T)
      yL_0d0 - bpLeftVar) * fractions[0U]) >> 16));
  }

  if (bpLeftVar >= yL_1d) {
    y = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)bpLeftVar - yL_1d)
      * frac) >> 16) + yL_1d);
  } else {
    y = (uint16_T)((uint32_T)yL_1d - (uint16_T)(((uint16_T)((uint32_T)yL_1d -
      bpLeftVar) * frac) >> 16));
  }

  return y;
}

uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator, uint32_T
  nRepeatSub)
{
  uint32_T iRepeatSub;
  uint32_T localNumerator;
  uint32_T quotient;
  quotient = numerator / denominator;
  localNumerator = numerator % denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    boolean_T numeratorExtraBit;
    numeratorExtraBit = (localNumerator >= 2147483648U);
    localNumerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (localNumerator >= denominator)) {
      quotient++;
      localNumerator -= denominator;
    }
  }

  return quotient;
}

/* Model step function */
void TCM_Final_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/TCM' */

  /* Inport: '<Root>/Brake_Pedal_Switch' incorporates:
   *  Inport: '<Root>/Driver_Mode_Selection'
   *  Inport: '<Root>/Engine_RPM'
   *  Inport: '<Root>/Engine_Torque_Actual'
   *  Inport: '<Root>/Gear_Lever_Position'
   *  Inport: '<Root>/Output_Speed_Sensor'
   *  Inport: '<Root>/Throttle_Position_Sensor'
   *  Inport: '<Root>/Transmission_Fluid_Temp'
   *  Inport: '<Root>/Turbine_Speed_Sensor'
   *  Inport: '<Root>/Vehicle_Speed_Reference'
   *  Outport: '<Root>/Current_Gear'
   *  Outport: '<Root>/Line_Pressure_Control_Solenoid'
   *  Outport: '<Root>/Shift_Solenoid_A'
   *  Outport: '<Root>/Shift_Solenoid_B'
   *  Outport: '<Root>/Shift_Solenoid_C'
   *  Outport: '<Root>/Shift_Solenoid_D'
   *  Outport: '<Root>/Shift_Solenoid_E'
   *  Outport: '<Root>/TCC_Control_Solenoid'
   */
  TCM_Final_TCM(TCM_Final_U.Brake_Pedal_Switch, TCM_Final_U.Gear_Lever_Position,
                TCM_Final_U.Vehicle_Speed_Reference,
                TCM_Final_U.Driver_Mode_Selection, TCM_Final_U.Engine_RPM,
                TCM_Final_U.Throttle_Position_Sensor,
                TCM_Final_U.Transmission_Fluid_Temp,
                TCM_Final_U.Output_Speed_Sensor,
                TCM_Final_U.Engine_Torque_Actual,
                TCM_Final_U.Turbine_Speed_Sensor, &TCM_Final_Y.Current_Gear,
                &TCM_Final_Y.Shift_Solenoid_A, &TCM_Final_Y.Shift_Solenoid_B,
                &TCM_Final_Y.Shift_Solenoid_C, &TCM_Final_Y.Shift_Solenoid_D,
                &TCM_Final_Y.Shift_Solenoid_E, &TCM_Final_Y.TCC_Control_Solenoid,
                &TCM_Final_Y.Line_Pressure_Control_Solenoid, &TCM_Final_B.TCM,
                &TCM_Final_DW.TCM);

  /* End of Outputs for SubSystem: '<Root>/TCM' */
}

/* Model initialize function */
void TCM_Final_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/TCM' */

  /* SystemInitialize for Outport: '<Root>/Current_Gear' incorporates:
   *  Outport: '<Root>/Line_Pressure_Control_Solenoid'
   *  Outport: '<Root>/Shift_Solenoid_A'
   *  Outport: '<Root>/Shift_Solenoid_B'
   *  Outport: '<Root>/Shift_Solenoid_C'
   *  Outport: '<Root>/Shift_Solenoid_D'
   *  Outport: '<Root>/Shift_Solenoid_E'
   *  Outport: '<Root>/TCC_Control_Solenoid'
   */
  TCM_Final_TCM_Init(&TCM_Final_Y.Current_Gear, &TCM_Final_Y.Shift_Solenoid_A,
                     &TCM_Final_Y.Shift_Solenoid_B,
                     &TCM_Final_Y.Shift_Solenoid_C,
                     &TCM_Final_Y.Shift_Solenoid_D,
                     &TCM_Final_Y.Shift_Solenoid_E,
                     &TCM_Final_Y.TCC_Control_Solenoid,
                     &TCM_Final_Y.Line_Pressure_Control_Solenoid);

  /* End of SystemInitialize for SubSystem: '<Root>/TCM' */
}

/* Model terminate function */
void TCM_Final_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
