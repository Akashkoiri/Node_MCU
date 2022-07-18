#include <ESP8266WiFi.h>

 WiFiClient client;
 WiFiServer server(80);
void setup() {
  Serial.begin(9600);
  WiFi.softAP("NodeMCU","ak47890");
  Serial.println("WiFi is created");
  Serial.print(WiFi.softAPIP());
  server.begin();
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop(){
  client = server.available();
  if(client == 1)
  {
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
  if(request == "GET /A HTTP/1.1")
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if(request == "GET /a HTTP/1.1")
  {
    digitalWrite(LED_BUILTIN, HIGH);

  }
  }
  delay(500);
}
