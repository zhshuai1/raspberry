#include<wiringPi.h>
#include<stdio.h>

#define PWM_PIN 13
int test_pwm(){
	int ret;
	if((ret = wiringPiSetupGpio())==-1){
		printf("Failed to set up gpio. code: %d\n", ret);
		return -1;
	}
	//wiringPiSetup();
	pinMode(PWM_PIN, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(192);
	pwmSetRange(2000);
	pwmWrite(PWM_PIN,150);
	return 0;
}
#define Pin0 0
int blink(){
	wiringPiSetup();
    printf("Hello, world!\n");
    pinMode(Pin0, OUTPUT);
    for(;;){
        digitalWrite(Pin0, HIGH);
        delay(1);
        digitalWrite(Pin0, LOW);
        delay(19);
    }
    return 0;
}

int test_pin_mapping(){
	wiringPiSetupGpio();
	wiringPiSetup();
	printf("wPi: %d, gpio: %d\n", 1, wpiPinToGpio(1));
	printf("phy: %d, gpio: %d\n", 12, physPinToGpio(12));
	return 0;
}
int main(void){
	printf("Hello, world!\n");
	//test_pin_mapping();
	test_pwm();
    return 0;
}
