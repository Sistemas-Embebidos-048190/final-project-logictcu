/*
 * @file    Get_signals.c
 * @brief   Provides getter functions for all global TCM signals.
 *
 * This file:
 *  - Exposes read-only access to CAN, hardware input, and output signals.
 *  - Centralizes retrieval of all system-wide variables used by the TCU.
 *  - Prevents direct access to global variables from other modules.
 *
 *  Created on: Nov 11, 2025
 *      Author: bruno
 */

#include "Get_signals.h"

uint16 Get_g_CAN_EngineRPM(void)
{
	return g_CAN_EngineRPM;
}
uint8 Get_g_CAN_ThrottlePosition(void)
{
	return g_CAN_ThrottlePosition;
}
sint16 Get_g_CAN_EngineTorque(void)
{
	return g_CAN_EngineTorque;
}
uint8 Get_g_CAN_VehicleSpeed(void)
{
	return g_CAN_VehicleSpeed;
}
uint8 Get_g_CAN_DriveMode(void)
{
	return g_CAN_DriveMode;
}
uint8 Get_g_CAN_IgnitionStatus(void)
{
	return g_CAN_IgnitionStatus;
}
uint8 Get_g_HW_LeverPosition(void)
{
	return g_HW_LeverPosition;
}
uint8 Get_g_HW_BrakeSW(void)
{
	return g_HW_BrakeSW;
}
uint16 Get_g_HW_TurbineSpeed(void)
{
	return g_HW_TurbineSpeed;
}
uint16 Get_g_HW_OutputSpeed(void)
{
	return g_HW_OutputSpeed;
}
sint8 Get_g_HW_TransmissionTEMP(void)
{
	return g_HW_TransmissionTEMP;
}
uint8 Get_g_OUT_ShiftSolenoidA(void)
{
	return g_OUT_ShiftSolenoidA;
}
uint8 Get_g_OUT_ShiftSolenoidB(void)
{
	return g_OUT_ShiftSolenoidB;
}
uint8 Get_g_OUT_ShiftSolenoidC(void)
{
	return g_OUT_ShiftSolenoidC;
}
uint8 Get_g_OUT_ShiftSolenoidD(void)
{
	return g_OUT_ShiftSolenoidD;
}
uint8 Get_g_OUT_ShiftSolenoidE(void)
{
	return g_OUT_ShiftSolenoidE;
}
uint8 Get_g_OUT_LinePressure_Control(void)
{
	return g_OUT_LinePressure_Control;
}
uint8 Get_g_OUT_TCC_ControlSolenoid(void)
{
	return g_OUT_TCC_ControlSolenoid;
}
uint8 Get_g_OUT_ShiftLock_Solenoid(void)
{
	return g_OUT_ShiftLock_Solenoid;
}
uint8 Get_g_OUT_TorqueReduction_Request(void)
{
	return g_OUT_TorqueReduction_Request;
}
uint8 Get_g_OUT_CurrentGear(void)
{
	return g_OUT_CurrentGear;
}
