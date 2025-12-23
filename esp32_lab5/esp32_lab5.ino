int ldr = 36;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int x = analogRead(ldr);
  Serial.println(x);
  delay(1000);

}