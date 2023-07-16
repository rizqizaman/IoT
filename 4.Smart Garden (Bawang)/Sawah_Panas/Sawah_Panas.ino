#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
const int ldr = A1, soil = A0, RLampu = 8, RPump = 7; 
int nilai_ldr, nilai_soil, lembab, cahaya;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Welcome To My");
  lcd.setCursor(1,1);
  lcd.print("Final Project");
  pinMode(ldr, INPUT);
  pinMode(soil, INPUT);
  pinMode(RLampu, OUTPUT);
  pinMode(RPump, OUTPUT);
  Serial.print("Sistem Otomasi Sawah");
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
 nilai_ldr  = analogRead(ldr);
 nilai_soil = analogRead(soil);
 cahaya = map(nilai_ldr, 0, 1023, 100, 0);
 lembab = map(nilai_soil, 0, 1023, 0, 100);
 
 Serial.print("Nilai LDR : ");
 Serial.println(cahaya);
 Serial.print("Nilai Soil : ");
 Serial.println(lembab);
 lcd.setCursor(7,1);
 lcd.print(" - ");
 lcd.print(lembab);
 lcd.print(" % ");
 
 if ((cahaya <= 30) && (lembab < 50)){  // Jika Nilai Cahaya kurang dari samadengan 30 (0-30) Lampu ON
                                        // Jika Nilai Lembab kurang dari 50 (0-49) Pompa OFF
    digitalWrite(RLampu, LOW);          // Relay (Saklar) Lampu ON

    lcd.setCursor(2,0);
    lcd.print("Status Tanah");
    lcd.setCursor(1,1);
    lcd.print("Normal");
    digitalWrite(RPump, HIGH);          // Relay (Saklar) Pompa OFF

    delay(1000);
    lcd.clear();
    
 }else if((cahaya > 30) && (lembab < 50)) {
    digitalWrite(RLampu, HIGH);          // Relay (Saklar) Lampu OFF

    lcd.setCursor(2,0);
    lcd.print("Status Tanah");
    lcd.setCursor(1,1);
    lcd.print("Normal");
    digitalWrite(RPump, HIGH);          // Relay (Saklar) Pompa OFF

    delay(1000);
    lcd.clear();
    
 }else if((cahaya <= 30) && (lembab >= 50)){
    digitalWrite(RLampu, LOW);          // Relay (Saklar) Lampu ON
    
   lcd.setCursor(2,0);
   lcd.print("Status Tanah");
   lcd.setCursor(1,1);
   lcd.print("Kering");
   digitalWrite(RPump, LOW);          // Relay (Saklar) Pompa ON
   
   delay(1000);
   lcd.clear();
   
 }else{
   digitalWrite(RLampu, HIGH);          // Relay (Saklar) Lampu OFF
    
   lcd.setCursor(2,0);
   lcd.print("Status Tanah");
   lcd.setCursor(1,1);
   lcd.print("Kering");
   digitalWrite(RPump, LOW);          // Relay (Saklar) Pompa ON
   
   delay(1000);
   lcd.clear();
 }
// delay(500);
}
