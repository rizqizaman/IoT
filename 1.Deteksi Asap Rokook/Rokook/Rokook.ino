#include <MQ2.h>
const int pinmq2 = A0;
int LPG, CO, Smoke;
MQ2 mq2(pinmq2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mq2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float nilai = mq2.read(true);
  LPG = mq2.readLPG();
  CO = mq2.readCO();
  Smoke = mq2.readSmoke();

  Serial.print("Nilai Sensor : ");
  Serial.println(nilai);
//  Serial.print("Nilai SMOKE : ");
//  Serial.println(Smoke);
  delay(1000);
}
