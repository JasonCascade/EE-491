
/*
 * code to pwm control fan.
 */

const int FanPin = x;
float pwm = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(FanPin, OUTPUT); //setting it as an output.


}

void loop() {
  // put your main code here, to run repeatedly:

pwm = 255; //need equation to determine this value
analogWrite(FanPin, pwm);

}
