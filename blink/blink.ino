#define PIN_LED 13
#define DELAY 100


void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(DELAY);
  digitalWrite(PIN_LED, LOW);
  delay(DELAY);
}
