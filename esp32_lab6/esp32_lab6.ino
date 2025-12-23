int ldr =36;
int bt = 17 ;
int wifi = 2 ;
int ntp = 15 ;
int iot = 12 ;

void setup() {
  Serial.begin(9600);
  pinMode(bt, OUTPUT);
  pinMode(wifi, OUTPUT);
  pinMode(ntp, OUTPUT);
  pinMode(iot, OUTPUT);

}
  void loop (){
    int x= analogRead(ldr);
    Serial.print(x);
    Serial.print("\t");
   int y =map (x , 0 , 1024 , 0 , 4);
   Serial.print(y);
   delay(100);


   //ให้เขียนต่อยอดทำไฟติดตามค่าyที่ได้
   if(y==0){
    digitalWrite(bt, HIGH);
    digitalWrite(wifi, HIGH);
    digitalWrite(ntp, HIGH);
    digitalWrite(iot, HIGH);
  }else if(y == 1){
    digitalWrite(bt, LOW);
    digitalWrite(wifi, HIGH);
    digitalWrite(ntp, HIGH);
    digitalWrite(iot, HIGH);
  }else if(y == 2){
    digitalWrite(bt, LOW);
    digitalWrite(wifi, LOW);
    digitalWrite(ntp, HIGH);
    digitalWrite(iot, HIGH);
  }else if(y == 3){
    digitalWrite(bt, LOW);
    digitalWrite(wifi, LOW);
    digitalWrite(ntp, LOW);
    digitalWrite(iot, HIGH);
  }else if(y == 4){
    digitalWrite(bt, LOW);
    digitalWrite(wifi, LOW);
    digitalWrite(ntp, LOW);
    digitalWrite(iot, LOW);
  }

  }