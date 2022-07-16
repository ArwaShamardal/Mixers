#include "Constants.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(mixerMotorPin1, OUTPUT);
  pinMode(mixerMotorPin2, OUTPUT);
  pinMode(pulleyMotorPin1, OUTPUT);
  pinMode(pulleyMotorPin2, OUTPUT);
}

void loop() {
  unsigned long foodDuration = cakeMixingDuration; // To be changed accordingly
  foodMixer(foodDuration);
  myDelay(1000UL);             // to be removed
}


void foodMixer(unsigned long cookingTime){
  if(mixerSystemSwitch == ON){
  // This part os for pulling down the mixer
  Serial.println("Pulling down");
  motorEnabler(pulleyMotorPin1,pulleyMotorPin2, ON, DOWN);
  myDelay(1000UL); // to be changed according to the speed


  //This part is for mixing the ingredients
  Serial.println("Mixing");
  motorEnabler(pulleyMotorPin1,pulleyMotorPin2, OFF, UNDECLARED);
  motorEnabler(mixerMotorPin1,mixerMotorPin2, ON, UNDECLARED);
  myDelay(cookingTime); // determined according to the time needed for the food selected


  //This part is for pulling up the mixer  
  Serial.println("Pulling up");
  motorEnabler(mixerMotorPin1,mixerMotorPin2, OFF, UNDECLARED);
  motorEnabler(pulleyMotorPin1,pulleyMotorPin2, ON, UP);
  myDelay(1200UL); // to be changed according to the speed

  //System shutting down
  Serial.println("system turining off");
  motorEnabler(pulleyMotorPin1,pulleyMotorPin2, OFF, UNDECLARED);
  mixerSystemSwitch = OFF;
  }
}


void motorEnabler(uint8_t motorPin1,uint8_t motorPin2, enum switcher switcher, enum pullDirection pullDirection){
  if(switcher == ON){
    if(pullDirection == UP || pullDirection == UNDECLARED){
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
    }
    else if(pullDirection == DOWN){
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);  
    }
  }
  else if (switcher = OFF){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
}


void myDelay(unsigned long milliSeconds){
  previousMillis = millis();
  bool finished = false;
  unsigned long currentMillis;
  while (!finished){
    currentMillis = millis();
    
    if(currentMillis - previousMillis > milliSeconds)
    {
      finished = true;
    }  
  }
}