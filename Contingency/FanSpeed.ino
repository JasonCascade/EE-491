// Start at low speed. Push button > switch to next speed. Only 3 modes. If on mode 3, if button press, then go back to first mode.
const int speedButton 3;
const int currentOut 5;
volatile int state = 0;
bool buttonState = LOW;

void buttonPressed();


void setup() {
  pinMode(currentOut, OUTPUT);
  pinMode(speedButton, INPUT);
  attachInterrupt(speedButton, buttonPressed, RISING);
}

void loop() {
  //if state 0, output certain current/voltage
  if(state == 0) {
    digitalWrite(currentOut, LOW); //maybe switch to analogWrite
    delay(100);
  }
  //if state 1, output certain current/voltage
  if(state == 1) {
    
  }
  //if state 2, output certain current/voltage
  if(state == 2) {
    
  }
  //if state 3, output certain current/voltage
  if(state == 3) {
    
  }
  //else if state 4, set state back to 0
  else if(state == 4) {
    state = 0;
  }
  
}

void buttonPressed() {
  state++;
}
