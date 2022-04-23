/*
  Extension and retraction without Delay
  ALTERED FROM led BLINK WITHOUT DELAY.
*/

// constants won't change. Used here to set a pin number:
const int ActPin =  5;// pin 5 for output

//MAY NOT BE NEEDED
int ActState = LOW;      //To send 5v pulse

int c1= 0; //Counter to track actuators extentions & retractions. 
long interval = 1000; // interval at which to retract/extend (milliseconds)


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long preM1 = 0;        // store previous history of time. bro.
//unsigned long preM2 = 0;//for 2ms pulse
//unsigned long preM3 = 0;// for 3ms pulse 

// constants won't change:
const long ETime = 2; //2ms pulse to Extend
const long RTime = 1; //1ms pulse to Retract



void setup() {
  // set the digital pin as output:
  pinMode(ActPin, OUTPUT);

  //Setting Actuator to begin in the retracted state.
  digitalWrite(ActPin, HIGH);
  delay(RTime);
  digitalWrite(ActPin,LOW);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  Actuator(1000); //Counter, actuator frequency hz, interval between?
  // INTERVAL will be calculated, basedon desired frequency.
  
}

void Actuator(long i){
  unsigned long currM1 = millis();
  //unsigned long currM2 = millis();
 // unsigned long currM3 = millis();

  if (currM1 - preM1 >= i) {
    // save the last time you blinked the LED
    preM1 = currM1;
    c1++;
    
    // Check if iteration is ODD or EVEN
    if(c1%2) //positive value if remainder more than one.. ergo 
    {
      //odd
      digitalWrite(ActPin,HIGH);
      delay(ETime); // 2ms to extend
      digitalWrite(ActPin,LOW);

    }
    else{ //else, it is even..
      //even
      digitalWrite(ActPin,HIGH);
      delay(RTime); // 1 ms to retract
      digitalWrite(ActPin,LOW);

    }

  }
}

