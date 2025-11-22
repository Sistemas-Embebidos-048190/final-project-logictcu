/*
 * RTE_write.h
 *
 *  Created on: Nov 22, 2025
 *      Author: bruno
 */

#ifndef RTE_RTE_WRITE_H_
#define RTE_RTE_WRITE_H_

#include "Platform_Types.h"
#include "set_signals.h"

//Inputs
Rte_read_g_CAN_EngineRPM(uint16 RPMS);
Rte_read_g_CAN_ThrottlePosition(uint8 TrtPosition);
Rte_read_g_CAN_EngineTorque(sint16 Torque);
Rte_read_g_CAN_VehicleSpeed(uint8 VhSpeed);
Rte_read_g_CAN_DriveMode(uint8 Mode);
Rte_read_g_CAN_IgnitionStatus(uint8 IgnStatus);
Rte_read_g_HW_LeverPosition(uint8 LvrPosition);
Rte_read_g_HW_BrakeSW(uint8 Brake);
Rte_read_g_HW_InputSpeed(uint16 InSpeed);
Rte_read_g_HW_OutputSpeed(uint16 OutSpeed);
Rte_read_g_HW_TransmissionTEMP(sint8 Temperature);

//Outputs
Rte_read_g_OUT_ShiftSolenoid(uint8 ShiftSol);
Rte_read_g_OUT_LinePressure_Control(uint8 Pressure);
Rte_read_g_OUT_TCC_ControlSolenoid(uint8 CntrlSol);
Rte_read_g_OUT_ShiftLock_Solenoid(uint8 ShiftLock);
Rte_read_g_OUT_TorqueReduction_Request(uint8 TrqReduction);
Rte_read_g_OUT_CurrentGear(uint8 Gear);

#endif /* RTE_RTE_WRITE_H_ */
