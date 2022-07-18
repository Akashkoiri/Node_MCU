#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
void setup() {
Serial.begin(9600);
WiFi.begin("WIFI","akash1896");
while(WiFi.status() != WL_CONNECTED)
{
  delay(300);
  Serial.print(".");
}
Serial.println();
Serial.print(WiFi.localIP());
server.begin();
pinMode(LED_BUILTIN,OUTPUT);
}
void loop() {
client = server.available();
  if(client == 1)
  {
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledon HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
    if(request == "GET /ledoff HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN,HIGH);
    }
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!Doctype html>");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>NodeMCU Controll page</title>");
  client.println("</head>");
  client.println("<a href=\"/ledon\"\"><button>ON</button></a>");
  client.println("<a href=\"/ledoff\"\"><button>OFF</button></a>");
  client.println("</body>");
  client.println("</html>");
 
}
