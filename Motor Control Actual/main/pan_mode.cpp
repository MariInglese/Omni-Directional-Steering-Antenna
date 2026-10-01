#include "pan_mode.h"
#include "motor_config.h"

void run_pan_mode(int hold_time_ms, int current_pos){
// monopole, N, NE, E, SE, S, SW, W, NW

// monopole - N motor 0 
if(current_pos != 0){
  go_to_0(); 
}
delay(hold_time_ms);

// N - N motor 0 
delay(hold_time_ms);

// NE - N motor 0
delay(hold_time_ms);

// E - N motor 90
go_to_90(); 
delay(hold_time_ms);

// SE - N motor 90 
delay(hold_time_ms);

// S - N motor 90 
delay(hold_time_ms);

// SW - N motor 90
delay(hold_time_ms);

// W - N motor 90 
delay(hold_time_ms);

// NW - N motor 0 
go_to_0(); 
delay(hold_time_ms);
}