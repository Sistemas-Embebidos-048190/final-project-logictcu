/*
 * RTE_write.c
 *
 *  Created on: Nov 22, 2025
 *      Author: bruno
 */
#include "RTE_write.h"
_
Rte_write_g_HW_LeverPosition(uint8 LvrPosition)
{
	set_g_HW_LvrPosition(LvrPosition);
}
Rte_write_g_CAN_EngineRPM(uint16 RPMS)
{
    set_g_CAN_EngineRPM(RPMS);
}
Rte_write_g_CAN_ThrottlePosition(uint8 TrtPosition)
{
	set_g_CAN_ThrottlePosition(TrtPosition);
}
Rte_write_g_CAN_EngineTorque(sint16 Torque)
{
	set_g_CAN_EngineTorque(Torque);
}
Rte_write_g_CAN_VehicleSpeed(sint16 VhSpeed)
{
	set_g_CAN_VehicleSpeed(VhSpeed);
}
Rte_write_g_CAN_DriveMode(uint8 Mode)
{
	set_g_CAN_DriveMode(Mode);
}
Rte_write_g_CAN_IgnitionStatus(uint8 IgnStatus)
{
	set_g_CAN_IgnitionStatus(IgnStatus);
}
Rte_write_g_HW_LeverPosition(uint8 LvrPosition)
{
	set_g_HW_LeverPosition(LvrPosition);
}
Rte_write_g_HW_BrakeSW(uint8 Brake)
{
	set_g_HW_BrakeSW(Brake);
}
Rte_write_g_HW_InputSpeed(uint16 InSpeed)
{
	set_g_HW_InputSpeed(InSpeed);
}
Rte_write_g_HW_OutputSpeed(uint16 OutSpeed)
{
	set_g_HW_OutputSpeed(OutSpeed);
}
Rte_write_g_HW_TransmissionTEMP(sint8 Temperature)
{
	set_g_HW_TransmissionTEMP(Temperature);
}
Rte_write_g_OUT_ShiftSolenoid(uint8 ShiftSol)
{
	set_g_OUT_ShiftSolenoid(ShiftSol);
}
Rte_write_g_OUT_LinePressure_Control(uint8 Pressure)
{
	set_g_OUT_LinePressure_Control(Pressure);
}
Rte_write_g_OUT_TCC_ControlSolenoid(uint8 CntrlSol)
{
	set_g_OUT_TCC_ControlSolenoid(CntrlSol);
}
Rte_write_g_OUT_ShiftLock_Solenoid(uint8 ShiftLock)
{
	set_g_OUT_ShiftLock_Solenoid(ShiftLock);
}
Rte_write_g_OUT_TorqueReduction_Request(uint8 TrqReduction)
{
	set_g_OUT_TorqueReduction_Request(TrqReduction);
}
Rte_write_g_OUT_CurrentGear(uint8 Gear)
{
	set_g_OUT_CurrentGear(Gear);
}
