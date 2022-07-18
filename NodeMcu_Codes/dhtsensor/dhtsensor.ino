#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
//#include <DHT.h>

//DHT dht(D5, DHT11);
WiFiClient client;

long myChannelNumber = 1539139;
const char myWriteAPIKey[] = "DBVNCPRUTU8ZOF6V";

void setup() {
  Serial.begin(9600);
  WiFi.begin("WIFI","akash1896"); //if connect to open network ==> WiFi.begin("WIFI");

  while(WiFi.status() != WL_CONNECTED)       //checking wifi connection
  {
      delay(300);
      Serial.print(".");
  }

  Serial.println();                         // after the println line anything prints from a new line in serial moniter
  Serial.println("NodeMCU is connected");
  Serial.println(WiFi.localIP());
  //dht.begin();
  ThingSpeak.begin(client);
}

void loop() {
//  float t = dht.readTemperature();
//  float h = dht.readHumidity();
//
//  Serial.println("Temperature: " + (String) t);
//  Serial.println("Humidity: " + (String) h);
//
//  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
//  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
    delay(2000);

}
