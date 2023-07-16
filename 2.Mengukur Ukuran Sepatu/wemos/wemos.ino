#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial (D2, D1);
// Replace with your network credentials
const char* ssid = "Rahasia_ net";
const char* password = "Satuduatiga";

String data;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
mySerial.begin(115200);
WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {
    unsigned long currentMillis = millis();
  unsigned long previousMillis = 0;
  const long interval = 3000;
//  String data = "panjang=26&lebar=8";
  if(currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    while (Serial.available() > 0) {
//      delay(10);
      char c = Serial.read();
      data += c;
    }
    if (data.length() > 0) {
      Serial.println (data);
      delay(500);
      data = "";
    }
  }
//  -------------------------------------------Kirim Data Ke website
  if ((WiFi.status() == WL_CONNECTED)) {

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    // Ignore SSL certificate validation
    client->setInsecure();
    
    //create an HTTPClient instance
    HTTPClient https;
  
  String url = "https://sepatu.solidvvproject.id/Home?";
    url += data;

    Serial.print("[HTTPS] begin...\n");
    if (https.begin(*client, url)) {  // HTTPS
      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();
      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }
  Serial.println();
  Serial.println("Waiting 2min before the next round...");
  delay(5000);
}
