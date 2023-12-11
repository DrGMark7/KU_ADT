from machine import Pin #Library From MicroPython
from time import sleep
 
red = Pin(41, Pin.OUT)
yellow = Pin(40, Pin.OUT)
green = Pin(39, Pin.OUT)

sw = Pin(42, Pin.IN, Pin.PULL_UP)
count = 0
Pins = [red,yellow,green]

while True:
    
    while sw.value() == 1:
        Pins[count%3 -1].value(0)
        if sw.value() == 1:
            Pins[count%3].value(1)
        sleep(0.01)

    while sw.value() == 0:
        pass
    sleep(0.01)
    
    count += 1