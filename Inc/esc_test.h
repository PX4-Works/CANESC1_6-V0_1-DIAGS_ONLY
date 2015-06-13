#define TIC_MS 1
int test(void);

void msDelay( int ms );
//#define USE_PX4FMU
#if defined(USE_PX4FMU)
#define GPIO_TIM1_PORT GPIOE
#define GPIO_TIM1_CH1  GPIO_TIM1_PORT, GPIO_PIN_14
#define GPIO_TIM1_CH2  GPIO_TIM1_PORT, GPIO_PIN_13
#define GPIO_TIM1_CH3  GPIO_TIM1_PORT, GPIO_PIN_11

#define GPIO_LED_PORT GPIOE
#define GPIO_LED_RED   GPIO_LED_PORT, GPIO_PIN_11
#define GPIO_LED_GREEN GPIO_LED_PORT, GPIO_PIN_13
#define GPIO_LED_BLUE  GPIO_LED_PORT, GPIO_PIN_14

#define GPIO_RPM_PORT GPIOE
#define GPIO_RPM      GPIO_RPM_PORT, GPIO_PIN_9

#else

/* For Diag we will walk a 1 on anything that can be an output  Even though it my be an
 * Input to the **board** i.e GPIO_USART3_RX, RPM will however be used as in input
 * When pulled low will extend the time on and off by 10 X
 */
                                                                        /*  USE IN DIAGS */
#define GPIO_PWRGD_PORT		GPIOC
#define GPIO_PWRGD		GPIO_PWRGD_PORT, GPIO_PIN_13		 /* Pin 2  Input */

#define GPIO_OCTW_PORT		GPIOC
#define GPIO_OCTW		GPIO_OCTW_PORT, GPIO_PIN_14		 /* Pin 3  Input */

#define GPIO_FAULT_PORT		GPIOC
#define GPIO_FAULT		GPIO_FAULT_PORT, GPIO_PIN_15		 /* Pin 4  Input */

#define GPIO_RC_PWM_PORT	GPIOA
#define GPIO_RC_PWM		GPIO_RC_PWM_PORT, GPIO_PIN_3		 /* Pin 17  Input */

#define GPIO_OC_ADJ_PORT	GPIOA
#define GPIO_OC_ADJ		GPIO_OC_ADJ_PORT, GPIO_PIN_4		 /* Pin 20 Output */

#define GPIO_EN_GATE_PORT	GPIOA
#define GPIO_EN_GATE		GPIO_EN_GATE_PORT, GPIO_PIN_5		 /* Pin 21 Output */

#define GPIO_DC_CAL_PORT	GPIOA
#define GPIO_DC_CAL		GPIO_DC_CAL_PORT, GPIO_PIN_6		 /* Pin 22  Output */

#define GPIO_TIM1_CH1N_PORT	GPIOA
#define GPIO_TIM1_CH1N		GPIO_TIM1_CH1N_PORT, GPIO_PIN_7		 /* Pin 23  Output*/

#define GPIO_USART3_RX_PORT	GPIOC
#define GPIO_USART3_RX		GPIO_USART3_RX_PORT, GPIO_PIN_5		 /* Pin 25  Output */

#define GPIO_TIM1_CH2N_PORT	GPIOB
#define GPIO_TIM1_CH2N		GPIO_TIM1_CH2N_PORT, GPIO_PIN_0		 /* Pin 26  Output */

#define GPIO_TIM1_CH3N_PORT	GPIOB
#define GPIO_TIM1_CH3N		GPIO_TIM1_CH3N_PORT, GPIO_PIN_1		 /* Pin 27 Output */

#define GPIO_GAIN_PORT		GPIOB
#define GPIO_GAIN		GPIO_GAIN_PORT, GPIO_PIN_2		 /* Pin 28 Output */

#define GPIO_USART3_TX_PORT	GPIOB
#define GPIO_USART3_TX		GPIO_USART3_TX_PORT, GPIO_PIN_10	/* Pin 29 Output */

#define GPIO_RPM_PORT		GPIOC
#define GPIO_RPM		GPIO_RPM_PORT, GPIO_PIN_6		 /* Pin 37 Input M */

#define GPIO_LED_RED_PORT	GPIOC
#define GPIO_LED_RED		GPIO_LED_RED_PORT, GPIO_PIN_7		 /* Pin 38 Output */

#define GPIO_LED_GREEN_PORT	GPIOC
#define GPIO_LED_GREEN		GPIO_LED_GREEN_PORT, GPIO_PIN_8		 /* Pin 39 Output */

#define GPIO_LED_BLUE_PORT	GPIOC
#define GPIO_LED_BLUE		GPIO_LED_BLUE_PORT, GPIO_PIN_9		 /* Pin 40 Output */

#define GPIO_TIM1_CH1_PORT	GPIOA
#define GPIO_TIM1_CH1		GPIO_TIM1_CH1_PORT, GPIO_PIN_8		 /* Pin 41 Output */

#define GPIO_TIM1_CH2_PORT	GPIOA
#define GPIO_TIM1_CH2		GPIO_TIM1_CH2_PORT, GPIO_PIN_9		 /* Pin 42 Output */

#define GPIO_TIM1_CH3_PORT	GPIOA
#define GPIO_TIM1_CH3		GPIO_TIM1_CH3_PORT, GPIO_PIN_10		 /* Pin 43 Output */

#define GPIO_USB_OTG_FS_DM_PORT	GPIOA
#define GPIO_USB_OTG_FS_DM	GPIO_USB_OTG_FS_DM_PORT, GPIO_PIN_11     /* Pin 44 Output */

#define GPIO_USB_OTG_FS_DP_PORT	GPIOA
#define GPIO_USB_OTG_FS_DP	GPIO_USB_OTG_FS_DP_PORT, GPIO_PIN_12     /* Pin 45 Output */

#define GPIO_HWID0_PORT		GPIOC
#define GPIO_HWID0		GPIO_HWID0_PORT, GPIO_PIN_10		 /* Pin 51 Input */
#define GPIO_HWID1_PORT		GPIOC
#define GPIO_HWID1		GPIO_HWID1_PORT, GPIO_PIN_11		 /* Pin 52 Input */

#define GPIO_TEST4_PORT		GPIOC
#define GPIO_TEST4		GPIO_TEST4_PORT, GPIO_PIN_12		 /* Pin 53 Output */
#define GPIO_TEST1_PORT		GPIOD
#define GPIO_TEST1		GPIO_TEST1_PORT, GPIO_PIN_2		 /* Pin 54 Output */
#define GPIO_TEST2_PORT		GPIOB
#define GPIO_TEST2		GPIO_TEST2_PORT, GPIO_PIN_3		 /* Pin 55 Output */
#define GPIO_TEST3_PORT		GPIOB
#define GPIO_TEST3		GPIO_TEST3_PORT, GPIO_PIN_4		 /* Pin 56 Output */
#endif

#define PIN(port, pin) pin
#define PORT(port, pin) port