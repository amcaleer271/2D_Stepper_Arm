#include <AccelStepper.h>


//Defining pins
int Stepper1Pulse = 2;  // Pulse or step pin
int Stepper1Direction = 3;  // Direction pin

int Stepper2Pulse = 5;
int Stepper2Direction = 6;

int Stepper1Switch = 7;
int Stepper2Switch = 8;

AccelStepper step1(1, Stepper1Pulse, Stepper1Direction);
AccelStepper step2(1, Stepper2Pulse, Stepper2Direction);

void setup() {               
   
  Serial.begin(9600);
  
  step1.setMaxSpeed(400);   //max attainable speed is 1200
  step1.setSpeed(400);
  step1.setAcceleration(500);
  pinMode(Stepper1Pulse, OUTPUT);
  pinMode(Stepper1Direction, OUTPUT);
  digitalWrite(Stepper1Pulse, LOW);
  digitalWrite(Stepper1Direction, HIGH);

  step2.setMaxSpeed (1000);   //max attainable speed is 1200
  step2.setSpeed(1000);
  step2.setAcceleration(0);
  pinMode(Stepper2Pulse, OUTPUT);
  pinMode(Stepper2Direction, OUTPUT);
  digitalWrite(Stepper2Pulse, LOW);
  digitalWrite(Stepper2Direction, HIGH);
  delay(1000);

  pinMode(Stepper1Switch, INPUT);
  pinMode(Stepper2Switch, INPUT);

//Homing Process

  delay(2000);

  step1.moveTo(-10000);
  while(digitalRead(Stepper1Switch)==HIGH){
    step1.run();
    delayMicroseconds(400);
  }
  step1.stop();
  step1.setCurrentPosition(0);

  Serial.println("Stepper 1 Home Set");

  step2.moveTo(10000);
    while(digitalRead(Stepper2Switch)==HIGH){
      step2.run();
      delayMicroseconds(400);
    }
    step2.stop();
    step2.setCurrentPosition(0);

    Serial.println("Stepper 2 Home Set");
    step2.setCurrentPosition(0);
  
  Serial.println("Stepper 2 Home Set");

  step1.setMaxSpeed(600);
  step1.setSpeed(600);
  step2.setMaxSpeed(600);
  step2.setSpeed(600);

}

void loop() {
  // step1.runToNewPosition(-90*15/1.8);
  // delay(1000);


  // step2.runToNewPosition(90*15/1.8);
  // delay(1000);

}




