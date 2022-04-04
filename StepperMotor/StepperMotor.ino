// Assume that pulling up/down the mixer takes 5 seconds
// Assume that any recipe takes 3 seconds to be mixed

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
  // put your main code here, to run repeatedly:   

if(mixerSystemSwitch == ON){
  // This part os for pulling down the mixer
  Serial.println("Pulling down");
  motorEnabler(pulleyMotorPin1,pulleyMotorPin2, ON, DOWN);
  delay(5000); // to be changed


  //This part is for mixing the ingredients
  Serial.println("Mixing");
  motorEnabler(pulleyMotorPin1,pulleyMotorPin2, OFF, UNDECLARED);
  motorEnabler(mixerMotorPin1,mixerMotorPin2, ON, UNDECLARED);
  delay(3000); // to be changed


  //This part is for pulling up the mixer  
  Serial.println("Pulling up");
  motorEnabler(mixerMotorPin1,mixerMotorPin2, OFF, UNDECLARED);
  motorEnabler(pulleyMotorPin1,pulleyMotorPin2, ON, UP);
  delay(5000); // to be changed

  //System shutting down
  Serial.println("system turining off");
  motorEnabler(pulleyMotorPin1,pulleyMotorPin2, OFF, UNDECLARED);
  mixerSystemSwitch = OFF;

}

  delay(1000);             // to be removed
  Serial.println("Done");  // to be removed
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
