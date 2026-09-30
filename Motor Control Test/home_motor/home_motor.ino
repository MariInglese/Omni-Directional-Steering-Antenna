// MOTOR HOMING SCRIPT -- 360 roatation cw and ccw 

const int DIR_PIN_M1 = 5; 
const int STEP_PIN_M1 = 6;

const int nativeSteps = 20; //360/18 deg per step
const int gearRatio = 100; 
const int microMode = 16; 
const int steps = nativeSteps * gearRatio * microMode;


void setup(){
  pinMode(DIR_PIN_M1, OUTPUT); 
  pinMode(STEP_PIN_M1, OUTPUT); 
}

void loop(){
  // change direction every loop 
  digitalWrite(DIR_PIN_M1, !digitalRead(DIR_PIN_M1)); 

  // toggle STEP to move 
  for(int x = 0; x < steps; x++){
    digitalWrite(STEP_PIN_M1, HIGH); 
    delayMicroseconds(300);
    digitalWrite(STEP_PIN_M1, LOW); 
    delayMicroseconds(300);
  }
  delay(1000); 
}