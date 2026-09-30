// confirm functionaity of run_static_mode() for N motor 
// ASSUME STARTING AT 90 

#include <string>

// Pins 
const int dir_pin_m1 = 5; 
const int step_pin_m1 = 6;

// Motor params 
const int native_steps = 20; // 360/18 deg per step 
const int gear_ratio = 100; 
const int micro_mode = 16; 
const int steps = native_steps * gear_ratio * micro_mode; 

// Motor position tracker (assumes motor starts at 90)
int m1_pos = 90; 

// Functions 
void go_to_0(){
  // ccw for 90 -> 0
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
  // cw for 0 -> 90
  digitalWrite(dir_pin_m1, HIGH);

  for(int x=0; x < steps/4; x++){
    digitalWrite(step_pin_m1, HIGH); 
    delayMicroseconds(300); 
    digitalWrite(step_pin_m1, LOW); 
    delayMicroseconds(300); 
  } 
  m1_pos = 90; 
}

void run_static_mode(std::string req_config, int m1_pos){
  if(req_config == "monopole_config"){
    // N motor is 0 
    if(m1_pos != 0){
      go_to_0(); 
    }
  }

  if(req_config == "N_config"){
    // N motor is 0 
    if(m1_pos != 0){
      go_to_0(); 
    }
  }

  if(req_config == "NE_config"){
    // N motor is 0 
    if(m1_pos != 0){
      go_to_0();
    }
  }
  if(req_config == "E_config"){
    // N motor is 90
    if(m1_pos != 90){
      go_to_90();
    }
  }

  if(req_config == "SE_config"){
    // N motor is 90 
    if(m1_pos != 90){
      go_to_90();
    }
  }

  if(req_config == "S_config"){
    // N motor is 90
    if(m1_pos != 90){
      go_to_90();
    } 
  }

  if(req_config == "SW_config"){
    // N motor is 90 
    if(m1_pos != 90){
      go_to_90();
    }
  }

  if(req_config == "W_config"){
    // N motor is 90
    if(m1_pos != 90){
      go_to_90();
    } 
  }

  if(req_config == "NW_config"){
    // N motor is 0
    if(m1_pos != 0){
      go_to_0();
    }
  }
}

void setup() {
  pinMode(dir_pin_m1, OUTPUT); 
  pinMode(step_pin_m1, OUTPUT);

  run_static_mode("NW_config", m1_pos); 
}

void loop() {
}
