#include <avr/sleep.h> 


//const byte interruptPin = 2;   
//volatile byte state = LOW;
//int interruptPin

void setup() {
  
Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(2, INPUT);     // D2 STOP/START
  digitalWrite(2, HIGH);
  bitClear(TIMSK0, 0);  //TC0's interrupt capability is disabled.


}

void loop()
{
  Serial.println("5");
  delay(1000);
  Serial.println("4");
  delay(1000);
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  Serial.println("Zzz");
  delay(1500);
  sleepSetup();
}

void sleepSetup()
{
  sleep_enable();
  attachInterrupt(2, pinInterupt, LOW);  //Nano 33 IoT interrupt pins are 2, 3, 9, 10, 11, A1, A5, A7
  set_sleep_mode(SLEEP_MODE_IDLE);//SLEEP_MODE_STANDBY);//PWR_SAVE);//PWR_DOWN);//IDLE);
 // SMCR = SMCR & 0b00000001;
  digitalWrite(13, LOW);
  sleep_cpu();
  Serial.println("Just woke up!");
//  bitSet(TIMSK0, 0);
  digitalWrite(13, HIGH);
}

void pinInterupt()
{
  sleep_disable();
  detachInterrupt(0);
}
