/*
 * RTE_os.c
 *
 *  Created on: Nov 12, 2025
 *      Author: bruno
 */
#include "Rte_os.h"


#include "IoHwAb.h"
#include "IoHwAb_gpio.h"
#include "IoHwAb_adc.h"
#include "IoHwAb_pwm.h"
#include "MCU.h"

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


void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 800000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

uint16_t value1 = 0;
uint32_t triggerMask1 = (1UL << 0);
uint16_t value2 = 0;
uint32_t triggerMask2 = (1UL << 1);
uint16_t value3 = 0;
uint32_t triggerMask3 = (1UL << 2);
uint32_t pwmVal = 4;
const uint32_t g_LpadcResultShift = 3U;

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
static void Rte_task_Comm_Tx(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
    	//van primero las tareas
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
static void Rte_task_Comm_Rx(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
    	vTaskDelay(pdMS_TO_TICKS(100));
    }
}
static void Rte_task_swc(void *pvParameters)
{
    for (;;)
    {
        //PRINTF("Hello world.\r\n");
    	vTaskDelay(pdMS_TO_TICKS(100));
    }
}
static void Rte_Task_logic(void *pvParameters)
{
    for (;;)
    {
    	TCU_step();
    	vTaskDelay(pdMS_TO_TICKS(100));
    }
}


static void Rte_task(void *pvParameters)
{
	 for (;;)
	 {

		 Init_IO_pins();
		 Update_IO_pins();

		 vTaskDelay(pdMS_TO_TICKS(100));
	 }

}
