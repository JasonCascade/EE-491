int PressureChangePin = 3;
int state = 0;

void changeState(state, PressureChangePin) {
   state++; 
}

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(PressureChangePin, changeState, RISING);
  
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
