/*
 * File: TCM.c
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

#include "rtwtypes.h"
#include "TCM.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "TCM_Final.h"
#include "TCM_Final_private.h"

/* Named constants for Chart: '<S1>/Driver_Mode' */
#define TCM_Final_IN_Eco               ((uint8_T)1U)
#define TCM_Final_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define TCM_Final_IN_Normal            ((uint8_T)2U)
#define TCM_Final_IN_Sport             ((uint8_T)3U)

/* Named constants for Chart: '<S1>/Gear_Selection' */
#define TCM_Final_IN_Drive             ((uint8_T)1U)
#define TCM_Final_IN_FifthSpeed        ((uint8_T)1U)
#define TCM_Final_IN_FirstSpeed        ((uint8_T)2U)
#define TCM_Final_IN_FourthSpeed       ((uint8_T)3U)
#define TCM_Final_IN_Neutral           ((uint8_T)2U)
#define TCM_Final_IN_Parking           ((uint8_T)3U)
#define TCM_Final_IN_Reverse           ((uint8_T)4U)
#define TCM_Final_IN_SecondSpeed       ((uint8_T)4U)
#define TCM_Final_IN_SixthSpeed        ((uint8_T)5U)
#define TCM_Final_IN_ThirdSpeed        ((uint8_T)6U)

/* Named constants for Chart: '<S1>/TCC_Control' */
#define TCM_Final_IN_Release           ((uint8_T)1U)
#define TCM_Final_IN_SlipMode          ((uint8_T)2U)

/* Forward declaration for local functions */
static void TCM_Final_Drive(uint8_T rtu_Gear_Lever_Position, uint8_T
  *rty_Current_Gear, uint8_T *rty_Shift_Solenoid_A, uint8_T
  *rty_Shift_Solenoid_B, uint8_T *rty_Shift_Solenoid_C, uint8_T
  *rty_Shift_Solenoid_D, uint8_T *rty_Shift_Solenoid_E, B_TCM_TCM_Final_T
  *localB, DW_TCM_TCM_Final_T *localDW);
static void TCM_Final_enter_atomic_Parking(uint8_T *rty_Current_Gear, uint8_T
  *rty_Shift_Solenoid_A, uint8_T *rty_Shift_Solenoid_B, uint8_T
  *rty_Shift_Solenoid_C, uint8_T *rty_Shift_Solenoid_D, uint8_T
  *rty_Shift_Solenoid_E, DW_TCM_TCM_Final_T *localDW);

/* Function for Chart: '<S1>/Gear_Selection' */
static void TCM_Final_Drive(uint8_T rtu_Gear_Lever_Position, uint8_T
  *rty_Current_Gear, uint8_T *rty_Shift_Solenoid_A, uint8_T
  *rty_Shift_Solenoid_B, uint8_T *rty_Shift_Solenoid_C, uint8_T
  *rty_Shift_Solenoid_D, uint8_T *rty_Shift_Solenoid_E, B_TCM_TCM_Final_T
  *localB, DW_TCM_TCM_Final_T *localDW)
{
  /* Chart: '<S1>/Gear_Selection' */
  if (rtu_Gear_Lever_Position == 2) {
    localDW->is_Drive = TCM_Final_IN_NO_ACTIVE_CHILD;
    localDW->is_c3_Gear_Selection_Library = TCM_Final_IN_Neutral;
    *rty_Current_Gear = localDW->N;
  } else {
    switch (localDW->is_Drive) {
     case TCM_Final_IN_FifthSpeed:
      if ((localDW->temporalCounter_i1 >= 15) && (localB->DownShift == 1)) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_FourthSpeed;
        *rty_Current_Gear = localDW->Fourth;
      } else if ((localDW->temporalCounter_i1 >= 15) && (localB->UpShift == 1))
      {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_SixthSpeed;
        *rty_Current_Gear = localDW->Sixth;
      } else {
        *rty_Shift_Solenoid_A = 1U;
        *rty_Shift_Solenoid_B = 1U;
        *rty_Shift_Solenoid_C = 0U;
        *rty_Shift_Solenoid_D = 0U;
        *rty_Shift_Solenoid_E = 0U;
      }
      break;

     case TCM_Final_IN_FirstSpeed:
      if ((localDW->temporalCounter_i1 >= 15) && (((localB->UpShift == 1) &&
            (rtu_Gear_Lever_Position == 3)) || (rtu_Gear_Lever_Position == 5)))
      {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_SecondSpeed;
        *rty_Current_Gear = localDW->Second;
      } else {
        *rty_Shift_Solenoid_A = 0U;
        *rty_Shift_Solenoid_B = 0U;
        *rty_Shift_Solenoid_C = 1U;
        *rty_Shift_Solenoid_D = 1U;
        *rty_Shift_Solenoid_E = 0U;
      }
      break;

     case TCM_Final_IN_FourthSpeed:
      if ((localDW->temporalCounter_i1 >= 15) && (localB->DownShift == 1)) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_ThirdSpeed;
        *rty_Current_Gear = localDW->Third;
      } else if ((localDW->temporalCounter_i1 >= 15) && (localB->UpShift == 1))
      {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_FifthSpeed;
        *rty_Current_Gear = localDW->Fifth;
      } else {
        *rty_Shift_Solenoid_A = 0U;
        *rty_Shift_Solenoid_B = 1U;
        *rty_Shift_Solenoid_C = 1U;
        *rty_Shift_Solenoid_D = 0U;
        *rty_Shift_Solenoid_E = 0U;
      }
      break;

     case TCM_Final_IN_SecondSpeed:
      if ((localDW->temporalCounter_i1 >= 15) && (localB->DownShift == 1) &&
          ((rtu_Gear_Lever_Position == 3) || (rtu_Gear_Lever_Position == 4))) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_FirstSpeed;
        *rty_Current_Gear = localDW->First;
      } else if ((localDW->temporalCounter_i1 >= 15) && (localB->UpShift == 1) &&
                 (rtu_Gear_Lever_Position == 3)) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_ThirdSpeed;
        *rty_Current_Gear = localDW->Third;
      } else {
        *rty_Shift_Solenoid_A = 0U;
        *rty_Shift_Solenoid_B = 0U;
        *rty_Shift_Solenoid_C = 1U;
        *rty_Shift_Solenoid_D = 0U;
        *rty_Shift_Solenoid_E = 1U;
      }
      break;

     case TCM_Final_IN_SixthSpeed:
      if ((localDW->temporalCounter_i1 >= 15) && (localB->DownShift == 1)) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_FifthSpeed;
        *rty_Current_Gear = localDW->Fifth;
      } else {
        *rty_Shift_Solenoid_A = 0U;
        *rty_Shift_Solenoid_B = 1U;
        *rty_Shift_Solenoid_C = 0U;
        *rty_Shift_Solenoid_D = 0U;
        *rty_Shift_Solenoid_E = 1U;
      }
      break;

     default:
      /* case IN_ThirdSpeed: */
      if ((localDW->temporalCounter_i1 >= 15) && (localB->DownShift == 1)) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_SecondSpeed;
        *rty_Current_Gear = localDW->Second;
      } else if ((localDW->temporalCounter_i1 >= 15) && (localB->UpShift == 1))
      {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_FourthSpeed;
        *rty_Current_Gear = localDW->Fourth;
      } else {
        *rty_Shift_Solenoid_A = 1U;
        *rty_Shift_Solenoid_B = 0U;
        *rty_Shift_Solenoid_C = 1U;
        *rty_Shift_Solenoid_D = 0U;
        *rty_Shift_Solenoid_E = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Gear_Selection' */
}

/* Function for Chart: '<S1>/Gear_Selection' */
static void TCM_Final_enter_atomic_Parking(uint8_T *rty_Current_Gear, uint8_T
  *rty_Shift_Solenoid_A, uint8_T *rty_Shift_Solenoid_B, uint8_T
  *rty_Shift_Solenoid_C, uint8_T *rty_Shift_Solenoid_D, uint8_T
  *rty_Shift_Solenoid_E, DW_TCM_TCM_Final_T *localDW)
{
  localDW->R = 82U;
  localDW->N = 78U;
  localDW->First = 49U;
  localDW->Second = 50U;
  localDW->Third = 51U;
  localDW->Fourth = 52U;
  localDW->Fifth = 53U;
  localDW->Sixth = 54U;

  /* Chart: '<S1>/Gear_Selection' */
  *rty_Current_Gear = 80U;
  *rty_Shift_Solenoid_A = 0U;
  *rty_Shift_Solenoid_B = 0U;
  *rty_Shift_Solenoid_C = 0U;
  *rty_Shift_Solenoid_D = 0U;
  *rty_Shift_Solenoid_E = 0U;
}

/* System initialize for atomic system: '<Root>/TCM' */
void TCM_Final_TCM_Init(uint8_T *rty_Current_Gear, uint8_T *rty_Shift_Solenoid_A,
  uint8_T *rty_Shift_Solenoid_B, uint8_T *rty_Shift_Solenoid_C, uint8_T
  *rty_Shift_Solenoid_D, uint8_T *rty_Shift_Solenoid_E, uint8_T
  *rty_TCC_Control_Solenoid, uint8_T *rty_Line_Pressure_Control_Solen)
{
  /* SystemInitialize for Chart: '<S1>/Gear_Selection' */
  *rty_Current_Gear = 0U;
  *rty_Shift_Solenoid_A = 0U;
  *rty_Shift_Solenoid_B = 0U;
  *rty_Shift_Solenoid_C = 0U;
  *rty_Shift_Solenoid_D = 0U;
  *rty_Shift_Solenoid_E = 0U;

  /* SystemInitialize for Chart: '<S1>/Hydraulic_Pressure_Control' */
  *rty_Line_Pressure_Control_Solen = 0U;

  /* SystemInitialize for Chart: '<S1>/TCC_Control' */
  *rty_TCC_Control_Solenoid = 0U;
}

/* Output and update for atomic system: '<Root>/TCM' */
void TCM_Final_TCM(uint8_T rtu_Brake_Pedal_Switch, uint8_T
                   rtu_Gear_Lever_Position, uint8_T rtu_Vehicle_Speed_Reference,
                   uint8_T rtu_Driver_Mode_Selection, uint16_T rtu_Engine_RPM,
                   uint8_T rtu_Throttle_Position_Sensor, int8_T
                   rtu_Transmission_Fluid_Temp, uint16_T rtu_Output_Speed_Sensor,
                   int16_T rtu_Engine_Torque_Actual, uint16_T
                   rtu_Turbine_Speed_Sensor, uint8_T *rty_Current_Gear, uint8_T *
                   rty_Shift_Solenoid_A, uint8_T *rty_Shift_Solenoid_B, uint8_T *
                   rty_Shift_Solenoid_C, uint8_T *rty_Shift_Solenoid_D, uint8_T *
                   rty_Shift_Solenoid_E, uint8_T *rty_TCC_Control_Solenoid,
                   uint8_T *rty_Line_Pressure_Control_Solen, B_TCM_TCM_Final_T
                   *localB, DW_TCM_TCM_Final_T *localDW)
{
  real_T tmp;
  uint32_T qY;

  /* Chart: '<S1>/Driver_Mode' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   *  Lookup_n-D: '<S6>/Eco Mode Downshift'
   *  Lookup_n-D: '<S6>/Eco Mode Upshift'
   *  Lookup_n-D: '<S7>/Normal dowshift'
   *  Lookup_n-D: '<S7>/Normal upshift'
   *  Lookup_n-D: '<S8>/Sport Mode Downshift'
   *  Lookup_n-D: '<S8>/Sport Mode Upshift'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  RelationalOperator: '<S6>/Relational Operator1'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  RelationalOperator: '<S8>/Relational Operator1'
   */
  if (localDW->is_active_c3_Drive_Mode_Librery == 0) {
    localDW->is_active_c3_Drive_Mode_Librery = 1U;
    localDW->is_c3_Drive_Mode_Librery = TCM_Final_IN_Normal;
  } else {
    switch (localDW->is_c3_Drive_Mode_Librery) {
     case TCM_Final_IN_Eco:
      switch (rtu_Driver_Mode_Selection) {
       case 2U:
        localDW->is_c3_Drive_Mode_Librery = TCM_Final_IN_Normal;
        break;

       case 1U:
        localDW->is_c3_Drive_Mode_Librery = TCM_Final_IN_Sport;
        break;

       default:
        /* Outputs for Function Call SubSystem: '<S2>/EcoF' */
        localB->UpShift = (uint8_T)(rtu_Engine_RPM >=
          look2_iu8lu32n16tu16_binlcse(rtu_Vehicle_Speed_Reference,
          rtu_Throttle_Position_Sensor, TCM_Final_ConstP.pooled6,
          TCM_Final_ConstP.pooled7, TCM_Final_ConstP.EcoModeUpshift_tableData,
          TCM_Final_ConstP.pooled2, 13U));
        localB->DownShift = (uint8_T)(rtu_Engine_RPM <=
          look2_iu8lu32n16tu16_binlcse(rtu_Vehicle_Speed_Reference,
          rtu_Throttle_Position_Sensor, TCM_Final_ConstP.pooled6,
          TCM_Final_ConstP.pooled7, TCM_Final_ConstP.EcoModeDownshift_tableData,
          TCM_Final_ConstP.pooled2, 13U));

        /* End of Outputs for SubSystem: '<S2>/EcoF' */
        break;
      }
      break;

     case TCM_Final_IN_Normal:
      switch (rtu_Driver_Mode_Selection) {
       case 0U:
        localDW->is_c3_Drive_Mode_Librery = TCM_Final_IN_Eco;
        break;

       case 1U:
        localDW->is_c3_Drive_Mode_Librery = TCM_Final_IN_Sport;
        break;

       default:
        /* Outputs for Function Call SubSystem: '<S2>/NormalF' */
        localB->UpShift = (uint8_T)(rtu_Engine_RPM >=
          look2_iu8lu32n16tu16_binlcse(rtu_Vehicle_Speed_Reference,
          rtu_Throttle_Position_Sensor, TCM_Final_ConstP.pooled6,
          TCM_Final_ConstP.pooled7, TCM_Final_ConstP.Normalupshift_tableData,
          TCM_Final_ConstP.pooled2, 13U));
        localB->DownShift = (uint8_T)(rtu_Engine_RPM <=
          look2_iu8lu32n16tu16_binlcse(rtu_Vehicle_Speed_Reference,
          rtu_Throttle_Position_Sensor, TCM_Final_ConstP.pooled6,
          TCM_Final_ConstP.pooled7, TCM_Final_ConstP.Normaldowshift_tableData,
          TCM_Final_ConstP.pooled2, 13U));

        /* End of Outputs for SubSystem: '<S2>/NormalF' */
        break;
      }
      break;

     default:
      /* case IN_Sport: */
      switch (rtu_Driver_Mode_Selection) {
       case 2U:
        localDW->is_c3_Drive_Mode_Librery = TCM_Final_IN_Normal;
        break;

       case 0U:
        localDW->is_c3_Drive_Mode_Librery = TCM_Final_IN_Eco;
        break;

       default:
        /* Outputs for Function Call SubSystem: '<S2>/SportF' */
        localB->UpShift = (uint8_T)(rtu_Engine_RPM >=
          look2_iu8lu32n16tu16_binlcse(rtu_Vehicle_Speed_Reference,
          rtu_Throttle_Position_Sensor, TCM_Final_ConstP.pooled6,
          TCM_Final_ConstP.pooled7, TCM_Final_ConstP.SportModeUpshift_tableData,
          TCM_Final_ConstP.pooled2, 13U));
        localB->DownShift = (uint8_T)(rtu_Engine_RPM <=
          look2_iu8lu32n16tu16_binlcse(rtu_Vehicle_Speed_Reference,
          rtu_Throttle_Position_Sensor, TCM_Final_ConstP.pooled6,
          TCM_Final_ConstP.pooled7,
          TCM_Final_ConstP.SportModeDownshift_tableData,
          TCM_Final_ConstP.pooled2, 13U));

        /* End of Outputs for SubSystem: '<S2>/SportF' */
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Driver_Mode' */

  /* Chart: '<S1>/Gear_Selection' */
  if (localDW->temporalCounter_i1 < 15) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c3_Gear_Selection_Lib == 0) {
    localDW->is_active_c3_Gear_Selection_Lib = 1U;
    localDW->is_c3_Gear_Selection_Library = TCM_Final_IN_Parking;
    TCM_Final_enter_atomic_Parking(rty_Current_Gear, rty_Shift_Solenoid_A,
      rty_Shift_Solenoid_B, rty_Shift_Solenoid_C, rty_Shift_Solenoid_D,
      rty_Shift_Solenoid_E, localDW);
  } else {
    switch (localDW->is_c3_Gear_Selection_Library) {
     case TCM_Final_IN_Drive:
      TCM_Final_Drive(rtu_Gear_Lever_Position, rty_Current_Gear,
                      rty_Shift_Solenoid_A, rty_Shift_Solenoid_B,
                      rty_Shift_Solenoid_C, rty_Shift_Solenoid_D,
                      rty_Shift_Solenoid_E, localB, localDW);
      break;

     case TCM_Final_IN_Neutral:
      if ((rtu_Gear_Lever_Position == 1) && (rtu_Brake_Pedal_Switch == 1) &&
          (rtu_Vehicle_Speed_Reference == 0)) {
        localDW->is_c3_Gear_Selection_Library = TCM_Final_IN_Reverse;
        *rty_Current_Gear = localDW->R;
      } else if ((rtu_Gear_Lever_Position == 3) && (rtu_Brake_Pedal_Switch == 1)
                 && (rtu_Vehicle_Speed_Reference < 3)) {
        localDW->is_c3_Gear_Selection_Library = TCM_Final_IN_Drive;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Drive = TCM_Final_IN_FirstSpeed;
        *rty_Current_Gear = localDW->First;
      } else {
        *rty_Shift_Solenoid_A = 0U;
        *rty_Shift_Solenoid_B = 0U;
        *rty_Shift_Solenoid_C = 0U;
        *rty_Shift_Solenoid_D = 0U;
        *rty_Shift_Solenoid_E = 0U;
      }
      break;

     case TCM_Final_IN_Parking:
      if ((rtu_Gear_Lever_Position == 1) && (rtu_Brake_Pedal_Switch == 1) &&
          (rtu_Vehicle_Speed_Reference < 3)) {
        localDW->is_c3_Gear_Selection_Library = TCM_Final_IN_Reverse;
        *rty_Current_Gear = localDW->R;
      }
      break;

     default:
      /* case IN_Reverse: */
      if ((rtu_Gear_Lever_Position == 0) && (rtu_Brake_Pedal_Switch == 1) &&
          (rtu_Vehicle_Speed_Reference == 0)) {
        localDW->is_c3_Gear_Selection_Library = TCM_Final_IN_Parking;
        TCM_Final_enter_atomic_Parking(rty_Current_Gear, rty_Shift_Solenoid_A,
          rty_Shift_Solenoid_B, rty_Shift_Solenoid_C, rty_Shift_Solenoid_D,
          rty_Shift_Solenoid_E, localDW);
      } else if ((rtu_Gear_Lever_Position == 2) && (rtu_Brake_Pedal_Switch == 1)
                 && (rtu_Vehicle_Speed_Reference < 3)) {
        localDW->is_c3_Gear_Selection_Library = TCM_Final_IN_Neutral;
        *rty_Current_Gear = localDW->N;
      } else {
        *rty_Shift_Solenoid_A = 1U;
        *rty_Shift_Solenoid_B = 0U;
        *rty_Shift_Solenoid_C = 0U;
        *rty_Shift_Solenoid_D = 1U;
        *rty_Shift_Solenoid_E = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Gear_Selection' */

  /* Chart: '<S1>/Hydraulic_Pressure_Control' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion3'
   */
  if (localDW->is_active_c3_Hydraulic_Pressure == 0) {
    localDW->is_active_c3_Hydraulic_Pressure = 1U;
  } else {
    /* Outputs for Function Call SubSystem: '<S4>/EPC_F' */
    /* DataTypeConversion: '<S9>/Data Type Conversion3' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion'
     *  DataTypeConversion: '<S9>/Data Type Conversion1'
     *  Lookup_n-D: '<S9>/2-D Lookup Table1'
     *  Lookup_n-D: '<S9>/LUT1 — P_ff_base'
     *  Lookup_n-D: '<S9>/PWM_EPC'
     */
    tmp = floor(look2_binlcpw(look2_is16bdtd_binlcpw(rtu_Engine_Torque_Actual,
      *rty_Current_Gear, TCM_Final_ConstP.LUT1P_ff_base_bp01Data,
      TCM_Final_ConstP.pooled1, TCM_Final_ConstP.LUT1P_ff_base_tableData,
      TCM_Final_ConstP.LUT1P_ff_base_maxIndex, 10U), look2_is8bdtd_binlcpw
      (rtu_Transmission_Fluid_Temp, (int8_T)rtu_Throttle_Position_Sensor,
       TCM_Final_ConstP.uDLookupTable1_bp01Data,
       TCM_Final_ConstP.uDLookupTable1_bp02Data,
       TCM_Final_ConstP.uDLookupTable1_tableData,
       TCM_Final_ConstP.uDLookupTable1_maxIndex, 7U),
      TCM_Final_ConstP.PWM_EPC_bp01Data, TCM_Final_ConstP.PWM_EPC_bp02Data,
      TCM_Final_ConstP.PWM_EPC_tableData, TCM_Final_ConstP.PWM_EPC_maxIndex, 5U));
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    *rty_Line_Pressure_Control_Solen = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

    /* End of Outputs for SubSystem: '<S4>/EPC_F' */
  }

  /* End of Chart: '<S1>/Hydraulic_Pressure_Control' */

  /* Chart: '<S1>/TCC_Control' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   *  DataTypeConversion: '<S10>/Data Type Conversion1'
   *  DataTypeConversion: '<S10>/Data Type Conversion2'
   *  DataTypeConversion: '<S10>/Data Type Conversion3'
   *  DataTypeConversion: '<S10>/Data Type Conversion4'
   *  DataTypeConversion: '<S10>/Data Type Conversion5'
   *  Lookup_n-D: '<S10>/2-D Lookup Table'
   *  Lookup_n-D: '<S10>/2-D Lookup Table1'
   *  Lookup_n-D: '<S10>/2-D Lookup Table2'
   */
  if (localDW->is_active_c3_TCC_Control_Librar == 0) {
    localDW->is_active_c3_TCC_Control_Librar = 1U;
    localDW->is_c3_TCC_Control_Library = TCM_Final_IN_Release;
  } else if (localDW->is_c3_TCC_Control_Library == TCM_Final_IN_Release) {
    if ((rtu_Brake_Pedal_Switch == 0) && (rtu_Output_Speed_Sensor > 30) &&
        (rtu_Transmission_Fluid_Temp > 55)) {
      localDW->is_c3_TCC_Control_Library = TCM_Final_IN_SlipMode;
    } else {
      *rty_TCC_Control_Solenoid = 0U;
    }

    /* case IN_SlipMode: */
  } else if (rtu_Brake_Pedal_Switch == 1) {
    localDW->is_c3_TCC_Control_Library = TCM_Final_IN_Release;
  } else {
    qY = (uint32_T)rtu_Engine_RPM -
      /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
      /*MW:OvSatOk*/ rtu_Turbine_Speed_Sensor;
    if (qY > rtu_Engine_RPM) {
      qY = 0U;
    }

    /* Outputs for Function Call SubSystem: '<S5>/SlipMode_F' */
    *rty_TCC_Control_Solenoid = (uint8_T)look2_iu16lu32n16_binlcse((uint16_T)
      look2_is16bu8s16lu32n1_I4aWljRd(*rty_Current_Gear,
      rtu_Engine_Torque_Actual, TCM_Final_ConstP.uDLookupTable_bp01Data,
      TCM_Final_ConstP.uDLookupTable_bp02Data,
      TCM_Final_ConstP.uDLookupTable_tableData, TCM_Final_ConstP.pooled3, 6U),
      (uint16_T)look2_is16bdlu32n16Ds3_dIbdfcxG(*rty_Current_Gear, (int16_T)qY,
      TCM_Final_ConstP.pooled1, TCM_Final_ConstP.uDLookupTable1_bp02Data_c,
      TCM_Final_ConstP.uDLookupTable1_tableData_k, TCM_Final_ConstP.pooled3, 6U),
      TCM_Final_ConstP.pooled4, TCM_Final_ConstP.pooled4,
      TCM_Final_ConstP.uDLookupTable2_tableData,
      TCM_Final_ConstP.uDLookupTable2_maxIndex, 10U);

    /* End of Outputs for SubSystem: '<S5>/SlipMode_F' */
  }

  /* End of Chart: '<S1>/TCC_Control' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
