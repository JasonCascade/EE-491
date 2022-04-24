// Start at low speed. Push button > switch to next speed. Only 3 modes. If on mode 3, if button press, then go back to first mode.
const int speedButton = 3;
const int voltOut = 5;
volatile int state = 0;
bool buttonState = LOW;
float pwm = 0;

void buttonPressed();


void setup() {
  pinMode(voltOut, OUTPUT);
  pinMode(speedButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(speedButton), buttonPressed, RISING);
  Serial.begin(9600);
}

void loop() {
  //if state 0, output certain current/voltage
  if(state == 0) {
    //Fan speed at 40%
    pwm = 102;
    analogWrite(voltOut, pwm);
    delay(100);
    Serial.print("State: ");
    Serial.println(state);
  }
  //if state 1, output certain current/voltage
  if(state == 1) {
    //Fan speed at 60%
    pwm = 153;
    analogWrite(voltOut, pwm); 
    Serial.print("State: ");
    Serial.println(state); 
  }
  //if state 2, output certain current/voltage
  if(state == 2) {
    //Fan speed at 100%
    pwm = 255;
    analogWrite(voltOut, pwm); 
    Serial.print("State: ");
    Serial.println(state); 
  }
  //if state 3, output certain current/voltage
  else if(state == 3) {
    //Set fan back to 20%
    state = 0;
    Serial.println(state);
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
