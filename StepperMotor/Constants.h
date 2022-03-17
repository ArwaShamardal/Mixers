#ifndef H_A
#define H_A

#define motorPin1  8                // IN1 pin on the ULN2003A driver
#define motorPin2  9                // IN2 pin on the ULN2003A driver
#define motorPin3  10               // IN3 pin on the ULN2003A driver
#define motorPin4  11               // IN4 pin on the ULN2003A driver


int stepPerRevolution = 64;        // steps per revolution
float degreePerStep = 5.625;  // degree per revolution

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
