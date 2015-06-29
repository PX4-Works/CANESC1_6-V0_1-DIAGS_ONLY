
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

    io_config_in(GPIO_PWRGD);
    io_config_in(GPIO_OCTW);
    io_config_in(GPIO_FAULT);
    io_config_out(GPIO_RC_PWM);
    io_config_out(GPIO_OC_ADJ);
    io_config_out(GPIO_EN_GATE);
    io_config_out(GPIO_DC_CAL);
    io_config_out(GPIO_TIM1_CH1N);
    io_config_out(GPIO_USART3_RX);
    io_config_out(GPIO_TIM1_CH2N);
    io_config_out(GPIO_TIM1_CH3N);
    io_config_out(GPIO_GAIN);
    io_config_out(GPIO_USART3_TX);
    io_config_out(GPIO_RPM);
    io_config_out(GPIO_LED_RED);
    io_config_out(GPIO_LED_GREEN);
    io_config_out(GPIO_LED_BLUE);
    io_config_out(GPIO_TIM1_CH1);
    io_config_out(GPIO_TIM1_CH2);
    io_config_out(GPIO_TIM1_CH3);
    io_config_out(GPIO_USB_OTG_FS_DM);
    io_config_out(GPIO_USB_OTG_FS_DP);
    io_config_in(GPIO_HWID0);
    io_config_in(GPIO_HWID1);
    io_config_out(GPIO_TEST4);
    io_config_out(GPIO_TEST1);
    io_config_out(GPIO_TEST2);
    io_config_out(GPIO_TEST3);

 
  while(1) {

   io_toggle(10, GPIO_RC_PWM); // 2 Ms Sync

   int id0 = (0 == io_read(GPIO_HWID0)) ? 5 : 15;
   io_toggle(id0, GPIO_RC_PWM); // S/B 5 MS

   int id1 = (0 == io_read(GPIO_HWID1)) ? 5 : 15;
   io_toggle(id1, GPIO_RC_PWM); //  S/B 5 MS

   int m = (io_read(GPIO_RPM) != 0) ? 10 : 1;

    io_toggle(m*100, GPIO_RC_PWM);
    io_toggle(m*100, GPIO_OC_ADJ);
    io_toggle(m*100, GPIO_EN_GATE);
    io_toggle(m*100, GPIO_DC_CAL);
    io_toggle(m*100, GPIO_TIM1_CH1N);
    io_toggle(m*100, GPIO_USART3_RX);
    io_toggle(m*100, GPIO_TIM1_CH2N);
    io_toggle(m*100, GPIO_TIM1_CH3N);
    io_toggle(m*100, GPIO_GAIN);
    io_toggle(m*100, GPIO_USART3_TX);
    io_toggle(m*100, GPIO_RPM);
    io_toggle(m*1000, GPIO_LED_RED);
    io_toggle(m*1000, GPIO_LED_GREEN);
    io_toggle(m*1000, GPIO_LED_BLUE);
    io_toggle(m*100, GPIO_TIM1_CH1);
    io_toggle(m*100, GPIO_TIM1_CH2);
    io_toggle(m*100, GPIO_TIM1_CH3);
    io_toggle(m*100, GPIO_USB_OTG_FS_DM);
    io_toggle(m*100, GPIO_USB_OTG_FS_DP);
    io_toggle(m*100, GPIO_TEST4);
    io_toggle(m*100, GPIO_TEST1);
    io_toggle(m*100, GPIO_TEST2);
    io_toggle(m*100, GPIO_TEST3);  
  }
}


