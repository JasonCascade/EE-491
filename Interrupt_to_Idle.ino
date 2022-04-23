const int sleepPin = 2;
const int voltOut = 5;
volatile int state = 0;
bool buttonState = LOW;
float pwm = 255;

void buttonPressed();

void setup() {
  // put your setup code here, to run once:
  pinMode(voltOut, OUTPUT);
  pinMode(sleepPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sleepPin), buttonPressed, RISING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(state == 0) {
    pwm = 255;
    Serial.println("Running");
  }
  if(state == 1) {
    pwm = 0;
    Serial.println("Idle");
  }
  else if(state > 1) {
    state = 0;
  }
}

void buttonPressed() {

  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  //If interrupts >200, assume bounce and ignore.
  if( interrupt_time - last_interrupt_time > 200)
  {
    state++;
  }
  last_interrupt_time = interrupt_time;
  
}
