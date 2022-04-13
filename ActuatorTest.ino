
const int ActPin = 5;


void setup() {
  // put your setup code here, to run once:
pinMode(ActPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

delay (500);

digitalWrite(ActPin, HIGH);
delay(2);
digitalWrite(ActPin, LOW);

delay(1000);

digitalWrite(ActPin, HIGH);
delay(1);
digitalWrite(ActPin, LOW);

}
