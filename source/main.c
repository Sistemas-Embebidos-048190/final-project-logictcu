/*
 * @file    main.c
 * @brief   Application entry point for the TCM project using FreeRTOS.
 *
 * This file:
 *  - Initializes board and MCU hardware.
 *  - Configures system clocks and ports.
 *  - Starts the RTE / OS integration, which creates all application tasks
 *    and starts the FreeRTOS scheduler.
 */


/* **********************************************************************
 * FreeRTOS kernel includes
 * *********************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* RTE / OS integration */
#include "Rte_os.h"

/* **********************************************************************
 * NXP / Board includes
 * *********************************************************************/
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"

/* MCU / low-level init */
#include "MCU.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Application entry point.
 *
 * Sequence:
 *  1) Initialize board hardware (pins, clocks, debug console, etc.).
 *  2) Initialize port clocks (Init_Clock_Ports).
 *  3) Initialize and start all RTE/OS tasks via @ref Rte_task_Init().
 *
 * @return This function should never return under normal operation
 *         because the RTOS scheduler takes control.
 */
int main(void)
{
	/* Init board hardware (pins, clocks, debug console, etc.). */
    BOARD_InitHardware();

    /* Init MCU clocking for ports and peripherals (project-specific). */
    Init_Clock_Ports();

    /* Create all RTE tasks and start the scheduler (never returns). */
    Rte_task_Init();
}

