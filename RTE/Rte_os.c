/*
 * @file    Rte_os.c
 * @brief   OS integration and task creation for the RTE / TCM application.
 *
 * This module is responsible for:
 *  - Creating all FreeRTOS tasks used by the TCM software components.
 *  - Starting the RTOS scheduler.
 *  - Providing cyclic execution of:
 *      - I/O Hardware Abstraction (IoHwAb)
 *      - TCU_step() application logic
 *      - Communication Tx/Rx placeholders
 *      - SWC (software components) placeholder task
 *
 * Tasks:
 *  - Rte_task          : Periodic I/O update (GPIO, ADC, PWM via IoHwAb)
 *  - Rte_Task_logic    : Periodic application logic (TCU_step)
 *  - Rte_task_Comm_Tx  : Periodic communication transmit (stub)
 *  - Rte_task_Comm_Rx  : Periodic communication receive (stub)
 *  - Rte_task_swc      : Periodic SWC execution (stub)
 *
 *  Created on: Nov 12, 2025
 *      Author: bruno
 */
#include "Rte_os.h"

/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "IoHwAb.h"
#include "IoHwAb_gpio.h"
#include "IoHwAb_adc.h"
#include "IoHwAb_pwm.h"
#include "MCU.h"
#include "Comm_can.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void Rte_task_Init();
static void Rte_task(void *pvParameters);
static void Rte_Task_logic(void *pvParameters);
static void Rte_task_Comm_Tx(void *pvParameters);
static void Rte_task_Comm_Rx(void *pvParameters);
static void Rte_task_swc(void *pvParameters);

/*******************************************************************************
 * defines
 ******************************************************************************/
#define Rte_task_PRIORITY (configMAX_PRIORITIES - 1)
#define Rte_task_Comm_TxPRIORITY (configMAX_PRIORITIES - 1)
#define Rte_task_Comm_RxPRIORITY (configMAX_PRIORITIES - 1)
#define Rte_task_swcPRIORITY (configMAX_PRIORITIES - 1)
#define Rte_Task_logicPRIORITY (configMAX_PRIORITIES - 1)

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Creates all RTE-related tasks and starts the scheduler.
 *
 * This function:
 *  - Creates:
 *      - Rte_task
 *      - Rte_task_Comm_Tx
 *      - Rte_task_Comm_Rx
 *      - Rte_task_swc
 *      - Rte_Task_logic
 *  - Starts the FreeRTOS scheduler.
 *
 * If any task creation fails, the function enters an infinite loop.
 *
 * @note This function is typically called from main() after basic MCU init.
 */
void Rte_task_Init()
{
	if (xTaskCreate(Rte_task, "Rte_task", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_PRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_task_Comm_Tx, "Rte_task_Comm_Tx", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_Comm_TxPRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_task_Comm_Rx, "Rte_task_Comm_Rx", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_Comm_RxPRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_task_swc, "Rte_task_swc", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_swcPRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_Task_logic, "Rte_Task_logic", configMINIMAL_STACK_SIZE + 100, NULL, Rte_Task_logicPRIORITY, NULL) !=
	        pdPASS)
	    {
	        //PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }

    vTaskStartScheduler();
    for (;;)
        ;
}

/**
 * @brief Periodic communication transmit task (stub).
 *
 * Intended responsibilities:
 *  - Handle cyclic transmission of diagnostic / CAN / LIN / UART messages.
 *
 * Currently:
 *  - Only waits for @ref RTE_TASK_PERIOD_MS (100 ms) in a loop.
 */
static void Rte_task_Comm_Tx(void *pvParameters)
{
    for (;;)
    {
    	//PRINTF("Hello world.\r\n");
    	//van primero las tareas
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

/**
 * @brief Periodic communication receive task (stub).
 *
 * Intended responsibilities:
 *  - Handle reception of diagnostic / CAN / LIN / UART messages.
 *
 * Currently:
 *  - Only waits for @ref RTE_TASK_PERIOD_MS (100 ms) in a loop.
 */
static void Rte_task_Comm_Rx(void *pvParameters)
{
    for (;;)
    {
    	TCM_Comm();
        //PRINTF("Hello world.\r\n");

    }
}

/**
 * @brief Periodic Software Component (SWC) execution task (stub).
 *
 * Intended responsibilities:
 *  - Execute AUTOSAR SWCs or equivalent application components.
 *
 * Currently:
 *  - Only waits for @ref RTE_TASK_PERIOD_MS (100 ms) in a loop.
 */
static void Rte_task_swc(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
    	vTaskDelay(pdMS_TO_TICKS(100));
    }
}

/**
 * @brief Periodic logic task for the main TCU application.
 *
 * This task:
 *  - Calls @ref TCU_step() every @ref RTE_TASK_PERIOD_MS milliseconds.
 *
 * @param pvParameters Unused.
 */
static void Rte_Task_logic(void *pvParameters)
{
    for (;;)
    {
    	TCU_step();
    	vTaskDelay(pdMS_TO_TICKS(100));
    }
}

/**
 * @brief Periodic IoHwAb task.
 *
 * This task:
 *  - Calls @ref Init_IO_pins() once at startup.
 *  - Calls @ref Update_IO_pins() every @ref RTE_TASK_PERIOD_MS milliseconds.
 *
 * Responsibilities:
 *  - Hardware input acquisition (GPIO + ADC) and publication to RTE.
 *  - Hardware output actuation (GPIO + PWM) from RTE commands.
 *
 * @param pvParameters Unused.
 */
static void Rte_task(void *pvParameters)
{
	Init_IO_pins();

	 for (;;)
	 {
		 Update_IO_pins();

		 vTaskDelay(pdMS_TO_TICKS(100));
	 }

}
