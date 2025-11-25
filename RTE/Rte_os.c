/*
 * RTE_os.c
 *
 *  Created on: Nov 12, 2025
 *      Author: bruno
 */
#include "Rte_os.h"

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
 * Code
 ******************************************************************************/

void Rte_task_Init()
{
	if (xTaskCreate(Rte_task, "Rte_task", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_PRIORITY, NULL) !=
	        pdPASS)
	    {
	        PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_task_Comm_Tx, "Rte_task_Comm_Tx", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_Comm_Tx_PRIORITY, NULL) !=
	        pdPASS)
	    {
	        PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_task_Comm_Rx, "Rte_task_Comm_Rx", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_Comm_Rx_PRIORITY, NULL) !=
	        pdPASS)
	    {
	        PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_task_swc, "Rte_task_swc", configMINIMAL_STACK_SIZE + 100, NULL, Rte_task_swcPRIORITY, NULL) !=
	        pdPASS)
	    {
	        PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }
	if (xTaskCreate(Rte_Task_logic, "Rte_Task_logic", configMINIMAL_STACK_SIZE + 100, NULL, Rte_Task_logicPRIORITY, NULL) !=
	        pdPASS)
	    {
	        PRINTF("Task creation failed!.\r\n");
	        while (1)
	        	;
	    }

    vTaskStartScheduler();
    for (;;)
        ;
}
static void Rte_task_Comm_Tx(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
        vTaskSuspend(NULL);
    }
}
static void Rte_task_Comm_Rx(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
        vTaskSuspend(NULL);
    }
}
static void Rte_task_swc(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
        vTaskSuspend(NULL);
    }
}
static void Rte_Task_logic(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
        vTaskSuspend(NULL);
    }
}
static void Rte_task(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
        vTaskSuspend(NULL);
    }
}
