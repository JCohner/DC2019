#Write your code here :-)
import serial
import string
import pygame
import pgzero

WIDTH = 500
HEIGHT = 250
TITLE = "Fading Green!"
c = 0
x = [0]*100 # list of size 100 initialized to 0
analog = 0
bump_state = 'none'

def draw():
    screen.fill((0, 0, 0))
    #plot(x,10,HEIGHT/2,0,0,255) # data, xpos, ypos, red, green, blue
    screen.draw.text(str(analog), (250, 20), color="orange", fontsize=80) # top left to bottom right, ypos is inverted

def plot(data,xpos,ypos,r,g,b):
    ypos = HEIGHT - ypos # flip the y axis
    for i in range(1, len(data)):
        screen.draw.line((xpos+i,ypos),(xpos+i,ypos-x[i]),(r,g,b))

def update(dt):
    global c, HEIGHT
    global x, analog
    c = (c + 1) % 256

    while ser.in_waiting: #if theres bytes on the serial port that are available
        line = ser.read_until().strip() #strip() removes the \r\n #reads the line till \r\n then removes the new line return chars
        values = line.decode('ascii').split(' ')

        print("received this on BT Serial " + str(values))

        if(values[0] == 'x'):
            x[int(values[1])] = int(values[2])
            print(x)
        if(values[0] == 'a'):
            analog = int(values[1])

def on_mouse_down(button, pos):
    print("Mouse button", button, "down at", pos)
    ser.write(b'o')

def on_mouse_up(button, pos):
    print("Mouse button", button, "up at", pos)
    ser.write(b'p')
    ser.write(b'a')

def on_key_down(key): #key names are saved in CAPS
    if key.name == 'X':
        ser.write(b'd 255 255')
        print("Sent x")
    if key.name == 'C':
        ser.write(b'd 128 128')
        print("Sent c")
    if key.name == 'D':
        ser.write(b'd 0 0')
        print("Sent d")
    if key.name == 'R':
        ser.write(b'a')
        print("Sent r")
    if key.name == 'P':
        ser.write(b'dra')
        print("reversing motor a")
    if key.name == 'L':
        ser.write(b'drb')
        print("reversing motor b")
ser = serial.Serial('COM25',9600)
#ser_controller = serial.Serial('COM16',9600)