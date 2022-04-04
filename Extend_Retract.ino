/*
  Extension and retraction without Delay

  ALTERED FROM led BLINK WITHOUT DELAY.
*/

// constants won't change. Used here to set a pin number:
const int Actuator =  5;// pin 5 for output

// Variables will change:
int ActuatorState = LOW;             // 5v pulse

int ExtendTime = 2;

int RetractTime = 1;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(Actuator, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ActuatorState == LOW) {
      ActuatorState = HIGH;
    } else {
      ActuatorState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(Actuator, ActuatorState);
  }
}
