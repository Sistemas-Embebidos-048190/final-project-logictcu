/**
 * @file    IoHwAb_gpio.h
 * @brief   GPIO pin definitions and initialization APIs for the
 *          Transmission Control Module (TCM).
 *
 * This header belongs to the IoHwAb (I/O Hardware Abstraction) layer.
 * It exposes:
 *  - Symbolic pin definitions (no magic numbers in the .c file)
 *  - Initialization functions for all GPIOs used by the TCM
 *
 * The GPIOs covered here include:
 *  - Brake pedal input
 *  - Gear lever position inputs (P, R, N, D, 1st, 2nd)
 *  - Shift solenoids (A, B, C, D, E)
 *  - Shift-lock solenoid
 *
 * Each pin macro represents the **pin number** for the corresponding PORT/GPIO
 * instance specified in app.h or board.h.
 */

#ifndef _IOHWAB_GPIO_H_
#define _IOHWAB_GPIO_H_


/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "app.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "global_signals.h"
#include "RTE_write.h"
#include "RTE_read.h"

/* **********************************************************************
 * Defines
 * *********************************************************************/

/**
 * @name Brake Pedal Input
 * @{
 */
#define BREAK_PEDAL_PIN	4U			/**< Brake pedal GPIO pin */
/** @} */


/**
 * @name Gear Position Inputs
 * @{
 */
#define PARKING_PIN		(9U)			/**< Gear position: Parking  */
#define REVERSE_PIN 	(12U)			/**< Gear position: Reverse  */
#define NEUTRAL_PIN		(5U)			/**< Gear position: Neutral  */
#define DRIVE_PIN		(0U)			/**< Gear position: Drive    */
#define FIRST_PIN		(23U)			/**< Gear position: 1st gear */
#define SECOND_PIN		(13U)			/**< Gear position: 2nd gear */
/** @} */

/**
 * @name Shift Solenoid Outputs
 * @{
 */
#define SOLENOID_A_PIN      (17U)  	/**< Solenoid A */
#define SOLENOID_B_PIN      (22U)  	/**< Solenoid B */
#define SOLENOID_C_PIN      (15U)  	/**< Solenoid C */
#define SOLENOID_D_PIN      (14U)   	/**< Solenoid D */
#define SOLENOID_E_PIN      (4U)  	/**< Solenoid E */
/** @} */

/**
 * @name Shift-Lock Solenoid Output
 * @{
 */
#define LOCK_SOLENOID		(8U)	/**< Shift-lock solenoid */
/** @} */

/* Variables estáticas del debounce */
static uint8_t lastState = 0;      // último estado leído del pin, 0 o 1
static uint8_t stableState = 0;    // estado debounced
static uint8_t counter = 0;        // contador de estabilidad

#define DEBOUNCE_COUNT   3
/* **********************************************************************
 * API Prototypes
 * *********************************************************************/

/**
 * @brief Initializes the GPIO for the brake pedal input.
 *
 * Configures port mux and direction for @ref BREAK_PEDAL_PIN.
 */
void Init_Pin_BreakPedal(void);

/**
 * @brief Initializes all GPIOs used to detect mechanical gear position.
 *
 * Configures port mux and direction for:
 *  - @ref PARKING_PIN
 *  - @ref REVERSE_PIN
 *  - @ref NEUTRAL_PIN
 *  - @ref DRIVE_PIN
 *  - @ref FIRST_PIN
 *  - @ref SECOND_PIN
 */
void Init_Pin_GearPossition(void);

/**
 * @brief Initializes all GPIOs that drive the shift solenoids (A–E).
 *
 * Configures port mux and direction for:
 *  - @ref SOLENOID_A_PIN
 *  - @ref SOLENOID_B_PIN
 *  - @ref SOLENOID_C_PIN
 *  - @ref SOLENOID_D_PIN
 *  - @ref SOLENOID_E_PIN
 */
void Init_Pin_ShiftSolenoids(void);

/**
 * @brief Initializes the GPIO that controls the shift-lock solenoid.
 *
 * Configures port mux and direction for @ref LOCK_SOLENOID.
 */
void Init_Pin_ShiftLockSolenoid(void);

/**
 * @brief Reads gear lever position inputs and updates the corresponding RTE signal.
 *
 * Samples all position inputs (P, R, N, D, 1, 2) and determines the current
 * gear_level_possition based on the active input. The resolved position is
 * written to RTE (g_HW_LeverPosition) and also returned.
 *
 * @return Current lever position as gear_level_possition.
 */
gear_level_possition TCM_read_gear_level_possition(void);

/**
 * @brief Reads the debounced brake pedal state and updates the RTE signal.
 *
 * Uses an internal debounce algorithm to obtain a stable brake state and
 * maps it to PEDAL_ON / PEDAL_OFF. The resolved state is written to
 * RTE (g_HW_BrakeSW) and also returned.
 *
 * @return Current brake pedal state as pedal_possition.
 */
pedal_possition TCM_read_pedal_possition(void);

/**
 * @brief Updates shift solenoid outputs from RTE commands.
 *
 * Reads desired solenoid states from RTE (g_OUT_ShiftSolenoid) and drives
 * GPIO outputs for A, B, C, D, E accordingly.
 */
void TCM_set_shift_solenoids(void);

/**
 * @brief Updates the shift-lock solenoid output from RTE command.
 *
 * Reads desired state from RTE (g_OUT_ShiftLock_Solenoid) and drives
 * the @ref LOCK_SOLENOID GPIO output accordingly.
 */
void TCM_set_ShiftLock_soenoid (void);

/**
 * @brief Debounces the raw brake pedal input and returns a stable value.
 *
 * Internal helper used by @ref TCM_read_pedal_possition.
 *
 * @return Debounced brake pedal state (0 = released, 1 = pressed).
 */
uint16 IoHwAb_DebounceBrakeRaw();

#endif /* _IOHWAB_GPIO_H_ */
