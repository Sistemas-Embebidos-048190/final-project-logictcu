/*
 *
 *
 */

#include "tcu.h"
#include "TCM_Final.h"
#include "RTE_write.h"
#include "RTE_read.h"
#include "rtwtypes.h"
#include "global_signals.h"

void TCU_init (void)
{
	TCM_Final_initialize();
}

void TCU_step(void)
{
	/* Leer entradas desde RTE */
	uint8	 				brake;
    gear_level_possition 	gear;
    uint16  				turbineSpeed_rpm;
    sint8	  				fluidTemp_x10;
    uint16 					outputSpeed_rpm;       // OSS, de ADC
    sint16					vehicleSpeed_kph;      // de CAN (ABS/ECU)
    uint16					engineSpeed_rpm;       // de CAN (Engine/ECU)
    uint8					driveMode;
    uint8					throttlePossition;
    sint16					engineTorque;


    Rte_read_g_HW_BrakeSW(&brake);
    Rte_read_g_HW_LeverPosition(&gear);
    Rte_read_g_HW_TurbineSpeed(&turbineSpeed_rpm);
    Rte_read_g_HW_TransmissionTEMP(&fluidTemp_x10);
    Rte_read_g_HW_OutputSpeed(&outputSpeed_rpm);
    Rte_read_g_CAN_VehicleSpeed(&vehicleSpeed_kph);
    Rte_read_g_CAN_EngineRPM(&engineSpeed_rpm);
    Rte_read_g_CAN_DriveMode(&driveMode);
    Rte_read_g_CAN_ThrottlePosition(&throttlePossition);
    Rte_read_g_CAN_EngineTorque(&engineTorque);

    TCM_Final_U.Brake_Pedal_Switch    	= brake;
    TCM_Final_U.Gear_Lever_Position   	= gear;
    TCM_Final_U.Turbine_Speed_Sensor  	= turbineSpeed_rpm;
    TCM_Final_U.Transmission_Fluid_Temp = fluidTemp_x10;
    TCM_Final_U.Output_Speed_Sensor		= outputSpeed_rpm;
    TCM_Final_U.Vehicle_Speed_Reference = vehicleSpeed_kph;
    TCM_Final_U.Engine_RPM 				= engineSpeed_rpm;
    TCM_Final_U.Driver_Mode_Selection 	= driveMode;
    TCM_Final_U.Throttle_Position_Sensor= throttlePossition;
    TCM_Final_U.Engine_Torque_Actual	= engineTorque;

    TCM_Final_step();

    /* Tomar las salidas del modelo y escribir al RTE */
    uint8 solenoidA 		= TCM_Final_Y.Shift_Solenoid_A;
    uint8 solenoidB 		= TCM_Final_Y.Shift_Solenoid_B;
    uint8 solenoidC 		= TCM_Final_Y.Shift_Solenoid_C;
    uint8 solenoidD 		= TCM_Final_Y.Shift_Solenoid_D;
    uint8 solenoidE 		= TCM_Final_Y.Shift_Solenoid_E;
    uint8 currentGear 		= TCM_Final_Y.Current_Gear;
    uint8 solenoidTCC   	= TCM_Final_Y.TCC_Control_Solenoid;
    uint8 PressureSolenoid 	= TCM_Final_Y.Line_Pressure_Control_Solenoid;
    //uint8 lockSolenoid 	= TCM_Final_Y.LockSolenoid;

    Rte_write_g_OUT_ShiftSolenoid(solenoidA);
    Rte_write_g_OUT_ShiftSolenoid(solenoidB);
    Rte_write_g_OUT_ShiftSolenoid(solenoidC);
    Rte_write_g_OUT_ShiftSolenoid(solenoidD);
    Rte_write_g_OUT_ShiftSolenoid(solenoidE);
    Rte_write_g_OUT_CurrentGear(currentGear);
    Rte_write_g_OUT_TCC_ControlSolenoid(solenoidTCC);
    Rte_write_g_OUT_LinePressure_Control(PressureSolenoid);

}
