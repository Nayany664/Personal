#include "mbed.h"

DigitalOut red(p5); //red LED to pin 5
DigitalOut yellow(p6); //yellow LED to pin 6
DigitalOut green(p7); //green LED to pin 7

int main() 
{
  while(1) //while working
  {
    red = 1; yellow = 0; green = 0; //red is the only colour (stop)
    wait(2.5); //show red for 2.5 seconds
    red = 1; yellow = 1; green = 0; //show both red and yellow is the only colour (get ready to go)
    wait(1.0); //show red and yellow for 1 second

    red = 0; yellow = 0; green = 1; //green is the only colour (go)
    wait(2.5); //show green for 2.5 seconds

    red = 0; yellow = 1; green = 0; //yellow is the only colour (slow down)
    wait(1.0); //show yellow for 1 second

  } //go back to red and loop until no power
