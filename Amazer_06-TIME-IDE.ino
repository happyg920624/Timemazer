/*    
      Delay = 400
      Autocorrect = 30
      L speed = 200
      R speed = 200
      Turn left = 190
      Turn right = 190
      1 BLOCK = 690
      2 BLOCKS = 1200
      3 BLOCKS = 1850
      4 BLOCKS = 2520 
      5 BLOCKS = 3150
 */ 
                            
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

byte pathsNo;
byte Ldir = 'F';
byte Rdir = 'F';
bool maze = false;  // Do maze if true

//++++++++++++++++++++++++++++++++++++++++
int delayBetweenPaths = 300;    // 400
byte autocorrect = 30;          // 30
byte Lspeed = 200;              // ?
byte Rspeed = 200;              // ?

char P1dir = 'F';
int P1steps = 0;

char P2dir = 'F';
int P2steps = 0;

char P3dir = 'F';
int P3steps = 0;

char P4dir = 'F';
int P4steps = 0;

char P5dir = 'F';
int P5steps = 0;

char P6dir = 'F';
int P6steps = 0;

char P7dir = 'F';
int P7steps = 0;

char P8dir = 'F';
int P8steps = 0;

char P9dir = 'F';
int P9steps = 0;

char P10dir = 'F';
int P10steps = 0;

char P11dir = 'F';
int P11steps = 0;

char P12dir = 'F';
int P12steps = 0;

char P13dir = 'F';
int P13steps = 0;

char P14dir = 'F';
int P14steps = 0;

char P15dir = 'F';
int P15steps = 0;

char P16dir = 'F';
int P16steps = 0;

char P17dir = 'F';
int P17steps = 0;

char P18dir = 'F';
int P18steps = 0;

char P19dir = 'F';
int P19steps = 0;

char P20dir = 'F';
int P20steps = 0;

char P21dir = 'F';
int P21steps = 0;

char P22dir = 'F';
int P22steps = 0;

char P23dir = 'F';
int P23steps = 0;

char P24dir = 'F';
int P24steps = 0;

char P25dir = 'F';
int P25steps = 0;

char P26dir = 'F';
int P26steps = 0;

char P27dir = 'F';
int P27steps = 0;

char P28dir = 'F';
int P28steps = 0;

char P29dir = 'F';
int P29steps = 0;

char P30dir = 'F';
int P30steps = 0;
//-------------------------------

char P1Ldir;
char P1Rdir;

char P2Ldir;
char P2Rdir;

char P3Ldir;
char P3Rdir;

char P4Ldir;
char P4Rdir;

char P5Ldir;
char P5Rdir;

char P6Ldir;
char P6Rdir;

char P7Ldir;
char P7Rdir;

char P8Ldir;
char P8Rdir;

char P9Ldir;
char P9Rdir;

char P10Ldir;
char P10Rdir;

char P11Ldir;
char P11Rdir;

char P12Ldir;
char P12Rdir;

char P13Ldir;
char P13Rdir;

char P14Ldir;
char P14Rdir;

char P15Ldir;
char P15Rdir;

char P16Ldir;
char P16Rdir;

char P17Ldir;
char P17Rdir;

char P18Ldir;
char P18Rdir;

char P19Ldir;
char P19Rdir;

char P20Ldir;
char P20Rdir;

char P21Ldir;
char P21Rdir;

char P22Ldir;
char P22Rdir;

char P23Ldir;
char P23Rdir;

char P24Ldir;
char P24Rdir;

char P25Ldir;
char P25Rdir;

char P26Ldir;
char P26Rdir;

char P27Ldir;
char P27Rdir;

char P28Ldir;
char P28Rdir;

char P29Ldir;
char P29Rdir;

char P30Ldir;
char P30Rdir;

void setup()
{
   if (P1dir == 'L'){P1Ldir = 'B';}else{P1Ldir = 'F';}
   if (P2dir == 'L'){P2Ldir = 'B';}else{P2Ldir = 'F';}
   if (P3dir == 'L'){P3Ldir = 'B';}else{P3Ldir = 'F';}
   if (P4dir == 'L'){P4Ldir = 'B';}else{P4Ldir = 'F';}
   if (P5dir == 'L'){P5Ldir = 'B';}else{P5Ldir = 'F';}
   if (P6dir == 'L'){P6Ldir = 'B';}else{P6Ldir = 'F';}
   if (P7dir == 'L'){P7Ldir = 'B';}else{P7Ldir = 'F';}
   if (P8dir == 'L'){P8Ldir = 'B';}else{P8Ldir = 'F';}
   if (P9dir == 'L'){P9Ldir = 'B';}else{P9Ldir = 'F';}
   if (P10dir == 'L'){P10Ldir = 'B';}else{P10Ldir = 'F';}
   if (P11dir == 'L'){P11Ldir = 'B';}else{P11Ldir = 'F';}
   if (P12dir == 'L'){P12Ldir = 'B';}else{P12Ldir = 'F';}
   if (P13dir == 'L'){P13Ldir = 'B';}else{P13Ldir = 'F';}
   if (P14dir == 'L'){P14Ldir = 'B';}else{P14Ldir = 'F';}
   if (P15dir == 'L'){P15Ldir = 'B';}else{P15Ldir = 'F';}
   if (P16dir == 'L'){P16Ldir = 'B';}else{P16Ldir = 'F';}
   if (P17dir == 'L'){P17Ldir = 'B';}else{P17Ldir = 'F';}
   if (P18dir == 'L'){P18Ldir = 'B';}else{P18Ldir = 'F';}
   if (P19dir == 'L'){P19Ldir = 'B';}else{P19Ldir = 'F';}
   if (P20dir == 'L'){P20Ldir = 'B';}else{P20Ldir = 'F';}
   if (P21dir == 'L'){P21Ldir = 'B';}else{P21Ldir = 'F';}
   if (P22dir == 'L'){P22Ldir = 'B';}else{P22Ldir = 'F';}
   if (P23dir == 'L'){P23Ldir = 'B';}else{P23Ldir = 'F';}
   if (P24dir == 'L'){P24Ldir = 'B';}else{P24Ldir = 'F';}
   if (P25dir == 'L'){P25Ldir = 'B';}else{P25Ldir = 'F';}
   if (P26dir == 'L'){P26Ldir = 'B';}else{P26Ldir = 'F';}
   if (P27dir == 'L'){P27Ldir = 'B';}else{P27Ldir = 'F';}
   if (P28dir == 'L'){P28Ldir = 'B';}else{P28Ldir = 'F';}
   if (P29dir == 'L'){P29Ldir = 'B';}else{P29Ldir = 'F';}
   if (P30dir == 'L'){P30Ldir = 'B';}else{P30Ldir = 'F';}

   if (P1dir == 'R'){P1Rdir = 'B';}else{P1Rdir = 'F';}
   if (P2dir == 'R'){P2Rdir = 'B';}else{P2Rdir = 'F';}
   if (P3dir == 'R'){P3Rdir = 'B';}else{P3Rdir = 'F';}
   if (P4dir == 'R'){P4Rdir = 'B';}else{P4Rdir = 'F';}
   if (P5dir == 'R'){P5Rdir = 'B';}else{P5Rdir = 'F';}
   if (P6dir == 'R'){P6Rdir = 'B';}else{P6Rdir = 'F';}
   if (P7dir == 'R'){P7Rdir = 'B';}else{P7Rdir = 'F';}
   if (P8dir == 'R'){P8Rdir = 'B';}else{P8Rdir = 'F';}
   if (P9dir == 'R'){P9Rdir = 'B';}else{P9Rdir = 'F';}
   if (P10dir == 'R'){P10Rdir = 'B';}else{P10Rdir = 'F';}
   if (P11dir == 'R'){P11Rdir = 'B';}else{P11Rdir = 'F';}
   if (P12dir == 'R'){P12Rdir = 'B';}else{P12Rdir = 'F';}
   if (P13dir == 'R'){P13Rdir = 'B';}else{P13Rdir = 'F';}
   if (P14dir == 'R'){P14Rdir = 'B';}else{P14Rdir = 'F';}
   if (P15dir == 'R'){P15Rdir = 'B';}else{P15Rdir = 'F';}
   if (P16dir == 'R'){P16Rdir = 'B';}else{P16Rdir = 'F';}
   if (P17dir == 'R'){P17Rdir = 'B';}else{P17Rdir = 'F';}
   if (P18dir == 'R'){P18Rdir = 'B';}else{P18Rdir = 'F';}
   if (P19dir == 'R'){P19Rdir = 'B';}else{P19Rdir = 'F';}
   if (P20dir == 'R'){P20Rdir = 'B';}else{P20Rdir = 'F';}
   if (P21dir == 'R'){P21Rdir = 'B';}else{P21Rdir = 'F';}
   if (P22dir == 'R'){P22Rdir = 'B';}else{P22Rdir = 'F';}
   if (P23dir == 'R'){P23Rdir = 'B';}else{P23Rdir = 'F';}
   if (P24dir == 'R'){P24Rdir = 'B';}else{P24Rdir = 'F';}
   if (P25dir == 'R'){P25Rdir = 'B';}else{P25Rdir = 'F';}
   if (P26dir == 'R'){P26Rdir = 'B';}else{P26Rdir = 'F';}
   if (P27dir == 'R'){P27Rdir = 'B';}else{P27Rdir = 'F';}
   if (P28dir == 'R'){P28Rdir = 'B';}else{P28Rdir = 'F';}
   if (P29dir == 'R'){P29Rdir = 'B';}else{P29Rdir = 'F';}
   if (P30dir == 'R'){P30Rdir = 'B';}else{P30Rdir = 'F';}

  left.setSpeed(Lspeed);
  right.setSpeed(Rspeed);
  pinMode(9,OUTPUT); // buzzer
  
  maze = true;
  delay (1000);
}

void loop()
{
  if (maze == true) {MAZE();}
}
//================

 void MAZE()
 {
  // P1
  if (P1Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P1Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}

  milliCounter = millis();
  counter = 0;
  while (milliCounter + P1steps > millis())
         {
            if (P1steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P2
  if (P2Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P2Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}

  milliCounter = millis();
  counter = 0;
  while (milliCounter + P2steps > millis())
         {
            if (P2steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P3
  if (P3Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P3Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}

  milliCounter = millis();
  counter = 0;
  while (milliCounter + P3steps > millis())
         {
            if (P3steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P4
  if (P4Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P4Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();
  counter = 0;
  while (milliCounter + P4steps > millis())
         {
            if (P4steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P5
  if (P5Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P5Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P5steps > millis())
         {
            if (P5steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P6
  if (P6Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P6Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P6steps > millis())
         {
            if (P6steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P7
  if (P7Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P7Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P7steps > millis())
         {
            if (P7steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P8
  if (P8Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P8Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P8steps > millis())
         {
            if (P8steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P9
  if (P9Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P9Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P9steps > millis())
         {
            if (P9steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P10
  if (P10Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P10Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P10steps > millis())
         {
            if (P10steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P11
  if (P11Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P11Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P11steps > millis())
         {
            if (P11steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P12
  if (P12Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P12Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P12steps > millis())
         {
            if (P12steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P13
  if (P13Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P13Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P13steps > millis())
         {
            if (P13steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P14
  if (P14Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P14Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P14steps > millis())
         {
            if (P14steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P15
  if (P15Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P15Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P15steps > millis())
         {
            if (P15steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P16
  if (P16Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P16Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P16steps > millis())
         {
            if (P16steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P17
  if (P17Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P17Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P17steps > millis())
         {
            if (P17steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P18
  if (P18Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P18Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P18steps > millis())
         {
            if (P18steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P19
  if (P19Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P19Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P19steps > millis())
         {
            if (P19steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P20
  if (P20Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P20Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P20steps > millis())
         {
            if (P20steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P21
  if (P21Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P21Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P21steps > millis())
         {
            if (P21steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P22
  if (P22Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P22Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P22steps > millis())
         {
            if (P22steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P23
  if (P23Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P23Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P23steps > millis())
         {
            if (P23steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P24
  if (P24Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P24Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P24steps > millis())
         {
            if (P24steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P25
  if (P25Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P25Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P25steps > millis())
         {
          
            if (P25steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P26
  if (P26Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P26Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P26steps > millis())
         {
            if (P26steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P27
  if (P27Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P27Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P27steps > millis())
         {
            if (P27steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P28
  if (P28Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P28Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P28steps > millis())
         {
            if (P28steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P29
  if (P29Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P29Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
   
  milliCounter = millis(); 
  counter = 0;
  while (milliCounter + P29steps > millis())
         {
            if (P29steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
          if (maze==true) {delay(delayBetweenPaths);}

          // P30
  if (P30Ldir == 'F'){left.run(FORWARD);}else{left.run(BACKWARD);}
  if (P30Rdir == 'F'){right.run(FORWARD);}else{right.run(BACKWARD);}
  
  milliCounter = millis();  
  counter = 0;
  while (milliCounter + P30steps > millis())
         {
            if (P30steps==0){StopMaze(); break;}
            if (digitalRead(A2) == LOW){left.setSpeed(Lspeed-autocorrect); tone(9,500,50);}else{left.setSpeed(Lspeed);}
            if (digitalRead(A3) == LOW){right.setSpeed(Rspeed-autocorrect); tone(9,1000,50);}else{right.setSpeed(Rspeed);}
         }
          left.run(RELEASE);
          right.run(RELEASE);
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
