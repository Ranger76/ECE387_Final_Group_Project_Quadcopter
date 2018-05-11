/*
 * Copyright Taewoong Won, Takdanai Tantiyartyanontha
 */
 

/********************Libraries**********************/
/***************************************************/

#include <Servo.h>;
#include <SoftwareSerial.h>;

/*****************BLUETOOTH SETUP*******************/
/***************************************************/
// Pins for Bluetooth
const int Tx = 2;
const int Rx = 3;
const int StatePin = 4;

SoftwareSerial btSerial(2,3);

//variables to monitor bluetooth connection
int connection = 0;
bool prevConnection = 0;

//variable to store received data
char d;

/*******************MOTOR SETUP*********************/
/***************************************************/
//Minimum/Base Speed and Maximum Speed for motors
const int baseSpeed = 64;
const int maxSpeed = 73;

//Define servo motors
Servo ESC_0;
Servo ESC_1;
Servo ESC_2;
Servo ESC_3;

//initialize speed of each motors with base speed
int speed0 = baseSpeed;
int speed1 = baseSpeed;
int speed2 = baseSpeed;
int speed3 = baseSpeed;


/********************FUNCTIONS**********************/
/***************************************************/

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
  }}

//Checks for validity of a given input
bool checkChar(char c){
  return (int)c >= 'a' && (int)c <= 'h';
}

//Changes Speed based on data received.
//Commented Lines were used for testing
void changeSpeed(char c){
 int speed;
  switch (c){
    case 'a': 
  
  //    Serial.print("ESC0 Speed:: ");
    //  Serial.print(speed0);
   //   Serial.print(" -> ");
       speed0 = checkSpeed(++speed0);
  //    Serial.print(speed0);
    ESC_0.write(speed0);
        Serial.print(speed0);

    break;
      case 'b':
      
   //   Serial.print("ESC0 Speed:: ");
    //  Serial.print(speed0);
   //   Serial.print(" -> ");
       speed0 = checkSpeed(--speed0);
  //    Serial.print(speed0);
    ESC_0.write(speed0);
        Serial.print(speed0);

    break;
    case 'c': 
    //    Serial.print("ESC1 Speed:: ");
   //   Serial.print(speed1);
   //   Serial.print(" -> ");
      speed1 = checkSpeed(++speed1);
  //    Serial.print(speed1);
    ESC_1.write(speed1);
        Serial.print(speed1);

    break;
   case 'd':
   
  //    Serial.print("ESC1 Speed:: ");
  //    Serial.print(speed1);
  //    Serial.print(" -> ");
       speed1 = checkSpeed(--speed1);
   //   Serial.print(speed1);
    ESC_1.write(speed1);
        Serial.print(speed1);

    break;
    case 'e':
   
   //    Serial.print("ESC2 Speed:: ");
   //   Serial.print(speed2);
   //   Serial.print(" -> ");
       speed2 = checkSpeed(++speed2);
  //    Serial.print(speed2);
    ESC_2.write(speed2);
        Serial.print(speed2);

    break;
    case 'f':
    
      //  Serial.print("ESC2 Speed:: ");
      //Serial.print(speed2);
      //Serial.print(" -> ");
       speed2 = checkSpeed(--speed2);
    //  Serial.print(speed2);
    ESC_2.write(speed2);
    Serial.print(speed2);

    break;
    case 'g':
//     
//      Serial.print("ESC3 Speed:: ");
//      Serial.print(speed3);
//      Serial.print(" -> ");
      speed3 = checkSpeed(++speed3);
//      Serial.print(speed3);
    ESC_3.write(speed3);
    Serial.print(speed3);

    break;
    case 'h':
     speed3 = checkSpeed(--speed3);
//      Serial.print("ESC3 Speed:: ");
//      Serial.print(speed3);
//      speed3 = checkSpeed(--speed3);
//      Serial.print(" -> ");
//      Serial.print(speed3);
    ESC_3.write(speed3);
    Serial.print(speed3);
    break;

    case 'z':
    ESC_0.write(0);
    ESC_1.write(0);
    ESC_2.write(0);
    ESC_3.write(0);
    break;
    default:
    break;
}
}
  

//Checks if a given speed is in range.
//If it exceeds max speed, set the speed to maxSpeed and return maxSpeed
//If it is below minimum speed, set the speed to minSpeed and return minSpeed
int checkSpeed(int i){
  if(i >= baseSpeed && i <= maxSpeed)
  return i;
  else if(i > maxSpeed)
  return maxSpeed;
  else return baseSpeed;
}


/******************SETUP FUNCTION*******************/
/***************************************************/

void setup(void)
{

  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(StatePin,INPUT);
  
  // Set up ESC pins
  ESC_0.attach(6); // Adds ESC;
  ESC_1.attach(9); // Adds ESC;
  ESC_2.attach(10); // Adds ESC;
  ESC_3.attach(11); // Adds ESC;

  ESC_0.write(0);
  ESC_1.write(0);
  ESC_2.write(0);
  ESC_3.write(0);

}


/**********************LOOP*************************/
/***************************************************/

void loop(){
 connected();
  
while (btSerial.available()){
  d = btSerial.read();
changeSpeed(d);
d = ' ';
    }
  }
  










