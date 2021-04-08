#define ACTIVATE_MOTOR1 2
#define INPUT_MOTOR1 3
#define INPUT2_MOTOR1 4

#define ACTIVATE_MOTOR2 8
#define INPUT_MOTOR2 9
#define INPUT2_MOTOR2 10

#define TrigPin 7
#define EchoPin 6

#include <Servo.h>

Servo servoM;

void initializeMotor(int activationPin, int pin1, int pin2)
{
    pinMode(activationPin, OUTPUT);
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
  
    digitalWrite(activationPin, HIGH); 
}
void runMotor(int pin1, int pin2, bool clockwise = true)
{
    if (clockwise) {
        // Run the motor clockwise
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    } else {
        // Run the motor counter-clockwise
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    }
}
void setup()
{ 
    pinMode(EchoPin, INPUT);
    pinMode(TrigPin, OUTPUT);
    servoM.attach(11);
    servoM.write(0);
    initializeMotor(ACTIVATE_MOTOR1, INPUT_MOTOR1, INPUT2_MOTOR1);
    initializeMotor(ACTIVATE_MOTOR2, INPUT_MOTOR2, INPUT2_MOTOR2);
}
void servo(){
  servoM.write(120);
  delay(100);
  servoM.write(0);
}
void Trig(){
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
}

void left(){
  runMotor(INPUT_MOTOR1, INPUT2_MOTOR1, true);
  runMotor(INPUT_MOTOR2, INPUT2_MOTOR2, false);
}

void right(){
  runMotor(INPUT_MOTOR1, INPUT2_MOTOR1, false);
  runMotor(INPUT_MOTOR2, INPUT2_MOTOR2, true);
}

void forward(){
  runMotor(INPUT_MOTOR1, INPUT2_MOTOR1, true);
  runMotor(INPUT_MOTOR2, INPUT2_MOTOR2, true);
}

void backward(){
  runMotor(INPUT_MOTOR1, INPUT2_MOTOR1, false);
  runMotor(INPUT_MOTOR2, INPUT2_MOTOR2, false);
}  
void loop()
{
    forward();
   delay(500);
    servo();
   delay(500);
    forward();
    delay(500);
    servo();
    Trig();
  
    int  distance;
    int duration;
    duration = pulseIn(EchoPin, HIGH);
    distance = duration*0.034/2; 
  
  if(distance >= 20){
      
      forward();
    }
  else{
    backward();
    delay(3000);
    left();
    delay(200);
    forward();
    }
}
