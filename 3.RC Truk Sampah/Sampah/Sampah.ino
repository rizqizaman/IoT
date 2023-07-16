#include <ESP32Servo.h>
Servo myservo1, myservo2, myservo3;
const int In1 = 18, In2 = 19, In3 = 21, In4 = 22;
int kecepatan = 100;

#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("ESP32Test");
  Serial.print("The Device Started");
  myservo1.attach(13);
  myservo2.attach(12);
  myservo3.attach(14);  
  pinMode(In1, OUTPUT); 
  pinMode(In2, OUTPUT); 
  pinMode(In3, OUTPUT); 
  pinMode(In4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    BT.write(Serial.read());
  }
  if(BT.available() >= 2){
    unsigned int servopos  = BT.read();
    unsigned int servopos1 = BT.read();
    unsigned int real = (servopos1*256) +servopos;
    Serial.print(real);
    Serial.println("");
    Serial.println("");
    int servo = real;
    Serial.println(servo);
    if (real == 12593){
      Serial.print("Mobil Maju");
      analogWrite(In1, kecepatan);
      digitalWrite(In2, 0);
      digitalWrite(In3, 0);
      analogWrite(In4, kecepatan);
      delay(50);
    }
    if (real == 13107){
      Serial.print("Mobil Mundur");
      analogWrite(In2, kecepatan);
      digitalWrite(In4, 0);
      digitalWrite(In1, 0);
      analogWrite(In3, kecepatan);
      delay(50);
    }
    if (real == 13621){ //719104
      Serial.print("Mobil Berhenti");
      analogWrite(In1, 0);
      analogWrite(In3, 0);
      analogWrite(In2, 0);
      analogWrite(In4, 0);
      delay(50);
    }
    if (real == 12850){ //640000
      Serial.print("Belok Kanan");
      analogWrite(In1, kecepatan);
      digitalWrite(In2, 0);
      analogWrite(In3, kecepatan);
      digitalWrite(In4, 0);
      delay(50);
    }
    if (real == 13364){ //692224
      Serial.print("Belok Kiri");
      digitalWrite(In1, 0);
      analogWrite(In2, kecepatan);
      digitalWrite(In3, 0);
      analogWrite(In4, kecepatan);
      delay(50);
    }
    if(real >= 1000 && real < 1180){
      int servo1 = real;
      servo1 = map(servo1, 1000,1180,0,180);
      servo1 = map(servo1, 0,180,180,0);
      myservo1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
    }
    if(real >= 2000 && real < 2180){
      int servo2 = real;
      servo2 = map(servo2, 2000,2180,0,180);
      servo2 = map(servo2, 0,180,180,0);
      myservo2.write(servo2);
      Serial.println("Servo 2 ON");
      delay(10);
    }
    if(real >= 3000 && real < 3180){
      int servo3 = real;
      servo3 = map(servo3, 3000,3180,0,180);
//      servo3 = map(servo3, 0,180,180,0);
      myservo3.write(servo3);
      Serial.println("Servo 3 ON");
      delay(10);
    }
    
    Serial.write(BT.read());
  }

  delay(20);
}

//void buang(){
//  naikturunservo.attach(pin);
//  for(pos = 35; pos <= 150; pos += 1){
//    naikturunservo.write(pos)
//    delay(5);
//  }
//  naikturunservo.detach();
//  delay(2000);
//}
//
//void simpan(){
// naikturunservo.attach(pin_naikturun);
// for (pos = 150; pos >= 35; pos -= 1) {
// naikturunservo.write(pos);
// delay(5);
// }
// naikturunservo.detach();
// delay(2000);
//}
//
//void masuk(){
// bukatutupservo.attach(pin_keluarmasuk);
// for (pos = 30; pos <= 130; pos += 1) {
// bukatutupservo.write(pos);
// delay(5);
// }
// bukatutupservo.detach();
// delay(2000);
//}
//void keluar(){
// bukatutupservo.attach(pin_keluarmasuk);
// for (pos = 130; pos >= 30; pos -= 1) {
// bukatutupservo.write(pos);
// delay(5);
// }
// naikturunservo.detach();
// delay(2000);
//}
//
//void tutup(){
// bukatutupservo.attach(pin_bukatutup);
// for (pos = 0; pos <= 53; pos += 1) {
// bukatutupservo.write(pos);
// delay(5);
// }
// bukatutupservo.detach();
// delay(2000);
//}
