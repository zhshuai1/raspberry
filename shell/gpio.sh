#!/bin/bash

show(){
	gpio readall;
	pinout;
}
blink(){
	interval=$1;
	gpio -g mode 17 out; # -g bcm pin number; else wPi pin number
	while :
	do
		gpio -g write 17 1;
		sleep $interval;
		gpio -g write 17 0;
		sleep $interval;
	done
}

pwm_blink(){
	# only work on pin 32(-g 12; 26)/33(-g 13; 23)/...
	# all channels share same clock division, range;
	PIN=23;
	gpio mode $PIN pwm #should set pwm first
	gpio pwm-ms;
	gpio pwmc 1920; #clock division
	gpio pwmr 200  #clock num each period
	gpio pwm $PIN 15 #high voltage each period
	sleep 10
}
#----------
#blink 0.9

#----------
pwm_blink
