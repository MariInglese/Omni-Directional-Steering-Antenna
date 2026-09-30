#include "motor_config.h"

const int dir_pin_m1 = 5; 
const int step_pin_m1 = 6; 

const int native_steps = 20; 
const int gear_ratio = 100;  
const int micro_mode = 16; 
const int steps = native_steps * gear_ratio * micro_mode; 

int m1_pos = 90; 

void go_to_0(){
  digitalWrite(dir_pin_m1, LOW);

  for(int x=0; x < steps/4; x++){
    digitalWrite(step_pin_m1, HIGH);
    delayMicroseconds(300);
    digitalWrite(step_pin_m1, LOW);
    delayMicroseconds(300);
  }
  m1_pos = 0;
}

void go_to_90(){
  digitalWrite(dir_pin_m1, HIGH);

  for(int x=0; x < steps/4; x++){
    digitalWrite(step_pin_m1, HIGH);
    delayMicroseconds(300);
    digitalWrite(step_pin_m1, LOW);
    delayMicroseconds(300);
  }
  m1_pos = 90;
}
