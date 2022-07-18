#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ESP8266HTTPClient.h>

DHT dht(D5, DHT11);

String host = "api.thingspeak.com";
int httpPort = 80;
String url1 = "/update?api_key=DBVNCPRUTU8ZOF6V&field1=";
String url2 = "/update?api_key=DBVNCPRUTU8ZOF6V&field1=";

HTTPClient http;

void setup() {
  Serial.begin(9600);
  WiFi.begin("WIFI","akash1896");   //if connect to open network ==> WiFi.begin("WIFI");

  while(WiFi.status() != WL_CONNECTED)       //checking wifi connection
  {
      delay(300);
      Serial.print(".");
  }

  Serial.println();                             // after the println line anything prints from a new line in serial moniter
  Serial.println("NodeMCU is connected");
  Serial.println(WiFi.localIP());
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();  //reading the temperature using sensor and saving it in 't' var
  float h = dht.readHumidity(); //reading the humidity using sensor and saving it in 'h' var

  Serial.println("Temperature: " + (String) t); //print temp in serial monitor
  Serial.println("Humidity: " + (String) h);    //print humidity in serial monitor

  String link1 = url1 + (String) t;
  http.begin(host,httpPort,link1);
  int httpCode = http.GET();
  Serial.println(httpCode);
  delay(2000);

  String link2 = url2 + (String) h;
  http.begin(host,httpPort,link2);
  httpCode = http.GET();
  Serial.println(httpCode);
  delay(2000);
}
