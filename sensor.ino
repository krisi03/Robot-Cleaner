#define ledPin 13
#define trigPin 7
#define EchoPin 9

void setup() {
  pinMode (ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(EchoPin,OUTPUT);
  int value;
int Time;
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
int value;
int Time;
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  Time = pulseIn(EchoPin, HIGH);
  value= Time*0.034/2;
  

  
  if (value <=1){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  
  
}
