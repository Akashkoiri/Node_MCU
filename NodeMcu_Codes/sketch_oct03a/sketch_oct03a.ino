#include<ESP8266WiFi.h>
WiFiServer server(80);
WiFiClient client;

void setup(){
  Serial.begin(9600);
  WiFi.begin("WIFI", "akash1896");
  pinMode(LED_BUILTIN, OUTPUT);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("NodeMCU is connected with: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  client = server.available();
  if(client == 1)
  {
    String request = client.readStringUntil('\n');
    Serial.println(request);
  }
      request.trim();
  if(request == "GET /A HTTP/1.1")
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if(request == "GET /a HTTP/1.1")
  {
    digitalWrite(LED_BUILTIN, HIGH);

  }
  delay(500);
}
