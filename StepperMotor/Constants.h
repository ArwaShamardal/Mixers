#ifndef H_A
#define H_A

enum switcher {
  ON, // enable
  OFF // disable
};
enum pullDirection {
  UP,  
  DOWN,
  UNDECLARED 
};
const uint8_t mixerMotorPin1 = 2;
const uint8_t mixerMotorPin2 = 3;
const uint8_t pulleyMotorPin1 = 4;
const uint8_t pulleyMotorPin2 = 5;
enum switcher mixerSystemSwitch = ON;

#endif


/*        Motor modes
 * AccelStepper::FULL2WIRE (2) means: 2 wire stepper (2 pins needed). 
 * AccelStepper::FULL3WIRE (3) means: 3 wire stepper, like a harddisk motor (3 pins needed). 
 * AccelStepper::FULL4WIRE (4) means: 4 wire stepper (4 pins needed). 
 * AccelStepper::HALF3WIRE (6) means: 3 wire half stepper, like a harddisk motor (3 pins needed) 
 * AccelStepper::HALF4WIRE (8) means: 4 wire half stepper (4 pins needed) 
 *
 * AccelStepper uses AccelStepper::FULL4WIRE (4 pins needed) by default.
 */
