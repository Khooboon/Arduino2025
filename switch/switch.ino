 #define buzzer 15
 #define button 27

void setup() {
 pinMode(buzzer, OUTPUT);
 pinMode(button, INPUT_PULLUP);

 digitalWrite(buzzer , HIGH); // สั่งงานให้ buzzer หยุด
}

 void loop() {
   if(digitalRead(button) == LOW){ // เงื่อนไขทำงานเมื่อกดปุ่ม
    digitalWrite(buzzer, LOW);
}
else { // เงื่อนไขทำงานเมื่อไม่กดปุ่ม
   digitalWrite(buzzer , HIGH);
}
}
 