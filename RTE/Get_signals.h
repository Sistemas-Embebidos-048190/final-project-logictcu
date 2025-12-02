/*
 * @file    Get_signals.h
 * @brief   Public API for accessing global TCM signals.
 *
 * This file:
 *  - Declares getter functions for all CAN, hardware input, and output signals.
 *  - Provides a standardized interface for retrieving system-wide variables.
 *  - Prevents external modules from accessing global variables directly.
 *
 *  Created on: Nov 11, 2025
 *      Author: bruno
 */

#ifndef RTE_GET_SIGNALS_H_
#define RTE_GET_SIGNALS_H_

#include "Platform_Types.h"
#include "global_signals.h"

//Inputs
uint16 Get_g_CAN_EngineRPM(void);
uint8 Get_g_CAN_ThrottlePosition(void);
sint16 Get_g_CAN_EngineTorque(void);
uint8 Get_g_CAN_VehicleSpeed(void);
uint8 Get_g_CAN_DriveMode(void);
uint8 Get_g_CAN_IgnitionStatus(void);
uint8 Get_g_HW_LeverPosition(void);
uint8 Get_g_HW_BrakeSW(void);
uint16 Get_g_HW_TurbineSpeed(void);
uint16 Get_g_HW_OutputSpeed(void);
sint8 Get_g_HW_TransmissionTEMP(void);

//Outputs
uint8 Get_g_OUT_ShiftSolenoidA(void);
uint8 Get_g_OUT_ShiftSolenoidB(void);
uint8 Get_g_OUT_ShiftSolenoidC(void);
uint8 Get_g_OUT_ShiftSolenoidD(void);
uint8 Get_g_OUT_ShiftSolenoidE(void);
uint8 Get_g_OUT_LinePressure_Control(void);
uint8 Get_g_OUT_TCC_ControlSolenoid(void);
uint8 Get_g_OUT_ShiftLock_Solenoid(void);
uint8 Get_g_OUT_TorqueReduction_Request(void);
uint8 Get_g_OUT_CurrentGear(void);

#endif /* RTE_GET_SIGNALS_H_ */
