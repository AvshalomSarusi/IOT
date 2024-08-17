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
