#include "mbed.h"



#define A 440
#define a 440
#define B 493.883
#define b 494
#define c 262
#define C 277.182
#define D 311.127
#define d 294
#define E 329.628
#define e 330
#define f 349
#define F 369.994
#define g 392
#define G 415.305

PwmOut buzzer(PTC1) ;

int main() {
    while (1) { 

        // E4
        wait(0.6);
        buzzer.period(1.0/E);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // G4#
        wait(0.6);
        buzzer.period(1.0/g);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // G4#
        wait(0.6);
        buzzer.period(1.0/g);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // G4#
        wait(0.6);
        buzzer.period(1.0/g);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // f4#
        wait(0.6);
        buzzer.period(1.0/F);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // e4
        wait(0.6);
        buzzer.period(1.0/e);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // b4
        wait(0.6);
        buzzer.period(1.0/b);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // b4
        wait(0.6);
        buzzer.period(1.0/b);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // a4
        wait(0.6);
        buzzer.period(1.0/b);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // G4#
        wait(0.6);
        buzzer.period(1.0/g);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // G4#
        wait(0.6);
        buzzer.period(1.0/g);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // G4#
        wait(0.6);
        buzzer.period(1.0/g);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // f4#
        wait(0.6);
        buzzer.period(1.0/F);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // e4
        wait(0.6);
        buzzer.period(1.0/e);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // b4
        wait(0.6);
        buzzer.period(1.0/b);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // b4
        wait(0.6);
        buzzer.period(1.0/b);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

        // a4
        wait(0.6);
        buzzer.period(1.0/b);
        buzzer =0.5;
        wait(0.3);
        buzzer=0.0; 
        wait(0.05);

    wait(5);
    }
}