#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "registers_operations_macros.h" 			// Macros header file


void PortB_Init(void);
void PortF_Init(void);

void SysTime (void);		

static void vTask1( void *pvParameters );
static void vTask2( void *pvParameters );
static void vTask3( void *pvParameters );

TaskHandle_t xTask2Handle;
TaskHandle_t xTask3Handle;

int main(void){  
  
  PortB_Init();         // Call initialization of portB
  PortF_Init();		  		// Call initialization of portF
	
  SysTime();						// Call systick timer  
	
	xTaskCreate( vTask1, (const portCHAR *)"Normal Mode", configMINIMAL_STACK_SIZE, NULL, 2, NULL );						   		// Task 1 for nomal mode
	xTaskCreate( vTask2, (const portCHAR *)"Pedestrian Mode", configMINIMAL_STACK_SIZE, NULL, 1,  &xTask2Handle);			// Task 2 for pedestrian mode
	xTaskCreate( vTask3, (const portCHAR *)"Train Mode", configMINIMAL_STACK_SIZE, NULL, 1, &xTask3Handle); 			  	// Task 3 for train mode
	
	vTaskStartScheduler();
}


												/*																TASK 1 (NORMAL MODE)																								*/


static void vTask1( void *pvParameters )
{

	for( ;; )
	{
			
	DATA_PORTB &= (~(0x14));					// Turn off E-W green lights	   
  DATA_PORTB |=  0x28;       				// Turn on N-S green lights
		
		for(int i = 0 ; i<5 ; i++)
		{										
		 while ((NVIC_ST_CTRL_R & 0x10000) == 0)							// Start systick
			 { 			
					if(((DATA_PORTB & 0x01)) == 1 )								// Check if Pedestrian button  is pressed
								{
									vTaskPrioritySet(xTask2Handle,3);		// make pedestrian mode high priority and perform task 2
								}
								
				  if((DATA_PORTB & 0x80) ==0x80)						// check if train switch 1 is pressed
								{	
									vTaskPrioritySet(xTask3Handle,4);   // make train mode high priority and perform task 3
								}
		 
				}
		}
			
					

		
		
		DATA_PORTB  &= (~(0x28));							 // Turn on N-S green lights
		DATA_PORTB  |= 0x14;      		 		    //  Turn on E-W green lights	   
		
		for(int i = 0 ; i<2 ; i++)
		{
		    while ((NVIC_ST_CTRL_R & 0x10000) == 0)						// Start systick
					{
								if(((DATA_PORTB & 0x01)) ==1 )						// Check if Pedetrian button  is pressed
								{
									vTaskPrioritySet(xTask2Handle,3);				// make pedestrian mode high priority and perform task 2
								}
								if(((DATA_PORTB & 0x80)) ==0x80)					// check if train switch 1 is pressed
								{
									vTaskPrioritySet(xTask3Handle,4);				// make train mode high priority and perform task 3
								}
							
			  	}
		}
				
				
		}
	
}

												/*																TASK 2 (PEDESTRIAN MODE)																											*/



static void vTask2( void *pvParameters )
{
	

	for( ;; )
	{

		DATA_PORTB |= 0x0C;						// Turn on red lights of normal mode
		DATA_PORTB &= (~(0x30));			// Turn off green lights of normal mode
		
		
		for(int i = 0 ; i<10 ; i++)
		{
				while ((NVIC_ST_CTRL_R & 0x10000) == 0)							// Start systick
				{
						
					 if((DATA_PORTB & 0x80) ==0x80)									 // check if train switch 1 is pressed
								{		
										vTaskPrioritySet(xTask3Handle,4);  		// make train mode high priority and perform task 3
								}
				}
		}
		
		vTaskPrioritySet(NULL,1);											// Return task 2 priority to 1 and return to make normal priority who has higher priority

	}
	
	
	
}


												/*																				TASK 3 (TRAIN MODE)																													*/

static void vTask3( void *pvParameters )
{
	
	for( ;; )
	{
		
		vTaskPrioritySet(xTask2Handle,1);								// Return task 2 to its priority
		
	 if((DATA_PORTB & 0x80) ==0x80)  									 // check if train switch 1 is pressed
		{ 
		DATA_PORTB |= 0x4C;										 					// Turn on all red lights
		DATA_PORTF |= 0x04;														  // Turn on buzzer 
		DATA_PORTB &= (~(0x30));												// Turn off all green lights
			
					
			for(int i = 0 ; i<30 ; i++)										// Begin 30 sec safety
			{
				while ((NVIC_ST_CTRL_R & 0x10000) == 0)	;		// Start systick	
			}
		}
		
		if((DATA_PORTF & 0x08) == 0x08)									// Check if switch 2 of the train is pressed
		{	

				DATA_PORTF &= (~(0x04));										// Turn off buzzer
				DATA_PORTB &= (~(0x4C));										// Turn off railway red light and 2 other red light
				vTaskPrioritySet(NULL,1);										// Return task3 priority to 1 and switch to normal mode
		}

	}

}


void PortB_Init(void)
	{ 
	
  ENABLE_PORTB_CLOCK; 									// activate clock for port B
	ENABLE_PORTB_LOCK; 										// open PortB Lock
	CHECK_REGISTER_PORTB |= 0x1F;					// Check register for port B
	DIGITAL_ENABLE_PORTB |= 0xFD;   	 	  // digital enable I/O on B0 and B2- B5
  DIRECTION_PORTB |= 0x7C; 					    // output B2 & B3 red lights and  B4 & B5 green lights
	DIRECTION_PORTB &= (~(0x81)); 				// make B0 input for pedestrian button and b7 input for switch 1 of train mode
  PULL_DOWN_PORTB |= 0x81;							// Pull down resistor for b0 button and b7 switch 1
	      
	}





void PortF_Init(void)
	{ 
	
  ENABLE_PORTF_CLOCK; 						  	// activate clock for portF
	ENABLE_PORTF_LOCK;									// open PortF Lock
	CHECK_REGISTER_PORTF |= 0x1F;				// Check register for port F
	DIGITAL_ENABLE_PORTF |= 0x0C;    	  // digital enable I/O on F2 & F3
  DIRECTION_PORTF |= 0x04; 				    // output F2 for buzzer
	DIRECTION_PORTF &= (~(0x08)); 			// input for F3 for switch 2 of the train
  PULL_DOWN_PORTB |= 0x08;						// Pull down resistor for F3 switch 2
     
	}

void SysTime (void)
	{
	
	NVIC_ST_RELOAD_R = 0xF423FF;  		 // reload value for 1 sec
  NVIC_ST_CTRL_R = 5;         			// enable control, no interrupt and use system clock 
	
	}

	