/*
 * The script written associated to the flex sensor 
 * was written by Takdanai Tantiyartyanontha.
 */

 // To vary the speed change the speed (int) varible; 
 // do not change anything in the setSpeed method.

 // Connect ESC high to pin 6 (PWM) on the Arduino board

#include <Servo.h>;
#include <SoftwareSerial.h>;

//Minimum/Base Speed and Maximum Speed for motors
const int baseSpeed = 64;
const int maxSpeed = 70;

//Pins for Bluetooth
const int Tx = 2;
const int Rx = 3;
const int StatePin = 4;

//Setup Bluetooth Module
SoftwareSerial btSerial(2,3);

Servo ESC_0;
Servo ESC_1;
Servo ESC_2;
Servo ESC_3;

int connection = 0;
bool prevConnection = 0;
char d;
String data = "";

int speed0 = baseSpeed;
int speed1 = baseSpeed;
int speed2 = baseSpeed;
int speed3 = baseSpeed;

//Checks if a given speed is in range
int checkSpeed(int i){
  if(i >= baseSpeed && i <= maxSpeed)
  return i;
  else if(i > maxSpeed)
  return 70;
  else return 64;
  
}

void setup(void)
{
  // put your setup code here, to run once:
  // Setting the baud rate.
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(StatePin,INPUT);
  
  // Set up ESC pins
  //ESC_0.attach(6); // Adds ESC;
  //ESC_1.attach(9); // Adds ESC;
  //ESC_2.attach(10); // Adds ESC;
  //ESC_3.attach(11); // Adds ESC;
  
}

//Checks for Bluetooth Connection
 bool connected(){
  connection = digitalRead(StatePin);
  if(connection == HIGH && prevConnection == 0){
    prevConnection = true; 
    Serial.println("btConnected"); 
  }else if(connection == LOW && prevConnection == true){
    prevConnection = false;
    //When the connection goes off turn off all the motors
    Serial.println("btDisconnected");
    ESC_0.detach();
    ESC_1.detach();  
    ESC_2.detach();
    ESC_3.detach();
    Serial.println("Motors are turned off");
  }
  
 }

bool checkMotorChar(char c){
  Serial.print("check: " + c);
  return (int)c >= 'a' && (int)c <= 'd';
}
bool checkSpeedChar(char c){
  Serial.print("check: " + c);
  return c == '-' && c == '+';
}

void changeSpeed(String s){
  char motor = s.charAt(0);
  char delta = s.charAt(1);
  switch (motor){
    case 'a': 
    if(delta == '+'){
      Serial.println("ESC0 Speed:: ");
      Serial.print(speed0);
      Serial.print(" -> ");
      Serial.print(checkSpeed(++speed0));
    //ESC_0.write(checkSpeed(++speed0));
    }
    else if (delta == '-'){
       Serial.println("ESC0 Speed:: ");
      Serial.print(speed0);
      Serial.print(" -> ");
      Serial.print(checkSpeed(--speed0));
    //ESC_0.write(checkSpeed(--speed0));
    }
    break;
    case 'b': 
    if(delta == '+'){
        Serial.println("ESC1 Speed:: ");
      Serial.print(speed1);
      Serial.print(" -> ");
      Serial.print(checkSpeed(++speed1));
    //ESC_1.write(checkSpeed(++speed1));
    }
    else if (delta == '-'){
       Serial.println("ESC1 Speed:: ");
      Serial.print(speed1);
      Serial.print(" -> ");
      Serial.print(checkSpeed(--speed1));
    //ESC_1.write(checkSpeed(--speed1));
    }
    break;
    case 'c':
    if(delta == '+'){
       Serial.println("ESC2 Speed:: ");
      Serial.print(speed2);
      Serial.print(" -> ");
      Serial.print(checkSpeed(++speed2));
    //ESC_2.write(checkSpeed(++speed2));
    }
    else if (delta == '-'){
        Serial.println("ESC2 Speed:: ");
      Serial.print(speed2);
      Serial.print(" -> ");
      Serial.print(checkSpeed(--speed2));
    //ESC_2.write(checkSPeed(--speed2));
    }
    break;
    case 'd':
    if(delta == '+'){
         Serial.println("ESC3 Speed:: ");
      Serial.print(speed3);
      Serial.print(" -> ");
      Serial.print(checkSpeed(++speed3));
    //ESC_3.write(checkSpeed(++speed3));
    }
    else if (delta == '-'){
      Serial.println("ESC3 Speed:: ");
      Serial.print(speed3);
      Serial.print(" -> ");
      Serial.print(checkSpeed(--speed3));
    //ESC_3.write(checkSpeed(--speed3));
    }
    break;
    default:
    break;
}
}

//Format "a+"
//first char == motor number
// second char == speed up or down represented by +/-
void loop(){
  connected();
  
if(btSerial.available()){
  d = btSerial.read();
  Serial.println("d: " + d);
  data += d;
  Serial.println("data: " + data);
  
  Serial.println(data.length());
  
  if(data.length()== 2 && checkMotorChar(data.charAt(0)) && checkSpeedChar(data.charAt(1))){
    Serial.println("fucku: " + data);
  changeSpeed(data);
  data = "";
  } else if( data.length() == 2){
    data = "";
  }
    }
  }
  










