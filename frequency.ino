// Start at low frequency > Push button > medium frequency > push button > high frequency > push button > back to low frequency
const int freqButton 3;
const int freqOut 5;
volatile int state = 0;
bool buttonState = LOW;

void buttonPressed();

void setup() {
  pinMode(freqOut, OUTPUT);
  pinMode(freqButton, INPUT);
  attachInterrupt(freqButton, buttonPressed, RISING);
}

void loop() {
  //if state 0, frequency calculation is set to low
  if(state == 0) {
    //Calculation: #times of oscillation/length of time
    delay(100);
  }
  //if state 1, frequency calculation is set to medium
  if(state == 1) {
    
  }
  //if state 2 frequency calculation is set to high
  if(state == 2) {
    
  }
  //else if state 3, set state back to 0
  else if(state == 3) {
    state = 0;
  }
  
}

void buttonPressed() {
  state++;
}
