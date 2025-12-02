/*
 * @file    RTE_read.h
 * @brief   Read-access interface for all RTE signals.
 *
 * This file:
 *  - Declares functions used to read CAN inputs, hardware inputs, and TCU outputs.
 *  - Wraps Get_signals.c to provide a standardized RTE-level API.
 *  - Ensures consistent and safe retrieval of system signals across modules.
 *
 *  Created on: Nov 20, 2025
 *      Author: bruno
 */

#ifndef RTE_RTE_READ_H_
#define RTE_RTE_READ_H_

#include "Platform_Types.h"
#include "Get_signals.h"

//Inputs
void Rte_read_g_CAN_EngineRPM(uint16 *RPMS);
void Rte_read_g_CAN_ThrottlePosition(uint8 *TrtPosition);
void Rte_read_g_CAN_EngineTorque(sint16 *Torque);
void Rte_read_g_CAN_VehicleSpeed(sint16 *VhSpeed);
void Rte_read_g_CAN_DriveMode(uint8 *Mode);
void Rte_read_g_CAN_IgnitionStatus(uint8 *IgnStatus);
void Rte_read_g_HW_LeverPosition(uint8 *LvrPosition);
void Rte_read_g_HW_BrakeSW(uint8 *Brake);
void Rte_read_g_HW_TurbineSpeed(uint16 *TbSpeed);
void Rte_read_g_HW_OutputSpeed(uint16 *OutSpeed);
void Rte_read_g_HW_TransmissionTEMP(sint8 *Temperature);

//Outputs
void Rte_read_g_OUT_ShiftSolenoidA(uint8 *ShiftSol);
void Rte_read_g_OUT_ShiftSolenoidB(uint8 *ShiftSol);
void Rte_read_g_OUT_ShiftSolenoidC(uint8 *ShiftSol);
void Rte_read_g_OUT_ShiftSolenoidD(uint8 *ShiftSol);
void Rte_read_g_OUT_ShiftSolenoidE(uint8 *ShiftSol);
void Rte_read_g_OUT_LinePressure_Control(uint8 *Pressure);
void Rte_read_g_OUT_TCC_ControlSolenoid(uint8 *CntrlSol);
void Rte_read_g_OUT_ShiftLock_Solenoid(uint8 *ShiftLock);
void Rte_read_g_OUT_TorqueReduction_Request(uint8 *TrqReduction);
void Rte_read_g_OUT_CurrentGear(uint8 *Gear);



#endif /* RTE_RTE_READ_H_ */
