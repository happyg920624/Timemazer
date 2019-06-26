/*    commands:   u --- APP encoder testing
                  v --- APP encoder testing with correction 
                  s --- paths data receive
                  m --- start maze
 
 */
#include <SoftwareSerial.h>
SoftwareSerial blue(14,13); //   
                            
#include <AFMotor.h>
AF_DCMotor left(4);  //AF motor shield M4 terminal
AF_DCMotor right(3); //AF motor shield M3 terminal

unsigned long milliCounter = 0;
int Lcounter=0;
int counter=0;
boolean LLastState=LOW;
boolean LastState=LOW;

int Lframes;
int frames;


byte DATA=0;
byte Lspeed = 200;
byte Ldir = 'F';
byte Rspeed = 200;
byte Rdir = 'F';
bool maze = false;  // Do maze if true
byte autocorrect;

byte pathsNo;
int delayBetweenPaths;
char P1Ldir;
byte P1Lspeed;
char P1Rdir;
byte P1Rspeed;
int P1steps;
char P2Ldir;
byte P2Lspeed;
char P2Rdir;
byte P2Rspeed;
int P2steps;
char P3Ldir;
byte P3Lspeed;
char P3Rdir;
byte P3Rspeed;
int P3steps;
char P4Ldir;
byte P4Lspeed;
char P4Rdir;
byte P4Rspeed;
int P4steps;
char P5Ldir;
byte P5Lspeed;
char P5Rdir;
byte P5Rspeed;
int P5steps;
char P6Ldir;
byte P6Lspeed;
char P6Rdir;
byte P6Rspeed;
int P6steps;
char P7Ldir;
byte P7Lspeed;
char P7Rdir;
byte P7Rspeed;
int P7steps;
char P8Ldir;
byte P8Lspeed;
char P8Rdir;
byte P8Rspeed;
int P8steps;
char P9Ldir;
byte P9Lspeed;
char P9Rdir;
byte P9Rspeed;
int P9steps;

char P10Ldir;
byte P10Lspeed;
char P10Rdir;
byte P10Rspeed;
int P10steps;

char P11Ldir;
byte P11Lspeed;
char P11Rdir;
byte P11Rspeed;
int P11steps;

char P12Ldir;
byte P12Lspeed;
char P12Rdir;
byte P12Rspeed;
int P12steps;

char P13Ldir;
byte P13Lspeed;
char P13Rdir;
byte P13Rspeed;
int P13steps;

char P14Ldir;
byte P14Lspeed;
char P14Rdir;
byte P14Rspeed;
int P14steps;

char P15Ldir;
byte P15Lspeed;
char P15Rdir;
byte P15Rspeed;
int P15steps;

char P16Ldir;
byte P16Lspeed;
char P16Rdir;
byte P16Rspeed;
int P16steps;

char P17Ldir;
byte P17Lspeed;
char P17Rdir;
byte P17Rspeed;
int P17steps;

char P18Ldir;
byte P18Lspeed;
char P18Rdir;
byte P18Rspeed;
int P18steps;

char P19Ldir;
byte P19Lspeed;
char P19Rdir;
byte P19Rspeed;
int P19steps;

char P20Ldir;
byte P20Lspeed;
char P20Rdir;
byte P20Rspeed;
int P20steps;

char P21Ldir;
byte P21Lspeed;
char P21Rdir;
byte P21Rspeed;
int P21steps;

char P22Ldir;
byte P22Lspeed;
char P22Rdir;
byte P22Rspeed;
int P22steps;

char P23Ldir;
byte P23Lspeed;
char P23Rdir;
byte P23Rspeed;
int P23steps;

char P24Ldir;
byte P24Lspeed;
char P24Rdir;
byte P24Rspeed;
int P24steps;

char P25Ldir;
byte P25Lspeed;
char P25Rdir;
byte P25Rspeed;
int P25steps;

char P26Ldir;
byte P26Lspeed;
char P26Rdir;
byte P26Rspeed;
int P26steps;

char P27Ldir;
byte P27Lspeed;
char P27Rdir;
byte P27Rspeed;
int P27steps;

char P28Ldir;
byte P28Lspeed;
char P28Rdir;
byte P28Rspeed;
int P28steps;

char P29Ldir;
byte P29Lspeed;
char P29Rdir;
byte P29Rspeed;
int P29steps;

char P30Ldir;
byte P30Lspeed;
char P30Rdir;
byte P30Rspeed;
int P30steps;

void setup()
{
  left.setSpeed(Lspeed);
  right.setSpeed(Rspeed);
  pinMode(9,OUTPUT); // buzzer
  
  blue.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  BLUE();
  if (maze == true) {MAZE();}
  
}
//================

void BLUE()
{
  
  if (blue.available() > 0)
   {
    maze = false;  // no maze
    DATA = blue.read();
    
      if (DATA == 'L')
      {
        while(blue.available() == 0){delay(1);}
        DATA = blue.read();
        
        if (DATA == 'F')
         {
          Ldir = 'F';
          //left.run(FORWARD);
         }
         else if (DATA == 'B')
         {
          Ldir = 'B';
          //left.run(BACKWARD);
         }

       while(blue.available() == 0){delay(1);}
       DATA = blue.read();
       Lspeed = DATA;
       //left.setSpeed(Lspeed);
       
       while(blue.available() == 0){delay(1);}
       DATA = blue.read();
      } 

      
      if (DATA == 'R')
      {
       
        while(blue.available() == 0){delay(1);}
        DATA = blue.read();
        
        if (DATA == 'F')
         {
          Rdir = 'F';
          right.run(FORWARD);
         }
         else if (DATA == 'B')
         {
          Rdir = 'B';
          right.run(BACKWARD);
         }

       while(blue.available() == 0){delay(1);}
       DATA = blue.read();
       Rspeed = DATA;
       //right.setSpeed(Rspeed);

      if (Ldir == 'F'){left.run(FORWARD);} else{left.run(BACKWARD);}
      if (Rdir == 'F'){right.run(FORWARD);} else{right.run(BACKWARD);}
       left.setSpeed(Lspeed);
       right.setSpeed(Rspeed);
      } 

      else if (DATA == 'S')
      {
         left.run(RELEASE);
         right.run(RELEASE);
      }      

      else if (DATA == 'u') // encoder testing
      {
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Ldir = DATA;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Rdir = DATA;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Lspeed = DATA;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Rspeed = DATA;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Lframes = DATA*100;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Lframes += DATA;
        
        Lcounter = 0;
        milliCounter = millis();
        
         left.setSpeed(Lspeed);
         right.setSpeed(Rspeed);
         if(Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
         if(Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}

         while (milliCounter + Lframes > millis()){}
         /*   
          {
          if (digitalRead(A1) != LLastState)
            {
            Lcounter+=1;
            LLastState = !LLastState;
            }
         }
         */
         
          left.run(RELEASE);
          right.run(RELEASE);
         }

         else if (DATA == 'v') // encoder testing with Autocorrect
      {
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Ldir = DATA;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Rdir = DATA;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Lspeed = DATA;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Rspeed = DATA;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        autocorrect = DATA;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Lframes = DATA*100;
        while(blue.available() == 0){delay(0);}
        DATA = blue.read();
        Lframes += DATA;
        
        Lcounter = 0;
        milliCounter = millis();
        
         left.setSpeed(Lspeed);
         right.setSpeed(Rspeed);
         if(Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
         if(Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}

         while (milliCounter + Lframes > millis())
         {

          /*
          if (digitalRead(A1) != LLastState)
            {
            Lcounter+=1;
            LLastState = !LLastState;
            }
           */

           if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
           if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
           
         }
          left.run(RELEASE);
          right.run(RELEASE);
         }


          

       else if  (DATA == 's')  // receive maze data
        {
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          delayBetweenPaths = DATA*4;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          autocorrect = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P1Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P1Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P1Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P1Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P1steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P1steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P2Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P2Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P2Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P2Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P2steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P2steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P3Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P3Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P3Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P3Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P3steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P3steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P4Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P4Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P4Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P4Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P4steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P4steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P5Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P5Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P5Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P5Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P5steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P5steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P6Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P6Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P6Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P6Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P6steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P6steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P7Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P7Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P7Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P7Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P7steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P7steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P8Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P8Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P8Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P8Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P8steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P8steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P9Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P9Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P9Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P9Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P9steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P9steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P10Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P10Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P10Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P10Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P10steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P10steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P11Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P11Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P11Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P11Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P11steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P11steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P12Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P12Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P12Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P12Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P12steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P12steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P13Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P13Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P13Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P13Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P13steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P13steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P14Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P14Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P14Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P14Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P14steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P14steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P15Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P15Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P15Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P15Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P15steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P15steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P16Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P16Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P16Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P16Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P16steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P16steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P17Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P17Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P17Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P17Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P17steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P17steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P18Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P18Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P18Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P18Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P18steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P18steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P19Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P19Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P19Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P19Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P19steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P19steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P20Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P20Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P20Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P20Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P20steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P20steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P21Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P21Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P21Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P21Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P21steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P21steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P22Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P22Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P22Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P22Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P22steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P22steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P23Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P23Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P23Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P23Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P23steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P23steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P24Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P24Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P24Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P24Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P24steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P24steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P25Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P25Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P25Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P25Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P25steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P25steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P26Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P26Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P26Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P26Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P26steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P26steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P27Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P27Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P27Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P27Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P27steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P27steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P28Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P28Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P28Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P28Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P28steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P28steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P29Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P29Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P29Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P29Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P29steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P29steps += DATA;

          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P30Ldir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P30Lspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P30Rdir = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P30Rspeed = DATA;
          
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P30steps = DATA*100;
          while(blue.available() == 0){delay(0);}
          DATA = blue.read();
          P30steps += DATA;
       
          Serial.println(P29steps);
        }

        else if  (DATA == 'm')  // start maze
        {
          maze = true;
        }

        else if  (DATA == 'n')  // stop maze
        {
          maze = false;
          left.run(RELEASE);
          right.run(RELEASE);
        }
        
   }
}
//----------------------

 void MAZE()
 {
  // P1
  left.setSpeed(P1Lspeed);
  right.setSpeed(P1Rspeed);
  if (P1Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P1Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}

  milliCounter = millis();
  counter = 0;
  while (milliCounter + P1steps > millis())
         {
            
            if (blue.available() >0 || P1steps==0){StopMaze(); break;}

            if (digitalRead(A2) == LOW){left.setSpeed(P1Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P1Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P1Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P1Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          
          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P2
  left.setSpeed(P2Lspeed);
  right.setSpeed(P2Rspeed);
  if (P2Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P2Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}

  milliCounter = millis();
  counter = 0;
  while (milliCounter + P2steps > millis())
         {

            if (blue.available() >0 || P2steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P2Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P2Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P2Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P2Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P3
  left.setSpeed(P3Lspeed);
  right.setSpeed(P3Rspeed);
  if (P3Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P3Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}

  milliCounter = millis();
  counter = 0;
  while (milliCounter + P3steps > millis())
         {
          
            if (blue.available() >0 || P3steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P3Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P3Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P3Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P3Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P4
  left.setSpeed(P4Lspeed);
  right.setSpeed(P4Rspeed);
  if (P4Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P4Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();
  counter = 0;
  while (milliCounter + P4steps > millis())
         {
         
            if (blue.available() >0 || P4steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P4Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P4Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P4Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P4Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P5
  left.setSpeed(P5Lspeed);
  right.setSpeed(P5Rspeed);
  if (P5Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P5Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P5steps > millis())
         {
          
            if (blue.available() >0 || P5steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P5Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P5Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P5Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P5Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P6
  left.setSpeed(P6Lspeed);
  right.setSpeed(P6Rspeed);
  if (P6Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P6Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P6steps > millis())
         {
          
            if (blue.available() >0 || P6steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P6Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P6Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P6Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P6Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P7
  left.setSpeed(P7Lspeed);
  right.setSpeed(P7Rspeed);
  if (P7Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P7Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P7steps > millis())
         {
         
            if (blue.available() >0 || P7steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P7Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P7Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P7Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P7Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P8
  left.setSpeed(P8Lspeed);
  right.setSpeed(P8Rspeed);
  if (P8Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P8Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P8steps > millis())
         {
         
            if (blue.available() >0 || P8steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P8Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P8Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P8Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P8Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P9
  left.setSpeed(P9Lspeed);
  right.setSpeed(P9Rspeed);
  if (P9Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P9Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P9steps > millis())
         {
          
            if (blue.available() >0 || P9steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P9Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P9Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P9Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P9Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P10
  left.setSpeed(P10Lspeed);
  right.setSpeed(P10Rspeed);
  if (P10Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P10Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P10steps > millis())
         {
         
            if (blue.available() > 0 || P10steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P10Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P10Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P10Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P10Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P11
  left.setSpeed(P11Lspeed);
  right.setSpeed(P11Rspeed);
  if (P11Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P11Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P11steps > millis())
         {
         
            if (blue.available() >0 || P11steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P11Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P11Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P11Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P11Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P12
  left.setSpeed(P12Lspeed);
  right.setSpeed(P12Rspeed);
  if (P12Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P12Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P12steps > millis())
         {
         
            if (blue.available() >0 || P12steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P12Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P12Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P12Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P12Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P13
  left.setSpeed(P13Lspeed);
  right.setSpeed(P13Rspeed);
  if (P13Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P13Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P13steps > millis())
         {
         
            if (blue.available() >0 || P13steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P13Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P13Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P13Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P13Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P14
  left.setSpeed(P14Lspeed);
  right.setSpeed(P14Rspeed);
  if (P14Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P14Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P14steps > millis())
         {
         
            if (blue.available() >0 || P14steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P14Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P14Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P14Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P14Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P15
  left.setSpeed(P15Lspeed);
  right.setSpeed(P15Rspeed);
  if (P15Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P15Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P15steps > millis())
         {
         
            if (blue.available() >0 || P15steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P15Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P15Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P15Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P15Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P16
  left.setSpeed(P16Lspeed);
  right.setSpeed(P16Rspeed);
  if (P16Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P16Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P16steps > millis())
         {
         
            if (blue.available() >0 || P16steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P16Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P16Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P16Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P16Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P17
  left.setSpeed(P17Lspeed);
  right.setSpeed(P17Rspeed);
  if (P17Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P17Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P17steps > millis())
         {
         
            if (blue.available() >0 || P17steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P17Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P17Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P17Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P17Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P18
  left.setSpeed(P18Lspeed);
  right.setSpeed(P18Rspeed);
  if (P18Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P18Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P18steps > millis())
         {
         
            if (blue.available() >0 || P18steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P18Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P18Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P18Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P18Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P19
  left.setSpeed(P19Lspeed);
  right.setSpeed(P19Rspeed);
  if (P19Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P19Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P19steps > millis())
         {
         
            if (blue.available() >0 || P19steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P19Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P19Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P19Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P19Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P20
  left.setSpeed(P20Lspeed);
  right.setSpeed(P20Rspeed);
  if (P20Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P20Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P20steps > millis())
         {
         
            if (blue.available() >0 || P20steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P20Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P20Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P20Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P20Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P21
  left.setSpeed(P21Lspeed);
  right.setSpeed(P21Rspeed);
  if (P21Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P21Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P21steps > millis())
         {
         
            if (blue.available() >0 || P21steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P21Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P21Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P21Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P21Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P22
  left.setSpeed(P22Lspeed);
  right.setSpeed(P22Rspeed);
  if (P22Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P22Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P22steps > millis())
         {
         
            if (blue.available() >0 || P22steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P22Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P22Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P22Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P22Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P23
  left.setSpeed(P23Lspeed);
  right.setSpeed(P23Rspeed);
  if (P23Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P23Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P23steps > millis())
         {
         
            if (blue.available() >0 || P23steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P23Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P23Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P23Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P23Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P24
  left.setSpeed(P24Lspeed);
  right.setSpeed(P24Rspeed);
  if (P24Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P24Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P24steps > millis())
         {
          
            if (blue.available() >0 || P24steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P24Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P24Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P24Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P24Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P25
  left.setSpeed(P25Lspeed);
  right.setSpeed(P25Rspeed);
  if (P25Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P25Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P25steps > millis())
         {
          
            if (blue.available() >0 || P25steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P25Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P25Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P25Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P25Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P26
  left.setSpeed(P26Lspeed);
  right.setSpeed(P26Rspeed);
  if (P26Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P26Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P26steps > millis())
         {
         
            if (blue.available() >0 || P26steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P26Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P26Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P26Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P26Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P27
  left.setSpeed(P27Lspeed);
  right.setSpeed(P27Rspeed);
  if (P27Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P27Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P27steps > millis())
         {
         
            if (blue.available() >0 || P27steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P27Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P27Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P27Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P27Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P28
  left.setSpeed(P28Lspeed);
  right.setSpeed(P28Rspeed);
  if (P28Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P28Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P28steps > millis())
         {
         
            if (blue.available() >0 || P28steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P28Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P28Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P28Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P28Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P29
  left.setSpeed(P29Lspeed);
  right.setSpeed(P29Rspeed);
  if (P29Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P29Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P29steps > millis())
         {
         
            if (blue.available() >0 || P29steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P29Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P29Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P29Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P29Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          // P30
  left.setSpeed(P30Lspeed);
  right.setSpeed(P30Rspeed);
  if (P30Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P30Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P30steps > millis())
         {
         
            if (blue.available() >0 || P30steps==0){StopMaze(); break;}
            
            if (digitalRead(A2) == LOW){left.setSpeed(P30Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(P30Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(P30Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(P30Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);

          if (blue.available() >0 ){StopMaze();}
          if (maze==true) {delay(delayBetweenPaths);}

          
          
          StopMaze();
 }
//---------

 void StopMaze()
 {
  maze = false;
  left.run(RELEASE);
  right.run(RELEASE);
 }

