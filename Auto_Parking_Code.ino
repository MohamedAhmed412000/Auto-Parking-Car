#include <Servo.h>

long y1;    // y1 is the destance right the car

long y2;    // y2 is the destance left the car

long y3;  

Servo motor;

float trigpin=5;

float echopin=6;

long duration, distance;

const byte motorL1 = 2;     //motor left(back)  
bin1
const byte motorL2 = 4;     //motor left(back)  
bin2
const byte motorR1 = 7;     //motor right(back) 
bin1
const byte motorR2 = 8;     //motor right(back) 
bin2
const byte ENL     = 10;     //motor left  (analog speed)

const byte ENR     = 9;     //motor right (analog speed)




void setup() {

  Serial.begin(9600);

  motor.attach(3);

  pinMode(trigpin,OUTPUT);

  pinMode(echopin,INPUT);  

  pinMode(ENL,OUTPUT);

  pinMode(ENR,OUTPUT);   

  pinMode(motorL1,OUTPUT);

  pinMode(motorL2,OUTPUT);

  pinMode(motorR1,OUTPUT);

  pinMode(motorR2,OUTPUT);

}





void forward (int i)
{
  
  analogWrite(ENL,i);    
  
  analogWrite(ENR,i);
  
  digitalWrite(motorL1,HIGH);
  
  digitalWrite(motorL2,LOW);
  
  digitalWrite(motorR1,HIGH);
  
  digitalWrite(motorR2,LOW);
  
}



void backward (int i)
{
  
  analogWrite(ENL,i);    
  
  analogWrite(ENR,i);
  
  digitalWrite(motorL1,LOW);
  
  digitalWrite(motorL2,HIGH);
  
  digitalWrite(motorR1,LOW);
  
  digitalWrite(motorR2,HIGH); 

}



void fleft (int i)
{
  
  analogWrite(ENL,i-14);
  
  analogWrite(ENR,i);
  
  digitalWrite(motorL1,LOW);
  
  digitalWrite(motorL2,HIGH);
  
  digitalWrite(motorR1,HIGH);
  
  digitalWrite(motorR2,LOW);

}



void fright (int i)
{   
  
  analogWrite(ENL,i);
  
  analogWrite(ENR,i-14);
  
  digitalWrite(motorL1,HIGH);
  
  digitalWrite(motorL2,LOW);
  
  digitalWrite(motorR1,LOW);
  
  digitalWrite(motorR2,HIGH);

}


void bleft (int i)
{
  
  analogWrite(ENL,i-14);
  
  analogWrite(ENR,i);
  
  digitalWrite(motorL1,LOW);
  
  digitalWrite(motorL2,HIGH);
  
  digitalWrite(motorR1,LOW);
  
  digitalWrite(motorR2,HIGH);

}



void bright (int i)
{   
  
  analogWrite(ENL,i);
  
  analogWrite(ENR,i-14);
  
  digitalWrite(motorL1,LOW);
  
  digitalWrite(motorL2,HIGH);
  
  digitalWrite(motorR1,LOW);
  
  digitalWrite(motorR2,HIGH);

}

 

void ultrasonic (long distance)
 {
 
  digitalWrite(trigpin,LOW);
 
  delayMicroseconds(2);
 
  digitalWrite(trigpin,HIGH);
 
  delayMicroseconds(10);
 
  digitalWrite(trigpin,LOW);
 
  duration=pulseIn(echopin,HIGH);
 
  distance=(duration/2) / 29.1; 
 
}

 

void loop() {
 
 
  motor.write(0);
 
  ultrasonic(distance);

  y1=distance;

  motor.write(180);
 
 ultrasonic(distance);

  y2=distance;

  if(y1>y2){

    motor.write(0);

    ultrasonic(distance);  

    y1=distance;
 
   forward(100);

    ultrasonic(distance);
  
  if(distance>y1){

      forward(100);

      delay(2000);

      forward(0);   

    }
 
    motor.write(90);

    fright(100);

    ultrasonic(distance);  
   
    if(distance<=3){

      forward(0);
   
    }

    backward(100);

    delay(2000);
   
      



   
 
  }  

}
