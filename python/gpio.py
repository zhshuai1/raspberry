import RPi.GPIO as GPIO
import time

Pin11=11
def led_blink():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(Pin11, GPIO.OUT)
    while(True):
        GPIO.output(Pin11, GPIO.HIGH)
        time.sleep(1)
        GPIO.output(Pin11, GPIO.LOW)
        time.sleep(1)
        
def test_pwm():
	pass
def test_spi():
	pass
def test_i2c():
	pass
def test_rx():
	pass

if __name__=='__main__':
        led_blink()


