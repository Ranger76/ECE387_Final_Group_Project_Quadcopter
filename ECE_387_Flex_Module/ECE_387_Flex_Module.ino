/*
 * The script written associated to the flex sensor 
 * was written by Takdanai Tantiyartyanontha.
 */

// .writeMicroseconds(1510) makes the 
// continuous servo 1 stop
// values above 1510 = ccw
// values below 1510 = cw
// .writeMicroseconds(1512) makes the 
// continuous servo 2 stop
// values above 1512 = ccw
// values below 1512 = cw
// .writeMicroseconds(1490) makes the 
// continuous servo 3 stop
// values above 1490 = ccw
// values below 1490 = cw

#include <Servo.h>;

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
int angle_base_0 = 1510;
int angle_base_1 = 1510;
int angle_arm = 1510;
int angle_gripper = 1510;
Servo base_0; // servo 1
Servo base_1; // servo 2
Servo arm; // servo 3
Servo gripper;

void setup(void)
{
  // put your setup code here, to run once:
  // Setting the baud rate.
  Serial.begin(9600);
  
  // Set up continuous rotation servo pins
  base_0.attach(6);
  base_1.attach(9);
  arm.attach(10);
  gripper.attach(11);
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
  Serial.println("flexRead2:");
  Serial.println(flexRead2);
  Serial.println("flexRead3:");
  Serial.println(flexRead3);
  Serial.println("flexRead4:");
  Serial.println(flexRead4);
  Serial.println("flexRead5:");
  Serial.println(flexRead5);

  // testing angle control
//  angle_base_0 = 1510;
  //Creates variable for angle_base_0 to be used
  
  base_0.writeMicroseconds(angle_base_0);
  Serial.println("angle_base_0:");
  Serial.println(angle_base_0);
  base_1.writeMicroseconds(angle_base_1);
  Serial.println("angle_base_1:");
  Serial.println(angle_base_1);
  arm.writeMicroseconds(angle_arm);
  Serial.println("anglearm:");
  Serial.println(angle_arm);
  
  // Mapping base_0 motor angle_base_0 
  // for flexSensor 0.
  if (flexRead0 >= 400 && flexRead5 >= 350) {
    angle_base_0 = 1540;
  }
  else if (flexRead0 >= 350 && flexRead5 >= 350) {
    angle_base_0 = 1530;
  }
  else if (flexRead0 >= 400 && flexRead5 < 350) {
    angle_base_0 = 1480;
  }
  else if (flexRead0 >= 350 && flexRead5 < 350) {
    angle_base_0 = 1490;
  }
  else if (flexRead0 < 400) {
    angle_base_0 = 1510;
  }
  else {
  }

  // Mapping base_1 motor angle_base_1 
  // for flexSensor 1.
  if (flexRead1 >= 400 && flexRead5 >= 350) {
    angle_base_1 = 1540;
  }
  else if (flexRead1 >= 350 && flexRead5 >= 350) {
    angle_base_1 = 1530;
  }
  else if (flexRead1 >= 400 && flexRead5 < 350) {
    angle_base_1 = 1480;
  }
  else if (flexRead1 >= 350 && flexRead5 < 350) {
    angle_base_1 = 1490;
  }
  else if (flexRead1 < 400) {
    angle_base_1 = 1512;
  }
  else {
  }

  // Mapping arm motor angle_arm 
  // for flexSensor 0.
  if (flexRead3 >= 425 && flexRead5 >= 350) {
    angle_arm = 1520;
  }
  else if (flexRead3 >= 350 && flexRead5 >= 350) {
    angle_arm = 1510;
  }
  else if (flexRead3 >= 425 && flexRead5 < 350) {
    angle_arm = 1460;
  }
  else if (flexRead3 >= 350 && flexRead5 < 350) {
    angle_arm = 1470;
  }
  else if (flexRead3 < 400) {
    angle_arm = 1490;
  }
  else {
  }

//  // Mapping base_0 motor angle_base_0 
//  // for flexSensor 0.
//  if (flexRead0 >= 400 && flexRead5 >= 300) {
//    angle_base_0 = 1540;
//  }
//  else if (flexRead0 >= 350 && flexRead5 >= 300) {
//    angle_base_0 = 1530;
//  }
//  else if (flexRead0 >= 400 && flexRead5 < 300) {
//    angle_base_0 = 1480;
//  }
//  else if (flexRead0 >= 350 && flexRead5 < 300) {
//    angle_base_0 = 1490;
//  }
//  else if (flexRead0 < 400) {
//    angle_base_0 = 1510;
//  }
//  else {
//  }
  
}







