/*
 *
 */


#include "IoHwAb.h"

void Init_IO_pins (void)
{
	Init_Pin_BreakPedal();
	Init_Pin_GearPossition();
	Init_Pin_ShiftSolenoids();
	Init_Pin_ShiftLockSolenoid();
	Init_ADC_Pins();
	Init_Pin_PWM();

}

void Update_IO_pins(void)
{
	/*GPIO*/
	TCM_read_gear_level_possition();
	TCM_read_pedal_possition();
	TCM_set_shift_solenoids();
	TCM_set_ShiftLock_soenoid ();

	/*ADC*/
	TCM_Read_OutputSpeedSensorRaw();
	TCM_Read_FluidTempSensorRaw();
	TCM_Read_TurbineSpeedSensorRaw();

	/*PWM*/
	TCM_set_line_pressure();
	TCM_set_TCC_control();

}
