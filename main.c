#include <stdint.h>

#define RCC_BASE        0x40021000
#define RCC_APB2ENR     (volatile uint32_t)(RCC_BASE + 0x18)

#define BLINK_LED_PIN   13

int main(void){
    //enable port c clock
    RCC_APB2ENR |= (1<<4);

}