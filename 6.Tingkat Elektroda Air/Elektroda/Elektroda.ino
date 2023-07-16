//#include <Arduino.h>
//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>
//#include <WiFiClientSecureBearSSL.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Replace with your network credentials
//const char* ssid = "Rahasia_ net";
//const char* password = "Satuduatiga";

String Status;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
//  WiFi.mode(WIFI_STA); 
//  WiFi.begin(ssid, password);
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//  
//  WiFi.begin(ssid, password);
//  
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  Serial.println("");
//  Serial.println("WiFi connected");
//  ----------------------------------
  pinMode(A0, INPUT);
  Serial.print("Sensor Elektroda");
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("SALINITAS AIR");
  lcd.setCursor(3,1);
  lcd.print("DESTILASI");
  delay(5000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilai = analogRead(A0);
  float voltage = nilai*(15.0/1023.0);
  
  Serial.print("Nilai Sensor : ");
  Serial.println(voltage);
  delay(1000);
  lcd.setCursor(3,0);
  lcd.print("STATUS AIR");

  if ((voltage >= 1) && (voltage <= 6)){
    lcd.setCursor(2,1);
    lcd.print("LAYAK MINUM");
    delay(1000);

    Status = "LAYAK MINUM";
    Serial.print("LAYAK MINUM");
    Serial.println("");
  }
  else if ((voltage > 6) && (voltage <= 16)){
    lcd.setCursor(2,1);
    lcd.print("LAYAK PAKAI");
    delay(1000);
    
    Status = "LAYAK PAKAI";
    Serial.print("LAYAK PAKAI");
    Serial.println("");
  }
  else{
    lcd.setCursor(2,1);
    lcd.print("TIDAK LAYAK!");
    delay(1000);
    
    Status = "TIDAK LAYAK MINUM & PAKAI";
    Serial.print("TIDAK LAYAK MINUM & PAKAI");
    Serial.println("");
  }
    lcd.clear();
//    --------------------------------------- PENGIRIMAN DATA
//    if ((WiFi.status() == WL_CONNECTED)) {
//
//    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
//
//    // Ignore SSL certificate validation
//    client->setInsecure();
//    
//    //create an HTTPClient instance
//    HTTPClient https;
//  
//  String url = "https://xxxx.my.id/KirimData?";
//    url += data;
//
//    Serial.print("[HTTPS] begin...\n");
//    if (https.begin(*client, url)) {  // HTTPS
//      Serial.print("[HTTPS] GET...\n");
//      // start connection and send HTTP header
//      int httpCode = https.GET();
//      // httpCode will be negative on error
//      if (httpCode > 0) {
//        // HTTP header has been send and Server response header has been handled
//        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
//        // file found at server
//        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
//          String payload = https.getString();
//          Serial.println(payload);
//        }
//      } else {
//        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
//      }
//
//      https.end();
//    } else {
//      Serial.printf("[HTTPS] Unable to connect\n");
//    }
//  }
//  Serial.println();
//  Serial.println("Waiting 2min before the next round...");
//  delay(60000);        // 1 MENIT
}
