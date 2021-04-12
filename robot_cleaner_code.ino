//nclude <Servo.h>          
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library


#define motor1Forward 7
#define motor1Backward 6
#define motor2Forward 4
#define motor2Backward 5

#define TrigPin A1 //analog input 1
#define EchoPin A2

#define max_dist 200

boolean goForward = false;
int dist = 100;

NewPing sonar(TrigPin, EchoPin, max_dist);
void setup(){

  pinMode(motor1Forward, OUTPUT);
  pinMode(motor1Backward, OUTPUT);
  pinMode(motor2Forward, OUTPUT);
  pinMode(motor2Backward, OUTPUT);
  
  dist = readPing();
  delay(100);
  dist = readPing();
  delay(100);
  dist = readPing();
  delay(100);
  dist = readPing();
  delay(100);
}

void loop(){
  int distR = 0;
  int distL = 0;
  delay(50);

  if (dist <= 20){
    Stop();
    delay(300);
    Backward();
    delay(400);
    Stop();
    delay(300);

    if (dist >= distL){
      turnRight();
      Stop();
    }
    else{
      turnLeft();
      Stop();
    }
  }
  else{
    Forward(); 
  }
    dist = readPing();
}
int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void Stop(){
  
  digitalWrite(motor2Forward, LOW);
  digitalWrite(motor1Forward, LOW);
  digitalWrite(motor2Backward, LOW);
  digitalWrite(motor1Backward, LOW);
}

void Forward(){
  if(!goForward){
    goForward=true;
    digitalWrite(motor1Forward, HIGH);
    digitalWrite(motor2Forward, HIGH);
  
    digitalWrite(motor1Backward, LOW);
    digitalWrite(motor2Backward, LOW); 
  }
}

void Backward(){
  goForward=false;
  digitalWrite(motor1Backward, HIGH);
  digitalWrite(motor2Backward, HIGH);
  
  digitalWrite(motor1Forward, LOW);
  digitalWrite(motor2Forward, LOW);
}

void turnRight(){
  digitalWrite(motor1Forward, HIGH);
  digitalWrite(motor2Backward, HIGH);
  
  digitalWrite(motor1Backward, LOW);
  digitalWrite(motor2Backward, LOW);
  delay(500);
  digitalWrite(motor1Forward, HIGH);
  digitalWrite(motor2Forward, HIGH);
  
  digitalWrite(motor1Backward, LOW);
  digitalWrite(motor2Backward, LOW);
}

void turnLeft(){
  digitalWrite(motor1Backward, HIGH);
  digitalWrite(motor2Forward, HIGH);
  
  digitalWrite(motor1Forward, LOW);
  digitalWrite(motor2Backward, LOW);
  delay(500);
  digitalWrite(motor1Forward, HIGH);
  digitalWrite(motor2Forward, HIGH);
  
  digitalWrite(motor1Backward, LOW);
  digitalWrite(motor2Backward, LOW);
}
