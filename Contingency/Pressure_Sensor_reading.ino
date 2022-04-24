/*
 * 
 * ANALOG READING FROM PRESSURE SENSOR.
 */

const int pressurePin = A0;
double pressureVoltage = 0;
double sensorVal = 0;
double pressurePSI = 0;

/*
 * FAN stuff
 */
 const int FanPin = 5;
 float pwm = 255;

void setup() {
  // put your setup code here, to run once:
 pinMode(FanPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

sensorVal = analogRead(pressurePin);
pressureVoltage = sensorVal * (12.0/1023.0); // convert analog reading, to 0-5volts
Serial.print(pressureVoltage);

  if(pressureVoltage > 8)
  {
    analogWrite(FanPin, 50);
  }
  else
  {
    analogWrite(FanPin,255);
  }
}
