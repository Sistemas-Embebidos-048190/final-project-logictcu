/**
 * @file    tcu.c
 * @brief   TCU integration with RTE and Simulink-generated model.
 *
 * This module is responsible for:
 *  - Initializing the Simulink-generated TCM_Final model.
 *  - Reading inputs from the RTE and mapping them to TCM_Final_U.
 *  - Executing one control step of the TCM logic (TCM_Final_step).
 *  - Mapping TCM_Final_Y outputs back to RTE signals.
 *
 * The periodic invocation of @ref TCU_step is handled by the OS layer
 * (see Rte_os.c → Rte_Task_logic).
 */

/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "tcu.h"

/* **********************************************************************
 * Public functions
 * *********************************************************************/

/**
 * @brief Initializes the TCU model.
 *
 * This function must be called once during system startup before any
 * periodic calls to @ref TCU_step.
 */
void TCU_init (void)
{
	TCM_Final_initialize();
}

/**
 * @brief Executes one control step of the TCM_Final model.
 *
 * Sequence:
 *  1) Read all required inputs from the RTE.
 *  2) Map them to the Simulink input structure TCM_Final_U.
 *  3) Execute the model step via TCM_Final_step().
 *  4) Map model outputs from TCM_Final_Y to RTE write signals.
 *
 * This function is typically called periodically (e.g. every 100 ms)
 * from the OS task @ref Rte_Task_logic.
 */
void TCU_step(void)
{
    /* ******************************************************************
     * Read inputs from RTE
     *******************************************************************/

	uint8	 				brake;
    gear_level_possition 	gear;
    uint16  				turbineSpeed_rpm;
    sint8	  				fluidTemp;
    uint16 					outputSpeed_rpm;       // OSS, de ADC
    sint16					vehicleSpeed_kph;      // de CAN (ABS/ECU)
    uint16					engineSpeed_rpm;       // de CAN (Engine/ECU)
    uint8					driveMode;
    uint8					throttlePossition;
    sint16					engineTorque;

    Rte_read_g_HW_BrakeSW(&brake);
    Rte_read_g_HW_LeverPosition(&gear);
    Rte_read_g_HW_TurbineSpeed(&turbineSpeed_rpm);
    Rte_read_g_HW_TransmissionTEMP(&fluidTemp);
    Rte_read_g_HW_OutputSpeed(&outputSpeed_rpm);
    Rte_read_g_CAN_VehicleSpeed(&vehicleSpeed_kph);
    Rte_read_g_CAN_EngineRPM(&engineSpeed_rpm);
    Rte_read_g_CAN_DriveMode(&driveMode);
    Rte_read_g_CAN_ThrottlePosition(&throttlePossition);
    Rte_read_g_CAN_EngineTorque(&engineTorque);

    /* ******************************************************************
     * Map RTE inputs to Simulink model inputs (TCM_Final_U)
     *******************************************************************/
    TCM_Final_U.Brake_Pedal_Switch    	= brake;
    TCM_Final_U.Gear_Lever_Position   	= gear;
    TCM_Final_U.Turbine_Speed_Sensor  	= turbineSpeed_rpm;
    TCM_Final_U.Transmission_Fluid_Temp = fluidTemp;
    TCM_Final_U.Output_Speed_Sensor		= outputSpeed_rpm;
    TCM_Final_U.Vehicle_Speed_Reference = outputSpeed_rpm;
    TCM_Final_U.Engine_RPM 				= engineSpeed_rpm;
    TCM_Final_U.Driver_Mode_Selection 	= driveMode;
    TCM_Final_U.Throttle_Position_Sensor= throttlePossition;
    TCM_Final_U.Engine_Torque_Actual	= engineTorque;

    /* ******************************************************************
     *Execute model step
     *******************************************************************/
    TCM_Final_step();

    /* ******************************************************************
     * Map model outputs to RTE signals
     *******************************************************************/
    uint8 solenoidA 		= TCM_Final_Y.Shift_Solenoid_A;
    uint8 solenoidB 		= TCM_Final_Y.Shift_Solenoid_B;
    uint8 solenoidC 		= TCM_Final_Y.Shift_Solenoid_C;
    uint8 solenoidD 		= TCM_Final_Y.Shift_Solenoid_D;
    uint8 solenoidE 		= TCM_Final_Y.Shift_Solenoid_E;
    uint8 currentGear 		= TCM_Final_Y.Current_Gear;
    uint8 solenoidTCC   	= TCM_Final_Y.TCC_Control_Solenoid;
    uint8 PressureSolenoid 	= TCM_Final_Y.Line_Pressure_Control_Solenoid;
    /*uint8 lockSolenoid 	= TCM_Final_Y.LockSolenoid; //Reserved for future use*/

    /* NOTE:
     * Actualmente se usan múltiples llamadas a la misma API
     * Rte_write_g_OUT_ShiftSolenoid() para A..E.
     * Si en el futuro hay una señal distinta por solenoide en el RTE,
     * aquí se deberá ajustar el mapeo.
     */
    Rte_write_g_OUT_ShiftSolenoidA(solenoidA);
    Rte_write_g_OUT_ShiftSolenoidB(solenoidB);
    Rte_write_g_OUT_ShiftSolenoidC(solenoidC);
    Rte_write_g_OUT_ShiftSolenoidD(solenoidD);
    Rte_write_g_OUT_ShiftSolenoidE(solenoidE);

    Rte_write_g_OUT_CurrentGear(currentGear);
    Rte_write_g_OUT_TCC_ControlSolenoid(solenoidTCC);
    Rte_write_g_OUT_LinePressure_Control(PressureSolenoid);

}
