#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Arduino.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti WiFiMulti;
WiFiClient client;
HTTPClient httpclient;
 
void setup() {
  Serial.begin(115200);
  Serial.swap();
  delay(1000);
  Serial1.begin(115200);
  WiFi.begin("JavaRuntimeError", "Kosinka46K");
  for(int i = 0;i<=1000;i++){
    if(WiFi.status() != WL_CONNECTED){
      delay(900);
          
    }
  }  
}

void loop() {
  
  if(Serial.available()){
    Serial1.write(Serial.read());
  }
  
    if(Serial.available()){
      char SerialChar = 0;
      String SerialString = "";
      while(Serial.available()){
        SerialChar = Serial.read();
        SerialString += SerialChar;
        delay(2);
      }
       
    httpclient.begin(client, "http://192.168.1.2:4646");
    httpclient.addHeader("Content-Type", "text/plain");
    String ADCResult = "ADC Result is: " + SerialString;
    httpclient.POST(ADCResult);
    httpclient.end();
  }  
}
