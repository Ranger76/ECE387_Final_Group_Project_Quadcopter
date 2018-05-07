/*
 * Copyright Takdanai Tantiyartyanontha, Taewoong Won
 */

#include <Servo.h>;
#include <SoftwareSerial.h>

const int Tx =2;
const int Rx = 3;
const int StatePin = 4;

SoftwareSerial btSerial(2,3);

// Declaring and/or initializing variable to be used 
// as pin assignments and values written to the 
// assigned pins.
int flexPin0 = 0;
int flexPin1 = 1;
int flexPin2 = 2;
int flexPin3 = 3;
int flexPin4 = 4;
int flexPin5 = 5;
int flexRead0;
int flexRead1;
int flexRead2;
int flexRead3;
int flexRead4;
int flexRead5;

bool f0 = false,f1 =false,f3=false,f4=false,f5=false;

void setup(void)
{
  // put your setup code here, to run once:
  // Setting the baud rate.
  Serial.begin(9550);
  btSerial.begin(9550);

}

void loop()
{

  // put your main code here, to run repeatedly:
  // Assigning the registered input values from 
  // pin A0 and A1 to repective variables.
  flexRead0 = analogRead(flexPin0);
  flexRead1 = analogRead(flexPin1);
  flexRead2 = analogRead(flexPin2);
  flexRead3 = analogRead(flexPin3);
  flexRead4 = analogRead(flexPin4);
  
  flexRead5 = analogRead(flexPin5);


  
  // Checking the variables with the input values.
  Serial.println("flexRead0:");
  Serial.println(flexRead0);
  Serial.println("flexRead1:");
  Serial.println(flexRead1);
//  Serial.println("flexRead2:");
//  Serial.println(flexRead2);
//  Serial.println("flexRead3:");
//  Serial.println(flexRead3);
//  Serial.println("flexRead4:");
//  Serial.println(flexRead4);
//  Serial.println("flexRead5:");
//  Serial.println(flexRead5);

  //flexed = greater than 550
  //flex5 for reverse
  //flex0,1,3,4 for motor control
  // Mapping base_0 motor angle_base_0 
  // for flexSensor 0.

  if(flexRead5 < 500){
    //Motor 0
      if(flexRead0 >= 550 && !f0){
      btSerial.write('a');
      Serial.print('a');
        f0 = true;
      }
      if(flexRead0 < 550 && f0){
        f0 = false;
      }
    //Motor 1
          if(flexRead1 >= 550 && !f1){
      btSerial.write('c');
       Serial.print('c');
        f1 = true;
      }
      if(flexRead1 < 550 && f1){
        f1 = false;
      }
      //Motor 2
          if(flexRead3 >= 550 && !f3){
      btSerial.write('e');
       Serial.print('e');
        f3 = true;
      }
      if(flexRead3 < 550 && f3){
        f3 = false;
      }

          if(flexRead4 >= 550 && !f4){
      btSerial.write('g');
       Serial.print('g');
        fb4 = true;
      }
      if(flexRead4 < 550 && f4){
        f4 = false;
      }
      
    
  }else if(flexRead5 >= 500){
    //Motor 0
      if(flexRead0 >= 550 && !f0){
      btSerial.write('b');
       Serial.print('b');
        f0 = true;
      }
      if(flexRead0 < 550 && f0){
        f0 = false;
      }
    //Motor 1
          if(flexRead1 >= 550 && !f1){
      btSerial.write('d');
       Serial.print('d');
        f1 = true;
      }
      if(flexRead1 < 550 && f1){
        f1 = false;
      }
      //Motor 2
          if(flexRead3 >= 550 && !f3){
      btSerial.write('f');
       Serial.print('f');
        f3 = true;
      }
      if(flexRead3 < 550 && f3){
        f3 = false;
      }

          if(flexRead4 >= 550 && !f4){
      btSerial.write('h');
       Serial.print('h');
        f4 = true;
      }
      if(flexRead4 < 550 && f4){
        f4 = false;
      } 
  }


if(flexRead2 > 500){
  btSerial.write('z');
}
  
}








