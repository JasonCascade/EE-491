
/*
 * code to pwm control fan.
 * Turno
 */

const int FanPin = 7;
float pwm1 = 255;
float pwm2 = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(FanPin, OUTPUT); //setting it as an output.


}

void loop() {
  // put your main code here, to run repeatedly:

//need equation to determine this value
analogWrite(FanPin, );

}
/*
 * Need fan to turn on and off to show frequency change.
 * 
 * 
 * 
 * 
 */
