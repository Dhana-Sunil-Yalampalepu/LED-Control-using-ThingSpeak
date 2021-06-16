#include <ESP8266WiFi.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiUdp.h>

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>


// Replace your wifi credentials here
const char* ssid     = "xxxxxxxxx";// ssid: your wifi name

const char* password = "xxxxxxxxxx";// password: your wifi password

// Replace with your own ThingSpeak Account Channel ID
unsigned long channel =  1415346;

// 1 is a channel field. You don't need to change if you are following
// this tutorial. You can modify it according to your application
unsigned int led = 1;

WiFiClient  client;


void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(D1, OUTPUT);

  // We start by connecting to a WiFi network
 
  Serial.println();
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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}

void loop() {
 
  // get the last data of the fields
  int led_1 = ThingSpeak.readFloatField(channel, led);
  
  if(led_1 == 1){
    digitalWrite(D1, 1);
    Serial.println("LED1 is On..!");
  }
  else if(led_1 == 0){
    digitalWrite(D1, 0);
    Serial.println("LED1 is Off..!");
  }
    
  Serial.println(led_1);
  delay(5000);
}
