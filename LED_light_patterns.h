 /*red1, green, red1 + green, yellow, red1 + yellow, green + yellow, red1 + green + yellow,
 red2, red1 + red2, green + red2, red1 + green + red2, yellow + red2, red1 + yellow + red2,
 red1 + green + yellow + red2 */

#include "mbed.h"
#include "C12832_lcd.h"

C12832_LCD lcd; //C12832 lcd(p5, p7, p6, p8, p11);

DigitalOut myLED1(p8); //DIP6 red pin 8
DigitalOut myLED2(p9); //DIP5 green pin 9
DigitalOut myLED3(p10); //DIP28 yellow pin 10
DigitalOut myLED4(p11); //DIP27 red2 pin 11

void timer2_init(void)
{
    LPC_SC->PCONP |= (0x01 << 22);  // Power Timer2

    //PCLK = CCLK - setting peripheral clock
    LPC_SC->PCLKSEL1 &= ~(0x03 << 12); //clear bits 13:12
    LPC_SC->PCLKSEL1 |=  (0x01 << 12); //set CPU clock

    LPC_TIM2->TCR = 0x02; //reset
    LPC_TIM2->CTCR = 0x00; //timer mode

    uint32_t pclk = SystemCoreClock; //get real clock
    LPC_TIM2->PR = pclk - 1; //TC increments every 1 second

    LPC_TIM2->MR1 = 15; //reset every 15 seconds
    LPC_TIM2->MCR = (0x01 << 4); //reset on MR1

    LPC_TIM2->TC = 0; //clear timer counter
    LPC_TIM2->PC = 0; //clear prescale counter

    LPC_TIM2->TCR = 0x01; //start timer2
}

int main()
{
    timer2_init(); //initialise timer2

    while (1) //while connected to power
    {
        uint32_t tc = LPC_TIM2->TC & 0xF;  // lower 4 bits

        myLED1 = (tc >> 0) & 1; //bit 0 => LED1 (red1)
        myLED2 = (tc >> 1) & 1; //bit 1 => LED2 (green)
        myLED3 = (tc >> 2) & 1; //bit 2 => LED3 (yellow)
        myLED4 = (tc >> 3) & 1; //bit 3  => LED4 (red2)

        wait_ms(50); //just to run more smoothly so 50milliseconds wait
    }
}
