void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on (Note that LOW is the voltage level
  delay(50);                      // Wait for a second
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off by making the voltage HIGH
  delay(100);                       // Wait for two seconds (to demonstrate the active low LED)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
