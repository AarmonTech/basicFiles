#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

HTTPClient http;

const char* WIFINAME = "swap";
const char* PASS = "Qwerty123";


void setup()
{
  Serial.begin(9600);
  delay(10);
  Serial.println("");

  Serial.print("Connecting To ");
  Serial.println(WIFINAME);

  if (WiFi.status() != WL_CONNECTED) {

    WiFi.begin(WIFINAME, PASS);
  }

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}


int i = 0;

void loop()
{

  i = i + 1;
  
  HTTPClient http;

  http.begin("http://prashant:LudvigVanB@broker.shiftr.io/foo");

  
  int httpCode = http.POST(String(i));

  //Serial.println(http.errorToString(httpCode));

  Serial.println(httpCode);


  if (httpCode == 200) {

    String amount_str = http.getString();
    Serial.println("Recieved : " + amount_str);



  }



}

