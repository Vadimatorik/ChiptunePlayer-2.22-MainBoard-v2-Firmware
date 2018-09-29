#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#define configUSE_HEAP_SCHEME						4

#define configUSE_PREEMPTION						1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION		1
#define configCPU_CLOCK_HZ							168000000
#define configTOTAL_HEAP_SIZE						( ( size_t ) ( 60 * 1024 ) )
#define configTICK_RATE_HZ							( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES						( 5 )
#define configMINIMAL_STACK_SIZE					( ( unsigned short ) 300 )
#define configMAX_TASK_NAME_LEN						( 30 )

#define configIDLE_SHOULD_YIELD						1
#define configQUEUE_REGISTRY_SIZE					10
#define configCHECK_FOR_STACK_OVERFLOW				2

#define configUSE_IDLE_HOOK							0
#define configUSE_TICK_HOOK							0
#define configUSE_MALLOC_FAILED_HOOK       	 		0
#define configUSE_DAEMON_TASK_STARTUP_HOOK  	    0

#define configRECORD_STACK_HIGH_ADDRESS				1
#define configGENERATE_RUN_TIME_STATS				1
#define configUSE_TRACE_FACILITY					1
#define configUSE_STATS_FORMATTING_FUNCTIONS		1

#define configSUPPORT_STATIC_ALLOCATION				1
#define configSUPPORT_DYNAMIC_ALLOCATION			1

#define configUSE_MUTEXES							1
#define configUSE_RECURSIVE_MUTEXES					1
#define configUSE_APPLICATION_TASK_TAG				0
#define configUSE_COUNTING_SEMAPHORES				1

#define configUSE_16_BIT_TICKS						0

#define configUSE_CO_ROUTINES 						0
#define configMAX_CO_ROUTINE_PRIORITIES 			2

#define configUSE_TIMERS							1
#define configTIMER_TASK_PRIORITY					2
#define configTIMER_QUEUE_LENGTH					10
#define configTIMER_TASK_STACK_DEPTH				800

#define INCLUDE_vTaskPrioritySet					1
#define INCLUDE_uxTaskPriorityGet					1
#define INCLUDE_vTaskDelete							1
#define INCLUDE_vTaskCleanUpResources				1
#define INCLUDE_vTaskSuspend						1
#define INCLUDE_vTaskDelayUntil						1
#define INCLUDE_vTaskDelay							1

#define configPRIO_BITS       							4
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			0xf
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5


#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configASSERT( x ) if( ( x ) == 0 )		{ taskDISABLE_INTERRUPTS(); for( ;; ); }

#define vPortSVCHandler				SVC_Handler
#define xPortPendSVHandler			PendSV_Handler

#ifdef configGENERATE_RUN_TIME_STATS
extern void				vConfigureTimerForRunTimeStats		( void );
extern uint32_t			vGetRunTimeCounterValue				( void );
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()			vConfigureTimerForRunTimeStats()
#define portGET_RUN_TIME_COUNTER_VALUE()					vGetRunTimeCounterValue();
#endif

#define assertParam(expr) ((expr) ? (void)0U : assertFailed((uint8_t *)__FILE__, __LINE__))
void assertFailed ( uint8_t* file, uint32_t line );

#ifdef __cplusplus
}
#endif

#endif
