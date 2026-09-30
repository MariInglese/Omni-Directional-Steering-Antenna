#include "motor_config.h"
#include "static_mode.h"
#include "pan_mode.h"
#include "search_mode.h"

String serial_input = ""; 
std::string mode = "static"; 

void setup(){
  pinMode(dir_pin_m1, OUTPUT); 
  pinMode(step_pin_m1, OUTPUT);

  if(mode == "static"){
    Serial.begin(115200);
    Serial.println("Enter a config:");
  }
}

void loop(){
  if(mode == "static"){
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
      } 
      else {
        serial_input += incoming_char;
      }
    }
  }
}


