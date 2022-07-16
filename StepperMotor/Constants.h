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

const unsigned long jellyMixingDuration = 8000UL;
const unsigned long cakeMixingDuration = 15000UL;
unsigned long previousMillis = 0UL;

enum switcher mixerSystemSwitch = ON;

#endif
