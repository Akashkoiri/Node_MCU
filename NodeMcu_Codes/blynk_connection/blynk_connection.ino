#include <ESP8266WiFi.h>
#include <Blynk.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "uhnVmlUzVStAlluA3g6Kmw6csl8pF4dG";
char ssid[] = "WIFI";
char pass[] = "akash1896";


void setup() {
pinMode(D5,OUTPUT);
Blynk.begin(auth, ssid, pass);
}

void loop() {
    Blynk.run();
}
