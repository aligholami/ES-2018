#include "mbed.h"
#include <string>

Serial pc(USBTX, USBRX);
DigitalOut cmd1Led(LED_BLUE);
DigitalOut cmd2Led(LED_RED);


string flush_buffer(string);

int main() 
{  

  char ch;  
  string BUFF_IO = "xyxy";

  pc.baud(110);

  while(1) 
  {
    cmd1Led = 1;
    cmd2Led = 1;
    if(pc.readable()){

      pc.printf("cmd1\n");
      // recvLed = 0;
      // wait(1);

   //  for (int  i = 0; i < 50; i++ ){
   //      if((ch = pc.getc()) == 13) {    // Carriage Return Input Case
   //        break;
   //      }
   //      BUFF_IO[i] = ch;
   //  }

   //  if (!BUFF_IO.compare(0, 4, "cmd1")) {
   //    cmd1Led = 0;
   //    wait(1);
   //  }
   //  else if (!BUFF_IO.compare(0, 4, "cmd2")) {
   //    cmd2Led = 0;
   //    wait(1);
   //  }


  }

  }      
 }    