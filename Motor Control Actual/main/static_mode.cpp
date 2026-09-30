#include "static_mode.h"
#include "motor_config.h"

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
