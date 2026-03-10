void init_TC2 (void) 
{
   LPC_SC->PCONP |= (0x01 << 22); // (Bit 22) Power up Timer 2
   LPC_SC->PCLKSEL1 |= (0x01 << 12) ; // (Bits 13:12) Timer 2 clock rate is 96 MHz
   LPC_TIM2->TCR |= (0x01); // (Bit 0) Enable Timer-counter

   LPC_TIM2->PR = 96000000 - 1; // Timer-Counter effective clock period = 1 sec.   
   LPC_TIM2->MR1 = 15; // Match after 15 seconds
   // 96000000/96MHz = 1

   LPC_TIM2->MCR |= (0x01 << 4); // (Bit 1) Timer-Counter reset on MR3 Match
   //need 1 under 4 so [11 10 9 8  7 6 5 4  3 2 1 0] if 1 originally under 0, need to shift by 4 to be under 4
   LPC_TIM2->TC = (0x00); //Initialise Timer-Counter
}

void LED_binary (int number)
{
    //port 0, byte 1
   LPC_GPIO0->FIOPIN1 |= ( number >> 0) & 1 ;
   LPC_GPIO0->FIOPIN1 |= ( number >> 1) & 1 ;
   LPC_GPIO0->FIOPIN1 |= ( number >> 2) & 1 ;
   LPC_GPIO0->FIOPIN1 |= ( number >> 3) & 1 ;
}

int main()
{
    //port 0, byte 1
    LPC_GPIO0->FIODIR1 |= 0X01 ; //led 6 is num 34
    LPC_GPIO0->FIODIR1 |= 0X01 << 1; //led 5 is num 35
    LPC_GPIO0->FIODIR1 |= 0X01 << 2 ; //led 28 is num 34
    LPC_GPIO0->FIODIR1 |= 0X01 << 3; //led 27 is num 35

   init_TC2(); // Timer 2 initialisation function
   int value = LPC_TIM2->TC ; //naming LPC_TIM2->TC
   LED_binary (value); //putting value into the LED_binary function
   lcd.cls();
   lcd.locate(0,0);
   lcd.printf("Timer 2 Monitor");

   while(1) 
   {

       lcd.locate(0,15);
       lcd.printf("Timer2: %d", LPC_TIM2->TC);
       wait(1); //include an update delay for the LCD output of 1 sec
       //myled = !myled; //diagnostic
   }
}
*/


