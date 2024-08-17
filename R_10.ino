#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Avshalom";
const char* pswd = "200492262";

WiFiClient client;
int server_port = 80;//http

void wifiClient_Setup() {
  Serial.println("wifiSetup");
  WiFi.begin(ssid,pswd);
    while (WiFi.status()!=WL_CONNECTED){
      Serial.println("trying ...");
      delay(100);
    }
      Serial.println("Connected to network");
}

int GetData() {
  int ret = -1;
  HTTPClient http;
  String dataURL = "http://api.kits4.me/GEN/api.php?ACT=GET&DEV=1121&CH=1";
  http.begin(client, dataURL);
  int httpCode = http.GET();
  Serial.println(httpCode);
  if (httpCode == HTTP_CODE_OK) {
    Serial.print("HTTP response code ");
    Serial.println(httpCode);
    String Res = http.getString();
    Serial.println(Res);
    ret = Res.toInt();
  }
  http.end();

  return ret;
}

void SendData(unsigned long val) {
  HTTPClient http;
  String dataURL = "http://api.kits4.me/GEN/api.php?ACT=SET&DEV=1121&CH=1&VAL="; 
  dataURL += String(val);

  http.begin(client, dataURL);
  int httpCode = http.GET();
  Serial.println(httpCode);
  http.end(); 
}
