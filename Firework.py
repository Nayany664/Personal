#error 1: whoever made this function is American cause you have to say color not colour =/
#error 2: keeps going even if tab closed, fix with pass line


import turtle
import random

screen = turtle.Screen()
screen.bgcolor("black") #background colour
screen.title("Fireworks Display") #title
screen.setup(width=1.0, height=1.0) #attempt fullscreen
screen.tracer(0) #turn off automatic screen updates for smooth animation

firework = turtle.Turtle()
firework.hideturtle()
firework.speed(0)
firework.penup()

def draw_firework(x, y, color, size, particles): #1 firework
    "Draws a single firework burst at (x, y) with specified color, size, and particle count."
    for _ in range(particles):
        firework.goto(x, y)  #start from centre of firework
        firework.color(color) #any colour
        firework.pendown()
        
        angle = random.uniform(0, 360) #go randonly
        distance = random.uniform(size * 0.5, size) #doesn't have to be right next to the old firework
        firework.setheading(angle)
        firework.forward(distance)
        firework.penup()


def fireworks_show(): #do multiple fireworks not just 1
    "Animates fireworks continuously until window is closed."
    try:
        while True:
            x = random.randint(-300, 300) #random position
            y = random.randint(0, 250)
            
            color = random.choice(["red", "yellow", "blue", "green", "orange", "purple", "white", "cyan", "magenta"]) #colour options
            size = random.randint(30, 80)
            particles = random.randint(20, 40)
            
            draw_firework(x, y, color, size, particles)
            screen.update()  # Refresh the screen
            
            # Randomly clear to simulate fade
            if random.random() < 0.2:
                firework.clear()
            
            screen.ontimer(lambda: None, 300) #non blocking delay
    except turtle.Terminator:
        pass #exit if window closed

fireworks_show() #start
