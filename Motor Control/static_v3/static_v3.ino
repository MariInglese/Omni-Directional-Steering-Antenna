// confirm functionaity of run_static_mode() using serial input for config
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

// Serial input buffer
String serial_input = "";

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

void run_static_mode(std::string req_config, int current_pos){
  if(req_config == "monopole_config"){
    // N motor is 0
    if(current_pos != 0){
      go_to_0(); 
    }
  }

  if(req_config == "N_config"){
    // N motor is 0
    if(current_pos != 0){
      go_to_0(); 
    }
  }

  if(req_config == "NE_config"){
    // N motor is 0
    if(current_pos != 0){
      go_to_0();
    }
  }
  if(req_config == "E_config"){
    // N motor is 90
    if(current_pos != 90){
      go_to_90();
    }
  }

  if(req_config == "SE_config"){
    // N motor is 90
    if(current_pos != 90){
      go_to_90();
    }
  }

  if(req_config == "S_config"){
    // N motor is 90 
    if(current_pos != 90){
      go_to_90();
    } 
  }

  if(req_config == "SW_config"){
    // N motor is 90 
    if(current_pos != 90){
      go_to_90();
    }
  }

  if(req_config == "W_config"){
    // N motor is 90 
    if(current_pos != 90){
      go_to_90();
    } 
  }

  if(req_config == "NW_config"){
    // N motor is 0
    if(current_pos != 0){
      go_to_0();
    }
  }
}

void setup() {
  pinMode(dir_pin_m1, OUTPUT); 
  pinMode(step_pin_m1, OUTPUT);

  Serial.begin(115200);
  Serial.println("Enter a config:");
}

void loop() {
  // Read serial input character by character
  while(Serial.available() > 0){
    char incoming_char = Serial.read();

    if(incoming_char == '\n'){
      // End of input, process it
      serial_input.trim(); // remove any trailing \r or whitespace

      if(serial_input.length() > 0){
        std::string config = serial_input.c_str(); // convert String to std::string
        Serial.print("Running config: ");
        Serial.println(serial_input);

        run_static_mode(config, m1_pos);

        Serial.print("m1_pos is now: ");
        Serial.println(m1_pos);
      }

      serial_input = ""; // clear buffer for next input
    } else {
      serial_input += incoming_char;
    }
  }
}