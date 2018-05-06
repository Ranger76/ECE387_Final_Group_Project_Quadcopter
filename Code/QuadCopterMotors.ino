/*
 * Copyright Takdanai Tantiyartyanontha, Taewoong Won
 */
 
//Code is currently setup for testing via serial monitor. To actually run the motors,
//comment out Serial.print statements and remove comments in function void setup() and void changeSpeed()
//14,3,66639  address of Sam's HC-05


#include <Servo.h>;
#include <SoftwareSerial.h>;

//Minimum/Base Speed and Maximum Speed for motors
const int baseSpeed = 64;
const int maxSpeed = 70;

// Pins for Bluetooth
const int Tx = 2;
const int Rx = 3;
const int StatePin = 4;

//Setup Bluetooth Module
// HC-06 should be used.
SoftwareSerial btSerial(2,3);

//Define servo motors
Servo ESC_0;
Servo ESC_1;
Servo ESC_2;
Servo ESC_3;

//variables to monitor bluetooth connection
int connection = 0;
bool prevConnection = 0;

//variable to store received data
char d;

//speed of each motors
int speed0 = baseSpeed;
int speed1 = baseSpeed;
int speed2 = baseSpeed;
int speed3 = baseSpeed;

//Checks if a given speed is in range
int checkSpeed(int i){
  if(i >= baseSpeed && i <= maxSpeed)
  return i;
  else if(i > maxSpeed)
  return maxSpeed;
  else return baseSpeed;
}

void setup(void)
{

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

bool checkChar(char c){
  return (int)c >= 'a' && (int)c <= 'h';
}


void changeSpeed(char c){
 int speed;
  switch (c){
    case 'a': 
  
      Serial.print("ESC0 Speed:: ");
      Serial.print(speed0);
      Serial.print(" -> ");
       speed0 = checkSpeed(++speed0);
      Serial.print(speed0);
    //ESC_0.write(speed0);
    break;
      case 'b':
      
      Serial.print("ESC0 Speed:: ");
      Serial.print(speed0);
      Serial.print(" -> ");
       speed0 = checkSpeed(--speed0);
      Serial.print(speed0);
    //ESC_0.write(speed0);
    
    break;
    case 'c': 
        Serial.print("ESC1 Speed:: ");
      Serial.print(speed1);
      Serial.print(" -> ");
      speed1 = checkSpeed(++speed1);
      Serial.print(speed1);
    //ESC_1.write(speed1);
    break;
   case 'd':
   
       Serial.print("ESC1 Speed:: ");
      Serial.print(speed1);
      Serial.print(" -> ");
       speed1 = checkSpeed(--speed1);
      Serial.print(speed1);
    //ESC_1.write(speed1);
    
    break;
    case 'e':
   
       Serial.print("ESC2 Speed:: ");
      Serial.print(speed2);
      Serial.print(" -> ");
       speed2 = checkSpeed(++speed2);
      Serial.print(speed2);
    //ESC_2.write(speed2);
    break;
    case 'f':
    
        Serial.print("ESC2 Speed:: ");
      Serial.print(speed2);
      Serial.print(" -> ");
       speed2 = checkSpeed(--speed2);
      Serial.print(speed2);
    //ESC_2.write(speed2);
    break;
    case 'g':
     
      Serial.print("ESC3 Speed:: ");
      Serial.print(speed3);
      Serial.print(" -> ");
      speed3 = checkSpeed(++speed3);
      Serial.print(speed3);
    //ESC_3.write(speed3);
    break;
    case 'h':
     speed3 = checkSpeed(--speed3);
      Serial.print("ESC3 Speed:: ");
      Serial.print(speed3);
      speed3 = checkSpeed(--speed3);
      Serial.print(" -> ");
      Serial.print(speed3);
    //ESC_3.write(speed3);
    
    break;
    default:
    break;
}
}


void loop(){
  connected();
  
while (btSerial.available()){
  d = btSerial.read();
if(checkChar(d))
changeSpeed(d);
d = ' ';
    }


  }
  










