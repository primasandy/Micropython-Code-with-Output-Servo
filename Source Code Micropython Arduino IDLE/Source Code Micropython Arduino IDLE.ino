#include <XPowersLib.h>
#include <XPowersLibInterface.hpp>
#include <XPowersParams.hpp>

import machine
import time
import dht


# Menginstal Board SERVO di pin 12
servo = machine.PWM(machine.Pin(12), freq=50)
servo.duty(77) # Set the initial position of the servo

# Menginstal Board LDR di pin 34
light_sensor = machine.ADC(machine.Pin(34))

# Menginstal Board DHT di pin 18
d = dht.DHT22(machine.Pin(4))

while True:
    # Membaca Value dari sensor Ldr
    light_value = light_sensor.read()
    print("Light value:", light_value)

    # Membaca Value dari sensor DHT
    d.measure() 
    temp = d.temperature()
    hum = d.humidity()
   
    print("Temperature:" ,temp,"C")
    print("Humidity   :" ,hum,"%")
    time.sleep(1)
    
    # Mengontrol Servo dari sensor ldr dan juga sensor DHT
    if light_value >= 1000 and temp <= 30 and hum > 1:
        servo.duty(120)
       
    else:
        servo.duty(75)