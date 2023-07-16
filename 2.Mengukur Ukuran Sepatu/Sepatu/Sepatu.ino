#include <SoftwareSerial.h>
String minta;
const int 
  ldr1 = A14, ldr2 = A15,
  ldr3 = A7, ldr4 = A6,
  ldr5 = A5,  ldr6 = A10,
  ldr7 = A11,  ldr8 = A12,
  ldr9 = A9,  ldr10= A8;
//  -------------------------------------------- Variabel untuk penempatan pin pada tiap-tiap sensor LDR
int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10; //---------- Varibel baru untuk menampung nilai dari pembacaan sensor LDR
const int triger = 2, echo = 3; //-------------- Variabel untuk penempatan pin pada sensor Ultrasonik
long durasi, jarak;             //-------------- Variabel baru untuk menampung nilai dari pembacaan sensor Ultrasonik
float maksim = 11.00, minim = 00;    //-------------- Variabel baru untuk menentukan nilai awal dari pembacaan lebar kaki
float panjang;
int sepatu;
void setup() {//-------------------------------- Funsi yang menampung persiapan Mode-Pin sebagai INPUT atau OUTPUT
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  pinMode(ldr3,INPUT);
  pinMode(ldr4,INPUT);
  pinMode(ldr5,INPUT);
  pinMode(ldr6,INPUT);
  pinMode(ldr7,INPUT);
  pinMode(ldr8,INPUT);
  pinMode(ldr9,INPUT);
  pinMode(ldr10,INPUT);
//---------------------------------------------- Setting Mode-Pin LDR sebagai Pin INPUT
  pinMode(triger, OUTPUT);//-------------------- Setting Mode-Pin Triger(Ultrasonik) sebagai Pin OUTPUT
  pinMode(echo, INPUT);//----------------------- Setting Mode-Pin Echo(Ultrasonik) sebagai Pin INPUT
  
}

void loop() {//-------------------------------------- Fungsi yang menampung perulangan mesin 
  // put your main code here, to run repeatedly:
  a1 = analogRead(ldr1);//---------------------- variabel untuk menampung nilai analog dari pembacaan sensor LDR
  a2 = analogRead(ldr2);
  a3 = analogRead(ldr3);
  a4 = analogRead(ldr4);
  a5 = analogRead(ldr5);
  a6 = analogRead(ldr6);
  a7 = analogRead(ldr7);
  a8 = analogRead(ldr8);
  a9 = analogRead(ldr9);
  a10= analogRead(ldr10);

  Serial.print("A1 : ");
  Serial.println(a1);
  Serial.print("A2 : ");
  Serial.println(a2);
  Serial.print("A3 : ");
  Serial.println(a3);
  Serial.print("A4 : ");
  Serial.println(a4);
  Serial.print("A5 : ");
  Serial.println(a5);
  Serial.print("A6 : ");
  Serial.println(a6);
  Serial.print("A7 : ");
  Serial.println(a7);
  Serial.print("A8 : ");
  Serial.println(a8);
  Serial.print("A9 : ");
  Serial.println(a9);
  Serial.print("A10 : ");
  Serial.println(a10);
  
  digitalWrite(triger, LOW);delayMicroseconds(2);//-- Arduino mengirim perintah pada pin triger untuk non-aktif selama 2ms
  digitalWrite(triger, HIGH);delayMicroseconds(10);// Arduino mengirim perintah pada pin triger untuk aktif selama 10ms
  digitalWrite(triger, LOW);//----------------------- Arduino mengirim perintah pada pin triger untuk non-aktif 
  durasi = pulseIn(echo, HIGH);//-------------------- Arduino mengirim perintah pada pin echo untuk aktif untuk mendapatkan nilai durasi 
  jarak = durasi/58.2;//----------------------------- Menghitung nilai jarak dari pembagian nilai durasi/58.2
//  Serial.print("Jarak : ");
//  Serial.println(jarak);
  if(jarak < maksim || jarak > minim){//----------- Logika jika jarak <= 15cm atau jarak >=0 maka,
    long lebar = maksim - jarak;//------------------- Menghitung nilai Lebar kaki dri pengurangan nilai maksim (15cm)-nilai jarak
//    ukuran();//-------------------------------------- Mengaktifkan fungsi ukuran, untuk mengaktifkan pembacaan ukuran kaki (panjang kaki)
    if ((a1 <= 240) && (a2 > 240) && (a3 > 240) && (a4 > 250) && (a5 > 240) && (a6 > 240) && (a7 > 240) && (a8 > 200) && (a9 > 240) && (a10 > 240)){
      panjang = 23.5;
      sepatu = 37;
    }
    else if ((a1 <= 240) && (a2 <= 240) && (a3 > 240) && (a4 > 250) && (a5 > 240) && (a6 > 240) && (a7 > 240) && (a8 > 200) && (a9 > 240) && (a10 > 240)){
      panjang = 24;
      sepatu = 38;
    }
    else if ((a1 <= 240) && (a2 <= 240) && (a3 <= 240)&& (a4 > 250) && (a5 > 240) && (a6 > 240) && (a7 > 240) && (a8 > 200) && (a9 > 240) && (a10 > 240)){
      panjang = 24.5;
      sepatu = 39;
    }
    else if ((a1 <= 240) && (a2 <= 240) && (a3 <= 240) && (a4 <= 250) && (a5 > 240) && (a6 > 240) && (a7 > 240) && (a8 > 200) && (a9 > 240) && (a10 > 240)){
      panjang = 25;
      sepatu = 40;
    }
    else if ((a1 <= 240) && (a2 <= 240) && (a3 <= 240) && (a4 <= 250) && (a5 <= 240) && (a6 > 240) && (a7 > 240) && (a8 > 200) && (a9 > 240) && (a10 > 240)){
      panjang = 26;
      sepatu = 41;
    }
    else if ((a1 <= 240) && (a2 <= 240) && (a3 <= 240) && (a4 <= 250) && (a5 <= 240) && (a6 <= 240) && (a7 > 240) && (a8 > 200) && (a9 > 240) && (a10 > 240)){
      panjang = 26.5;
      sepatu = 42;
    }
    else if ((a1 <= 240) && (a2 <= 240) && (a3 <= 240) && (a4 <= 250) && (a5 <= 240) && (a6 <= 240) && (a7 <= 240) && (a8 > 200) && (a9 > 240) && (a10 > 240)){
      panjang = 27;
      sepatu = 43;
    }
    else if ((a1 <= 240) && (a2 <= 240) && (a3 <= 240) && (a4 <= 250) && (a5 <= 240) && (a6 <= 240) && (a7 <= 240) && (a8 <= 200) && (a9 > 240) && (a10 > 240)){
      panjang = 28;
      sepatu = 44;
    }
    else if ((a1 <= 240) && (a2 <= 240) && (a3 <= 240) && (a4 <= 250) && (a5 <= 240) && (a6 <= 240) && (a7 <= 240) && (a8 <= 200) && (a9 <= 240) && (a10 > 240)){
      panjang = 29;
      sepatu = 45;
    }
    else if ( (a1 <= 240) && (a2 <= 240) && (a3 <= 240) && (a4 <= 250) && (a5 <= 240) && (a6 <= 240) && (a7 <= 240) && (a8 <= 240) && (a9 <= 240) && (a10 <= 240)){
      panjang = 30;
      sepatu = 46;
    }
    else{
    }
    String data = String("panjang=")+String(panjang)+String("&lebar=")+String(lebar); 
    Serial.print(data);
    Serial.println("");
    
//    while(Serial.available() > 0 ){
//    minta += char(Serial.read());
//    }
//    minta.trim();
//    if(minta == "Ya"){
//      String data = String("panjang=")+String(panjang)+String("&lebar=")+String(lebar); 
//    }
//    minta = "";
  }
  
//    ukuran();
  delay(1000);//------------------------------------- delay 5000 = 5 detik
}
