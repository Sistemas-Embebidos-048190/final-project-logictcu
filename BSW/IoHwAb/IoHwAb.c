/**
 * @file    IoHwAb.c
 * @brief   High-level I/O Hardware Abstraction integration module.
 *
 * This module initializes and updates all hardware inputs/outputs used by
 * the TCM (Transmission Control Module). It acts as the central point that
 * coordinates GPIO, ADC and PWM submodules.
 *
 * Responsibilities:
 *  - Initialize all I/O peripherals (GPIO, ADC, PWM)
 *  - Read all hardware inputs and publish them to the RTE
 *  - Write all hardware outputs from RTE commands to physical pins
 *
 * This module must be called from the application layer:
 *  - Init_IO_pins()   → called once during system startup
 *  - Update_IO_pins() → called periodically (e.g. every main loop or task)
 */

/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "IoHwAb.h"

/* **********************************************************************
 * Functions
 * *********************************************************************/

/**
 * @brief Initializes all I/O peripherals used by the TCM.
 *
 * This function calls the initialization routines of:
 *  - GPIO inputs (Brake pedal, Gear position)
 *  - GPIO outputs (Shift solenoids, Shift-lock solenoid)
 *  - ADC pins and LPADC modules (Output speed, Fluid temperature, Turbine speed)
 *  - PWM pins and modules (Line pressure, TCC)
 *
 * Must be called **once** during system startup before any I/O access occurs.
 */
void Init_IO_pins (void)
{
	Init_Pin_BreakPedal();
	Init_Pin_GearPossition();
	Init_Pin_ShiftSolenoids();
	Init_Pin_ShiftLockSolenoid();
	Init_ADC_Pins();
	TCM_LPADC_InitSensors();
	Init_Pin_PWM();
}

/**
 * @brief Updates the state of all I/O pins.
 *
 * This function performs:
 *  - Reading of all digital inputs (gear lever position, brake pedal)
 *  - Writing of all digital outputs (shift solenoids, shift-lock solenoid)
 *  - ADC conversion and publishing of sensor values (speed, temperature)
 *  - PWM duty update for hydraulic line pressure and TCC control
 *
 * Must be called periodically (e.g., in main loop or cyclic task).
 */
void Update_IO_pins(void)
{
    /* ==========================
     *      GPIO INPUTS
     * ========================== */
	TCM_read_gear_level_possition();
	TCM_read_pedal_possition();

    /* ==========================
     *      GPIO OUTPUTS
     * ========================== */
	TCM_set_shift_solenoids();
	TCM_set_ShiftLock_soenoid ();

    /* ==========================
     *      ADC SENSORS
     * ========================== */
	TCM_Read_OutputSpeedSensorRaw();
	TCM_Read_FluidTempSensorRaw();
	TCM_Read_TurbineSpeedSensorRaw();

    /* ==========================
     *      PWM OUTPUTS
     * ========================== */
	TCM_set_line_pressure();
	TCM_set_TCC_control();
}
