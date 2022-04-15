/*
  Extension and retraction without Delay
  ALTERED FROM led BLINK WITHOUT DELAY.
*/

// constants won't change. Used here to set a pin number:
const int ActPin =  5;// pin 5 for output

// Variables will change:
int ActState = LOW;             // 5v pulse

int c1= 0; //Counter to track actuators extentions & retractions. 
double ActFreqOutput = 0;// Rate of oscillation, for calculation purposes
long interval = 1000;           // interval at which to retract/extend (milliseconds) TEMPORARY


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

  Actuator(0,1,1000); //Counter, actuator frequency hz, interval between?
  // INTERVAL will be calculated, basedon desired frequency.
  
}

void Actuator(int counter, double AFO, long i) // counter may not need be passed, since global variable.
{
  unsigned long currM1 = millis();
  //unsigned long currM2 = millis();
 // unsigned long currM3 = millis();

  if (currentMillis - pMillisAct >= i) {
    // save the last time you blinked the LED
    pMillisAct = currentMillis;
    c1++;
    // if the LED is off turn it on and vice-versa:

    /*
     * 
     * MAY need to reimplimant this logic is the proceeding if/else statements
     */

     // dont need to switch between high and low... switch High and low in the  counter..

    /*
    if (ActState == LOW) {
      ActState = HIGH; 
    } else {
      ActState = LOW;
    }
*/
    // Check if iteration is ODD or EVEN
    if(c1%2) //positive value if remainder more than one.. ergo 
    {
      //odd
      digitalWrite(ActPin,HIGH);
      delay(ETime);
      digitalWrite(ActPin,LOW);

    }
    else{ //else, it is even..
      //even
      digitalWrite(ActPin,HIGH);
      delay(RTime);
      digitalWrite(ActPin,LOW);

    }
    // Determine if send to function to extend or retract, based on count. Function will send 2ms or 1 ms pulse. Ergo digital write high and low fast.
   // digitalWrite(ActPin, ActState);
  }
}

void Extend()
{
  
}

void Retract()
{
}

/* PSUEDOCODE
 *  
 *  
 *  change interval, to change frequence of oscillating
 *
 *
 *
 */
