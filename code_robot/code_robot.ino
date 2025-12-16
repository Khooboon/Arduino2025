const int led_red = 23;
const int led_green = 18;

void setup() {
 pinMode(led_red, OUTPUT);
 pinMode(led_green, OUTPUT);
}

void loop() {
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, LOW);
  delay(1000);
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, HIGH);
  delay(1000);


  
}
