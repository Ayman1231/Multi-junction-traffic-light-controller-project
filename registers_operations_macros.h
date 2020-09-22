#ifndef registers_operations_marcos
#define registers_operations_marcos



/* BITWISE OPERATIONS ON REGISTER BITS */       
#define SET_BIT(REG,BIT_NUM) (REG |=(1<< BIT_NUM))                             // SET SPECIFIED BIT IN REGISTER
#define CLEAR_BIT(REG,BIT_NUM) (REG &=~(1<< BIT_NUM))                         // CLEAR SPECIFIED BIT IN REGISTER
#define TOGGLE_BIT(REG,BIT_NUM) (REG=REG^(1<<BIT_NUM))                       //TOGGLE SPECIFIED BIT IN REGISTER
#define BIT_IS_SET(REG,BIT_NUM) (REG&(1<<BIT_NUM))                        //CHECK IF A SPECIFIC BIT IS SET IN REGISTER
#define BIT_IS_CLEAR(REG,BIT_NUM) (!(REG&(1<<BIT_NUM)))                 //CHECK IF A SPECIFIC BIT IS CLEAR IN REGISTER



                        /* PORTS CLOCK ACTIVATION*/
#define ENABLE_PORTA_CLOCK SYSCTL_RCGCGPIO_R|=(1<<0)
#define ENABLE_PORTB_CLOCK SYSCTL_RCGCGPIO_R|=(1<<1)
#define ENABLE_PORTC_CLOCK SYSCTL_RCGCGPIO_R|=(1<<2)
#define ENABLE_PORTD_CLOCK SYSCTL_RCGCGPIO_R|=(1<<3)
#define ENABLE_PORTE_CLOCK SYSCTL_RCGCGPIO_R|=(1<<4)
#define ENABLE_PORTF_CLOCK SYSCTL_RCGCGPIO_R|=(1<<5)

                        /*PORTS CLOCK DEACTIVATION*/
#define DISABLE_PORTA_CLOCK SYSCTL_RCGCGPIO_R&=~(1<<0)
#define DISABLE_PORTB_CLOCK SYSCTL_RCGCGPIO_R&=~(1<<1)
#define DISABLE_PORTC_CLOCK SYSCTL_RCGCGPIO_R&=~(1<<2)
#define DISABLE_PORTD_CLOCK SYSCTL_RCGCGPIO_R&=~(1<<3)
#define DISABLE_PORTE_CLOCK SYSCTL_RCGCGPIO_R&=~(1<<4)
#define DISABLE_PORTF_CLOCK SYSCTL_RCGCGPIO_R&=~(1<<5)


			/* PORTS LOCK ACTIVATION */
#define ENABLE_PORTA_LOCK GPIO_PORTA_LOCK_R |= 0x4C4F434B
#define ENABLE_PORTB_LOCK GPIO_PORTB_LOCK_R |= 0x4C4F434B
#define ENABLE_PORTC_LOCK GPIO_PORTC_LOCK_R |= 0x4C4F434B
#define ENABLE_PORTD_LOCK GPIO_PORTD_LOCK_R |= 0x4C4F434B
#define ENABLE_PORTE_LOCK GPIO_PORTE_LOCK_R |= 0x4C4F434B
#define ENABLE_PORTF_LOCK GPIO_PORTF_LOCK_R |= 0x4C4F434B


                          /* PORTS DIRECTION */
#define DIRECTION_PORTA GPIO_PORTA_DIR_R
#define DIRECTION_PORTB GPIO_PORTB_DIR_R
#define DIRECTION_PORTC GPIO_PORTC_DIR_R
#define DIRECTION_PORTD GPIO_PORTD_DIR_R
#define DIRECTION_PORTE GPIO_PORTE_DIR_R
#define DIRECTION_PORTF GPIO_PORTF_DIR_R


                          /* PORTS DATA */
#define DATA_PORTA GPIO_PORTA_DATA_R
#define DATA_PORTB GPIO_PORTB_DATA_R
#define DATA_PORTC GPIO_PORTC_DATA_R
#define DATA_PORTD GPIO_PORTD_DATA_R
#define DATA_PORTE GPIO_PORTE_DATA_R
#define DATA_PORTF GPIO_PORTF_DATA_R

                          /* PORTS DIGTAL ENABLE */
#define DIGITAL_ENABLE_PORTA GPIO_PORTA_DEN_R
#define DIGITAL_ENABLE_PORTB GPIO_PORTB_DEN_R
#define DIGITAL_ENABLE_PORTC GPIO_PORTC_DEN_R
#define DIGITAL_ENABLE_PORTD GPIO_PORTD_DEN_R
#define DIGITAL_ENABLE_PORTE GPIO_PORTE_DEN_R
#define DIGITAL_ENABLE_PORTF GPIO_PORTF_DEN_R


 
                        /* PORTS CHECK REGISTER */
#define CHECK_REGISTER_PORTA GPIO_PORTA_CR_R
#define CHECK_REGISTER_PORTB GPIO_PORTB_CR_R
#define CHECK_REGISTER_PORTC GPIO_PORTC_CR_R
#define CHECK_REGISTER_PORTD GPIO_PORTD_CR_R
#define CHECK_REGISTER_PORTE GPIO_PORTE_CR_R
#define CHECK_REGISTER_PORTF GPIO_PORTF_CR_R



                        /* PORTS PULL UP RESISTOR */
#define PULL_UP_PORTA GPIO_PORTA_PUR_R
#define PULL_UP_PORTB GPIO_PORTB_PUR_R
#define PULL_UP_PORTC GPIO_PORTC_PUR_R
#define PULL_UP_PORTD GPIO_PORTD_PUR_R
#define PULL_UP_PORTE GPIO_PORTE_PUR_R
#define PULL_UP_PORTF GPIO_PORTF_PUR_R



                      /* PORTS PULL DOWN RESISTOR */
#define PULL_DOWN_PORTA  GPIO_PORTA_PDR_R
#define PULL_DOWN_PORTB  GPIO_PORTB_PDR_R
#define PULL_DOWN_PORTC  GPIO_PORTC_PDR_R
#define PULL_DOWN_PORTD  GPIO_PORTD_PDR_R
#define PULL_DOWN_PORTE  GPIO_PORTE_PDR_R
#define PULL_DOWN_PORTF  GPIO_PORTF_PDR_R



                      /* PORTS OPEN DRAIN OUTPUT */
#define OPEN_DRAIN_PORTA GPIO_PORTA_ODR_R
#define OPEN_DRAIN_PORTB GPIO_PORTB_ODR_R
#define OPEN_DRAIN_PORTC GPIO_PORTC_ODR_R
#define OPEN_DRAIN_PORTD GPIO_PORTD_ODR_R
#define OPEN_DRAIN_PORTE GPIO_PORTE_ODR_R
#define OPEN_DRAIN_PORTF GPIO_PORTF_ODR_R


/*PINS DEFINATIONS8*/

//PORTA
#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7

//PORTB
#define B0 0
#define B1 1
#define B2 2
#define B3 3
#define B4 4
#define B5 5
#define B6 6
#define B7 7

//PORTC
#define C0 0
#define C1 1
#define C2 2
#define C3 3
#define C4 4
#define C5 5
#define C6 6
#define C7 7

//PORTD
#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

//PORTE
#define E0 0
#define E1 1
#define E2 2
#define E3 3
#define E4 4
#define E5 5
#define E6 6
#define E7 7

//PORTF
#define F0 0
#define F1 1
#define F2 2
#define F3 3
#define F4 4
#define F5 5
#define F6 6
#define F7 7

//////////////////////////////////////////////////////////////////////////////////////////////

/* Switches on controller  */
#define SWITCH1 (1u<<0)
#define SWITCH2 (1u<<4)
#define Switch1_Pressed (GPIO_PORTF_DATA_R&SWITCH1)
#define Switch2_Pressed (GPIO_PORTF_DATA_R&SWITCH2)



#endif
