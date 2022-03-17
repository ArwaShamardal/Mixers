/*
 * 28BYJ-48 stepper motor with ULN2003A driver
 */

#include <AccelStepper.h>           // Load the AccelStepper library
#include "Constants.h"

int numberOfRevolutions = 2;
int maximumSpeed = 100;
int acceleration = 100;
int currentSpeed = 200;



AccelStepper stepper(AccelStepper::HALF4WIRE, motorPin1, motorPin3, motorPin2, motorPin4);   // Intitialization of Module

void setup() {
  Serial.begin(9600);               // initialise the serial monitor

  stepper.setMaxSpeed(maximumSpeed);      // set the max motor speed
  stepper.setAcceleration(acceleration);   // set the acceleration
  stepper.setSpeed(currentSpeed);            // set the current speed

  stepper.moveTo(SetNumberOfRevolutions(numberOfRevolutions));   // order the motor to rotate 90 degrees forward

}

void loop() {
  stepper.run();                    // start moving the motor
}

/*
 * Converts degrees to steps
 * 
 * 28BYJ-48 motor has 5.625 degrees per step
 * 360 degrees / 5.625 = 64 steps per revolution
 * 
 * Example with degToSteps(45):
 * (64 / 5.625) * 45 = 512 steps
 */
float SetNumberOfRevolutions(float revolutions) {
  return (stepPerRevolution / degreePerStep) * revolutions * 360;
}
