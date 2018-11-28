#include "mbed.h"
#include <string>

#define A 440
#define a 439
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

PwmOut buzzer(PTB2);
Serial pc(USBTX, USBRX);
AnalogIn LM35(PTC2);
DigitalOut led_1(LED1);
InterruptIn interrupter_1(PTA5);
InterruptIn interrupter_2(PTD0);
Timer timer_isr1;
Timer timer_isr2;

string flush_buffer(string);
double get_temprature();
int led_on();
int led_off();
void play_music();
void isr_1();
void isr_2();

int main()
{   

    NVIC_SetPriority(PORTA_IRQn, 1);
    NVIC_SetPriority(PORTD_IRQn, 0);

    interrupter_1.fall(&isr_1);
    interrupter_2.fall(&isr_2);
    char ch;  
    string BUFF_IO = "xyxy";

    while(true) {
        pc.printf("\n\rEnter your command: ");

        for (int  i = 0; i < 50; i++ ){
            if((ch = pc.getc()) == 13) {    // Carriage Return Input Case
              break;
            }
            pc.putc(ch);
            BUFF_IO[i] = ch;
        }

        // pc.printf("Input command was: %s", &BUFF_IO[0]);

        if (!BUFF_IO.compare(0, 4, "temp")) {
          double temperature = get_temprature();
          fflush(stdout);
          fflush(stdin);
          pc.printf("\n\rTemperature: %f", temperature);
          BUFF_IO = flush_buffer(BUFF_IO);
        }
        else if(!BUFF_IO.compare(0, 2, "on")) {
          fflush(stdout);
          fflush(stdin);
          pc.printf("\n\rTurned on LED.");
          led_1 = led_on();
          BUFF_IO = flush_buffer(BUFF_IO);
        }
        else if(!BUFF_IO.compare(0, 3, "off")) {
          fflush(stdout);
          fflush(stdin);
          pc.printf("\n\rTurned off LED.");
          led_1 = led_off();
          BUFF_IO = flush_buffer(BUFF_IO);
        }
        else if(!BUFF_IO.compare(0, 4, "play")) {
          fflush(stdout);
          fflush(stdin);
          pc.printf("\n\rPlaying music...");
          play_music();
          BUFF_IO = flush_buffer(BUFF_IO);
        }
        else {
          BUFF_IO = flush_buffer(BUFF_IO);
        }
    }
}

string flush_buffer(string buffer)
{
  fflush(stdin);
  fflush(stdout);
  buffer = "xyxy";
  return buffer; 
}

double get_temprature(){
  double temp;
  float avg = 0.0;
  float arr[10];

  // Convert to celcius
  for(int i=0; i<10; i++) {
    arr[i] = LM35.read();
    wait(0.05);
  }

  for(int i=0; i<5; i++) {
    avg = avg + (arr[i] / 10);
  }
  temp = avg * 3.685503686 * 100;

  return temp;
}

void play_music()
{

  // E4

  buzzer.period(1.0/E);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // f4#

  buzzer.period(1.0/F);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // e4

  buzzer.period(1.0/e);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // a4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // f4#

  buzzer.period(1.0/F);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // e4

  buzzer.period(1.0/e);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // a4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);


  // E4

  buzzer.period(1.0/E);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // f4#

  buzzer.period(1.0/F);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // e4

  buzzer.period(1.0/e);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // a4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // G4#

  buzzer.period(1.0/g);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // f4#

  buzzer.period(1.0/F);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // e4

  buzzer.period(1.0/e);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // a4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);


  // g4#

  buzzer.period(1.0/G);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // a4

  buzzer.period(1.0/a);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);



  // a4

  buzzer.period(1.0/a);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);


  // g4#

  buzzer.period(1.0/G);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);


  // f4#

  buzzer.period(1.0/F);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);


  // d4#

  buzzer.period(1.0/D);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);


  // b4

  buzzer.period(1.0/b);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  // e4

  buzzer.period(1.0/e);
  buzzer =0.5;
  wait(0.2);
  buzzer=0.0; 
  wait(0.01);

  wait(5);
}


void isr_1()
{
  timer_isr1.reset();
  pc.printf("User interrupt 1 has been received."); 

  timer_isr1.start();

  // Count for 5 seconds
  while(timer_isr1.read() < 6)

  timer_isr1.stop();
}

void isr_2()
{
  timer_isr2.reset();
  pc.printf("User interrupt 2 has been received.");

  timer_isr2.start();

  // Count for 5 seconds
  while(timer_isr2.read() < 6)

  timer_isr2.stop();
}

int led_on() {return 0;}
int led_off() {return 1;}