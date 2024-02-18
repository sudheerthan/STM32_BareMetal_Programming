#include <stdint.h>

#define RCC_BASE        0x40021000
#define RCC_APB2ENR     (*(volatile uint32_t * )(RCC_BASE + 0x18))

#define GPIO_PORTC_BASE 0x40011000
#define GPIO_CRH        (*(volatile uint32_t *)(GPIO_PORTC_BASE + 0x04))
#define GPIO_ODR        (*(volatile uint32_t *)(GPIO_PORTC_BASE + 0x0C))

#define RCC_IOPCEN      (1<<4)
#define LED_PIN         (1UL<<13)


int main(void){
    int i;
    //enable port c clock
    RCC_APB2ENR |= RCC_IOPCEN;

    //config pin 13 as output
    GPIO_CRH &= ~(0xF<<20);
    GPIO_CRH |= (0x2<<20);

while(1){
    
    GPIO_ODR |= LED_PIN;
    for (i = 0; i < 1500000; i++)	// Wait a bit. 
			__asm__("nop");
    GPIO_ODR &= ~LED_PIN;
    for (i = 0; i < 1500000; i++)	// Wait a bit. 
			__asm__("nop");
}
    return 0;
}
