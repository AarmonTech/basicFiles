#include<ESP8266WiFi.h>
#include<MQTT.h>

const char ssid[] = "swap";
const char pass[] = "Qwerty123";

WiFiClientSecure net;
MQTTClient client;


int flow_frequency = 0;


void connect()
{
  Serial.print("Checking Wifi....");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");


  while (!client.connect("esp", "prashant", "LudvigVanB")) {
    Serial.print(".");
    delay(1000) ;
  }

  Serial.println("\nconnected!");

}


void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);



  client.begin("broker.shiftr.io", net);
  connect();



}

int i = 0;

void loop() {

  i = i + 1;

  client.loop();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(i);
    client.publish("/vendingmachine", String(i));
  }

}



