from machine import Pin, ADC, PWM
from time import sleep
ANALOG_PIN = 4
ain = ADC(Pin(ANALOG_PIN))
ain.atten(ADC.ATTN_11DB)

PWM_FREQ = 5000
RED_PIN = 41
YELLOW_PIN = 40
GREEN_PIN = 39

red = PWM(Pin(RED_PIN))
yellow = PWM(Pin(YELLOW_PIN))
green = PWM(Pin(GREEN_PIN))

red.init(freq=PWM_FREQ)
yellow.init(freq=PWM_FREQ)
green.init(freq=PWM_FREQ)

while True:
    if 2525 < ain.read() < 3025:
        green.duty(1023)
        yellow.duty(0)
        red.duty(0)
    elif  2025 < ain.read() < 2525:
        green.duty(512)
        yellow.duty(0)
        red.duty(0)
    elif  1525 < ain.read() < 2025:
        red.duty(0)
        yellow.duty(1023)
        green.duty(0)
    elif  1025 < ain.read() < 1525:
        red.duty(0)
        yellow.duty(512)
        green.duty(0)
    elif  525 < ain.read() < 1025:
        green.duty(0)
        yellow.duty(0)
        red.duty(1023)
    elif  0 <= ain.read() < 525:
        green.duty(0)
        yellow.duty(0)
        red.duty(512)
﻿
sdsd
alpacathalhalom
