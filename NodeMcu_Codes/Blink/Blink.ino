#define led D5
void setup() {
  pinMode(led, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);            // turn the LED on (HIGH is the voltage level)
  delay(500);                        // wait for a second
  digitalWrite(led, LOW);
  digitalWrite(LED_BUILTIN, LOW);      // turn the LED off by making the voltage LOW
  delay(500);                        // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);
}
