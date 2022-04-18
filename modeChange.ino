//MODES: Normal, Ramp, Random...
//Start normal mode > Button press > Ramp mode > Button Press > Random mode > Button press > Back to normal mode
const int modeButton 10;
volatile int state = 0;
bool buttonState = LOW;

void buttonPressed();
void normalMode();
void rampMode();
void randomMode();

void setup() {
  pinMode(modeButton, INPUT);
  attachInterrupt(modeButton, buttonPressed, RISING);
}

void loop() {
  //if state 0, mode set to normal
  if(state == 0) {
    
  }
  //if state 1, mode set to ramp
  if(state == 1) {
    
  }
  //if state 2, mode set to random
  if(state == 2) {
    
  }
  //else if state 3, mode set back to normal
  else if(state == 3) {
    state = 0;
  }
  
}

void buttonPressed() {
  state++;
}

void normalMode(){
  
}

void rampMode(){
  
}

void randomMode(){
  
}
