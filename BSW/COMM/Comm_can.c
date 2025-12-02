
#include "CAN_signals_simulations.h"
#include "Comm_can.h"
#include "RTE_write.h"

void TCM_Comm (void)
{


	//Rte_write_g_CAN_IgnitionStatus();

	for (int i = 0; i < SCENARIO_STEPS; i++)
	{
	         // 1. Actualizar las entradas simuladas
	         Simulate_CAN_Bus_Update(i);

	     	Rte_write_g_CAN_EngineRPM(current_inputs.engine_rpm);
	     	Rte_write_g_CAN_ThrottlePosition(current_inputs.throttle_pos);
	     	Rte_write_g_CAN_EngineTorque(current_inputs.engine_torque);
	     	Rte_write_g_CAN_VehicleSpeed(current_inputs.vehicle_speed_ref);
	     	Rte_write_g_CAN_DriveMode(current_inputs.drive_mode);
	 }
}
