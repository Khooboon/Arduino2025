int bt = 17;
int wifi = 2;
int ntp = 15;
int iot = 12;

void setup() {
  Serial.begin(115200);
  pinMode(bt, OUTPUT);
  pinMode(wifi, OUTPUT);
  pinMode(ntp, OUTPUT);
  pinMode(iot, OUTPUT);
}

void loop() {
  digitalWrite(bt, HIGH);
  delay(1000);
  digitalWrite(bt, LOW);
  delay(1000);
  digitalWrite(wifi, HIGH);
  delay(1000);
  digitalWrite(wifi, LOW);
  delay(1000);
  digitalWrite(ntp, HIGH);
  delay(1000);
  digitalWrite(ntp, LOW);
  delay(1000);
  digitalWrite(iot, HIGH);
  delay(1000);
  digitalWrite(iot, LOW);
  delay(1000);

}