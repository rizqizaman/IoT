#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
#include <DHT.h>
#define DHTPIN 13
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
float temp, humi;

const int
  LDR = 12, 
  Soil = 14, 
  RLampu = 18, 
  RPump = 19; 
int 
  nilai_LDR,
  nilai_Soil,
  Lembab;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.init();
  lcd.setCursor(0,0);
  lcd.print("Welcome To");
  lcd.setCursor(0,1);
  lcd.print("My Garder");
  lcd.clear();
  
  dht.begin();
  pinMode(LDR, INPUT);
  pinMode(Soil, INPUT);
  pinMode(RLampu, OUTPUT);
  pinMode(RPump, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Kelembaban();
  Cahaya();
  temp = dht.readTemperature();
  humi = dht.readHumidity();
  
}
void Kelembaban(){
  nilai_Soil = analogRead(Soil);
  Lembab     = map(nilai_Soil, 0, 1023, 0, 100);
  digitalWrite(RPump, LOW);
  if (Lembab <= 50 ){         //Kelembaban tanah dianggap kering
    digitalWrite(RPump, HIGH);
    delay(5000);
    digitalWrite(Rpump, LOW);
  }
}
void Cahaya(){
  nilai_LDR  = analogRead(LDR);
  digitalWrite(RLampu, LOW);
  if (nilai_LDR < 511){             // Nilai Cahaya dianggap Gelap
      digitalWrite(RLampu, HIGH);
  }
}
