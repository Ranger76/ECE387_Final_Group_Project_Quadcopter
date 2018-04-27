/*
 * The script written associated to the flex sensor 
 * was written by Takdanai Tantiyartyanontha.
 */

 // To vary the speed change the speed (int) varible; 
 // do not change anything in the setSpeed method.

 // Connect ESC high to pin 6 (PWM) on the Arduino board

#include <Servo.h>;

// Declaring and/or initializing variable to be used 
// as pin assignments and values written to the 
// assigned pins.
int flexPin0 = 0;
int flexPin1 = 1;
int flexRead0;
int flexRead1;
Servo ESC_0;
Servo ESC_1;
Servo ESC_2;
Servo ESC_3;

void setSpeed(int speed) {
  int i = 0;
  int angle = map(speed, 0, 1000, 0, 100); //Sets servo positions to difeerent speeds
  ESC_0.write(angle);
  Serial.println(angle);
}

void setup(void)
{
  // put your setup code here, to run once:
  // Setting the baud rate.
  Serial.begin(9600);
  
  // Set up ESC pins
  ESC_0.attach(6); // Adds ESC;
  ESC_1.attach(9); // Adds ESC;
  ESC_2.attach(10); // Adds ESC;
  ESC_3.attach(11); // Adds ESC;
  
}

void loop()
{

  // put your main code here, to run repeatedly:
  // Assigning the registered input values from 
  // pin A0 and A1 to repective variables.
  flexRead0 = analogRead(flexPin0);
  flexRead1 = analogRead(flexPin1);
  
  // Checking the variables with the input values.
//  Serial.println("flexRead0:");
//  Serial.println(flexRead0);
//  Serial.println("flexRead1:");
//  Serial.println(flexRead1);

  // only working for value equal to or higher than 600.
  int speed = 630; //Implements speed variable
  setSpeed(speed); //Creates variable for speed to be used


  // Mapping ESC 0 motor speed 
  // for flexSensor 0.
  if (flexRead0 >= 700) {
    speed = 700;
  }
  else if (flexRead0 >= 600) {
    speed = 650;
  }
  else if (flexRead0 >= 575) {
    speed = 640;
  }
  else if (flexRead0 >= 525) {
    speed = 630;
  }
  else if (flexRead0 >= 475) {
    speed = 620;
  }
  else if (flexRead0 >= 425) {
    speed = 610;
  }
  else if (flexRead0 < 425) {
    speed = 0;
  }
  else {
  }


  // Mapping ESC 1 motor speed 
  // for flexSensor 0.
  if (flexRead0 >= 700) {
    speed = 700;
  }
  else if (flexRead0 >= 600) {
    speed = 650;
  }
  else if (flexRead0 >= 575) {
    speed = 640;
  }
  else if (flexRead0 >= 525) {
    speed = 630;
  }
  else if (flexRead0 >= 475) {
    speed = 620;
  }
  else if (flexRead0 >= 425) {
    speed = 610;
  }
  else if (flexRead0 < 425) {
    speed = 0;
  }
  else {
  }

  // Mapping ESC 2 motor speed 
  // for flexSensor 0.
  if (flexRead0 >= 700) {
    speed = 700;
  }
  else if (flexRead0 >= 600) {
    speed = 650;
  }
  else if (flexRead0 >= 575) {
    speed = 640;
  }
  else if (flexRead0 >= 525) {
    speed = 630;
  }
  else if (flexRead0 >= 475) {
    speed = 620;
  }
  else if (flexRead0 >= 425) {
    speed = 610;
  }
  else if (flexRead0 < 425) {
    speed = 0;
  }
  else {
  }

  // Mapping ESC 3 motor speed 
  // for flexSensor 0.
  if (flexRead0 >= 700) {
    speed = 700;
  }
  else if (flexRead0 >= 600) {
    speed = 650;
  }
  else if (flexRead0 >= 575) {
    speed = 640;
  }
  else if (flexRead0 >= 525) {
    speed = 630;
  }
  else if (flexRead0 >= 475) {
    speed = 620;
  }
  else if (flexRead0 >= 425) {
    speed = 610;
  }
  else if (flexRead0 < 425) {
    speed = 0;
  }
  else {
  }

}







