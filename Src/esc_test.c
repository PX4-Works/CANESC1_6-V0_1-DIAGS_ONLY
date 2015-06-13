
#include "stm32f4xx.h"
#include "esc_test.h"


static volatile unsigned long _tick;

void SysTick_HandlerX(void)
{
  _tick++;
}   
unsigned long getMsTic()
{
  return _tick;
}
void msDelay( int ms )
{
    unsigned long start = getMsTic();
    while((getMsTic() - start) < ms);
}

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

GPIO_PinState io_read(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);

}

void io_toggle(long delayMs, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
    msDelay(delayMs);
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}

void io_config_out(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_InitStruct.Pin = GPIO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void io_config_in(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_InitStruct.Pin = GPIO_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}



int test(void)
{
  
    __GPIOE_CLK_ENABLE();
    __GPIOD_CLK_ENABLE();

    io_config_out(GPIO_TIM1_CH1);
    io_config_out(GPIO_TIM1_CH2);
    io_config_out(GPIO_TIM1_CH3);

    io_config_in(GPIO_RPM);


 
  while(1) {
    int m = io_read(GPIO_RPM) ? 1 : 10;
    io_toggle(m*100, GPIO_TIM1_CH1);
    io_toggle(m*100, GPIO_TIM1_CH1);
    io_toggle(m*100, GPIO_TIM1_CH1);
    io_toggle(m*100, GPIO_LED_RED);
    io_toggle(m*100, GPIO_LED_GREEN);
    io_toggle(m*100, GPIO_LED_BLUE);
  }
}


