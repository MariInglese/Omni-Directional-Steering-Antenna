#ifndef MOTOR_CONFIG_H
#define MOTOR_CONFIG_H

#include <Arduino.h>

// Pins 
extern const int dir_pin_m1; 
extern const int step_pin_m1; 

// Motor params 
extern const int steps; 

// Motor position tracker 
extern int m1_pos; 

// Motor movement helper functions 
void go_to_0(); 
void go_to_90(); 

#endif 
