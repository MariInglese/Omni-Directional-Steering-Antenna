// confirm functionality of go_to_90() and go_to_0()

// Pins 
const int dir_pin_m1 = 5; 
const int step_pin_m1 = 6;

// Motor params 
const int native_steps = 20; // 360/18 deg per step 
const int gear_ratio = 100; 
const int micro_mode = 16; 
const int steps = native_steps * gear_ratio * micro_mode; 

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
}

void setup() {
  pinMode(dir_pin_m1, OUTPUT); 
  pinMode(step_pin_m1, OUTPUT);

  go_to_0(); 

  delay(2000); 

  go_to_90(); 
}

void loop() {
}
