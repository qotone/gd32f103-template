
/* Includes ------------------------------------------------------------------*/
 #include <stdio.h>

#include "gd32f10x.h"
#include "rtthread.h"







int main(void)
{
    rcu_periph_clock_enable(RCU_AF);


    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOD);
    // rcu_periph_clock_enable(RCU_DMA0);


    nvic_priority_group_set(NVIC_PRIGROUP_PRE0_SUB4);




    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_10MHZ, GPIO_PIN_8);
    gpio_bit_set(GPIOB, GPIO_PIN_8);




    while (1)
    {

        rt_thread_mdelay(1000);

        gpio_bit_reset(GPIOB, GPIO_PIN_8);
        rt_thread_mdelay(1000);
        gpio_bit_set(GPIOB, GPIO_PIN_8);
        rt_thread_mdelay(1000);
    }
    /* USER CODE END 3 */
}
