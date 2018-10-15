#include "mbed.h"
DigitalIn button(PTA1, PullUp);
PwmOut led(PTC1);

int main() {
    led.period(0.01);
    led = 0.00; 
	int i = 1;
    while(1) {
        if(button == 0){
            led = led + 0.20 * i;
			if(led == 1.00 || led == 0){
                i *= -1;
            }
            while(button == 0)
                led = led;
            wait(0.2); 
        }
    }
}
