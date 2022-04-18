/*
 * 
 * ANALOG READING FROM PRESSURE SENSOR.
 */

const int pressurePin = A0;
double pressureVoltage = 0;
double pressurePSI = 0;

void setup() {
  // put your setup code here, to run once:
serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
pressureVoltage = analogRead(pressurePin);
serial.print(pressureVoltage);
}
