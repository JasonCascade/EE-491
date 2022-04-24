// Start at low frequency > Push button > medium frequency > push button > high frequency > push button > back to low frequency
const int freqButton = 19;
//const int freqOut = 5;
volatile int state = 0;
bool buttonState = LOW;

/*
 * FAN STUFF BELOW.
 */

const int FanPin = 5;
float pwm = 255;
//float Off = 0;

const long interval_0= 1000;
const long interval_1= 3000;
unsigned long previousMillis = 0;
long int c1 = 1;

void buttonPressed();

void setup() {
 // pinMode(freqOut, OUTPUT);
  pinMode(freqButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(freqButton), buttonPressed, RISING);
  pinMode(FanPin, OUTPUT); //setting it as an output.

}

void loop() {
    unsigned long currentMillis = millis();
  //if state 0, frequency calculation is set to low
  if(state == 0) {
     if (currentMillis - previousMillis >= interval_0) {
      previousMillis = currentMillis;
      analogWrite(FanPin, pwm);
          // if the LED is off turn it on and vice-versa:
      if (pwm == 80) {
        pwm = 255;
      } else {
        pwm = 80;
      }
    }
  }
  //if state 1, frequency calculation is set to medium
  if(state == 1) {

  // Check if iteration is ODD or EVEN
    if(c1%2) //positive value if remainder more than one.. ergo
    {
      if (currentMillis - previousMillis >= interval_0) {
        c1++;
        previousMillis = currentMillis;
        pwm = 80;
        analogWrite(FanPin, pwm);

      }
    }
    else{ //else, it is even..
      //even
       if(currentMillis - previousMillis >= interval_1)
      {
        c1++;
        previousMillis = currentMillis;
        pwm = 255;
        analogWrite(FanPin, pwm);

      }
    }
     
    
    }
  //else if state 2, set state back to 0
  else if(state == 2) {
    state = 0;
  }

}

void buttonPressed() {  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  //If interrupts >80, assume bounce and ignore.
  if( interrupt_time - last_interrupt_time > 200)
  {
    state++;
  }
  last_interrupt_time = interrupt_time;
}
