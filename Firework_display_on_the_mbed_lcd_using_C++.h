//most similar to java code but has library like python

#include "mbed.h"
#include "C12832.h"

#include <cmath>
#include <cstdlib>

C12832 lcd(p5, p7, p6, p8, p11);

void drawFirework(int x, int y, int size, int particles) //just 1 firework
{
    for(int i = 0; i < particles; i++)
    {
        float angle = (rand() % 360) * 3.14159 / 180; //random angle
        int distance = rand() % size + (size / 2); //random distance

        int x2 = x + cos(angle) * distance; //end point of spark
        int y2 = y + sin(angle) * distance;

        if(x2 >= 0 && x2 < WIDTH && y2 >= 0 && y2 < HEIGHT) //keep drawing if inside lcd screen measurements
        {
            lcd.line(x, y, x2, y2, 1);
        }
    }
}

int main()
{
    while(true) //while connected
    {
        int x = rand() % WIDTH; //start at random position
        int y = rand() % (HEIGHT / 2); //the top half of screen

        int size = rand() % 10 + 5; //random size
        int particles = rand() % 10 + 8; //random num of sparks

        drawFirework(x, y, size, particles); //draw the fireworks

        thread_sleep_for(300); pause for 300ms (0.3s)

        if(rand() % 5 == 0) //clear screen to simulate fading
        {
            lcd.cls();
        }
    }
}
