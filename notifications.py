#https://www.makeuseof.com/tag/automate-garage-door-ifttt-raspberry-pi/
import RPi.GPIO as GPIO
import time
from datetime import date
from bottle import route, run, template
import serial

today = date.today()
ser = serial.Serial('/dev/ttyUSB0', 9600)



#while (1):

if (date.today()!=today):
    led(3)
    led(4)
# Handle http requests to the root address
@route('/')
def index():
    return 'Go away.'

# Handle http requests to /garagedoor
@route('/led/:x')
def led(x):
    if x == '2':
        ser.write('2')
    if x == '1':
        ser.write('1')
    if x == '3':
        ser.write('3')
    if x == '4':
        ser.write('4')
        

run(host='172.26.168.180', port=1234)

    