/*
 * 
 * ANALOG READING FROM PRESSURE SENSOR.
 */

const int pressurePin = A0;
double pressureVoltage = 0;
double sensorVal = 0;
double pressurePSI = 0;

void setup() {
  // put your setup code here, to run once:
serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorVal = analogRead(pressurePin);
pressureVoltage = sensorVal * (12.0/1023.0); // convert analog reading, to 0-5volts
serial.print(pressureVoltage);
}
