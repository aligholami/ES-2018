
#include "mbed.h"
    
DigitalOut led(PTC1);
DigitalIn button(PTA1 , PullUp);
int main() {

    led = 0;
    double LOW_PERIOD = 0.00;
    double HIGH_PERIOD = 0.01; 

    int i = 1;
    int j = -1;

    while(1) 
    {
        if (button == 0) {
            
            // Update Periods
            LOW_PERIOD += i * 0.002;
            HIGH_PERIOD += j * 0.002;

            if (LOW_PERIOD == 0.01 || LOW_PERIOD == 0) {
                // Rise and Fall Switch
                i *= -1;
                j *= -1;
            }

            while(button == 0){
                led = 0;
                wait(LOW_PERIOD);
                led = 1;
                wait(HIGH_PERIOD);
            }  
        }
    }
}