# Timemazer
*迷宮自走車
//   Middle:   L:9,  R:9
//   Left:     R:14
//   Right:    L:15
//   Enter:    F:23

#include <AFMotor.h>
AF_DCMotor left(4);  //AF moter shield M4 terminal
AF_DCMotor right(3); //AF moter shield M3 terminal

#include <Ultrasonic.h>
Ultrasonic USfront(A5,A2);  //TRIG, ECHO
Ultrasonic USleft(A1,A3);   //TRIG, ECHO
Ultrasonic USright(10,A4);  //TRIG, ECHO

 byte Lspeed = 190;
 byte Rspeed = 210;

 int Fdist;
 int Ldist;
 int Rdist;

 unsigned long lastUS;  //for stuck check
 int lastF;             //for stuck check

 
void setup() 
{
 left.setSpeed(Lspeed);
 right.setSpeed(Rspeed);
 delay(1000);
}
 
void loop()
{
 left.run(FORWARD);
 right.run(FORWARD);

 
  delay(20);
 Fdist=USfront.distanceRead();
 delay(20);
 Ldist=USleft.distanceRead();
 delay(20);
 Rdist=USright.distanceRead();
 
    if (Ldist <= 3) { right.setSpeed(Rspeed- 60);}
 else if (Ldist == 4) { right.setSpeed(Rspeed- 50);}
 else if (Ldist == 5) { right.setSpeed(Rspeed- 40);}
 else if (Ldist == 6) { right.setSpeed(Rspeed- 30);}
 else if (Ldist == 7) { right.setSpeed(Rspeed- 20);}
 else if (Ldist == 8) { right.setSpeed(Rspeed- 10);}

  else if (Ldist == 10) { left.setSpeed(Rspeed- 10);}
  else if (Ldist == 11) { left.setSpeed(Rspeed- 20);}
  else if (Ldist == 12) { left.setSpeed(Rspeed- 30);}
  else if (Ldist == 13) { left.setSpeed(Rspeed- 40);}
  else if (Ldist == 14) { left.setSpeed(Rspeed- 50);}
  else if (Ldist == 15) { left.setSpeed(Rspeed- 60);}
  else {left.setSpeed(Lspeed);right.setSpeed(Rspeed);}

  //STUCK
  if(Fdist == lastF || Fdist == lastF+1 || Fdist == lastF-1)
  {
    if (millis() > lastUS + 1000)
    {
      tone(9,7500,50);
      left.setSpeed(Lspeed-50);
      right.setSpeed(Rspeed-50);
      left.run(BACKWARD);
      right.run(BACKWARD);
      delay(300);
      right.run(BACKWARD);
      delay(250);
      left.run(FORWARD);
      left.run(FORWARD);
      }
    }
    else
    {
       lastUS = millis();
       lastF = Fdist;
    }
      
}
