#define TIC_MS 1
int test(void);

void msDelay( int ms );
#define USE_PX4FMU
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
#define GPIO_TIM1_PORT GPIOA
#define GPIO_TIM1_CH1 GPIO_TIM1_PORT, GPIO_PIN_8
#define GPIO_TIM1_CH2 GPIO_TIM1_PORT, GPIO_PIN_9
#define GPIO_TIM1_CH3 GPIO_TIM1_PORT, GPIO_PIN_10

#define GPIO_LED_PORT GPIOC
#define GPIO_LED_RED   GPIO_LED_PORT, GPIO_PIN_7
#define GPIO_LED_GREEN GPIO_LED_PORT, GPIO_PIN_8
#define GPIO_LED_BLUE  GPIO_LED_PORT, GPIO_PIN_9

#define GPIO_RPM_PORT GPIOC
#define GPIO_RPM      GPIO_RPM_PORT, GPIO_PIN_6

#endif

#define PIN(port, pin) pin
#define PORT(port, pin) port