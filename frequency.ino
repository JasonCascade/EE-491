//D9 pin for frequency change
int frequencypin = 9;
volatile int freqstate = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(frequencypin,INPUT);
attachInterrupt(digitalPinToInterrupt(frequencypin),freq_change,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void freq_change() { 
 freqstate = freqstate++;
 if(freqstate==4)
 {
  freqstate = 0;
 }
}
