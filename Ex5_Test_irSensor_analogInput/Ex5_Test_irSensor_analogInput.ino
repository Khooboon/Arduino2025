///////////////////////////////////////////////////////////////////////////////////////
// Robot 2WD Line Tracking Ultrasonic             Version 3.0                        //
// Create : Mr.Chartthai Santhanaboun by #EarthElectronics #ThaiRoboShop #ThaiRobo3D //
// Date : 19/05/2025                                                                 //
// Hardware : Robot 2WD, Arduino ESP32, Line Sensor Module, Ultrasonic Sensor, LED   //
// Software : Version 3.0                                                            //
///////////////////////////////////////////////////////////////////////////////////////

//Line Tracking Sensor
const int line_1  = 26;                // กำหนดขา GPIO ของเซ็นเซอร์ตรวจจับเส้น ที่เชื่อมต่อกับ UNO
const int line_2  = 25;
const int line_3  = 33;
const int line_4  = 32;
const int line_5  = 35;
const int line_6  = 34;
const int line_7  = 39;
const int line_8  = 36;

//Line Value
int lineValue_1, lineValue_2, lineValue_3, lineValue_4,     // สร้างตัวแปรเก็บค่าการตรวจจับเส้นของเซ็นเซอร์แต่ละตำแหน่ง
lineValue_5, lineValue_6, lineValue_7, lineValue_8; 

void setup() {
  Serial.begin(115200);                     // ประกาศ Buadrate เริ่มต้นอยู่ที่ 115200
  Serial.println("Robot_Ready");            // พิมพ์ข้อความโชว์ผ่านทาง Serial Monitor ว่า "Robot_Ready"
}

void loop() {
  lineValue_1 = analogRead(line_1)/16; lineValue_2 = analogRead(line_2)/16;
  lineValue_3 = analogRead(line_3)/16; lineValue_4 = analogRead(line_4)/16;
  lineValue_5 = analogRead(line_5)/16; lineValue_6 = analogRead(line_6)/16;
  lineValue_7 = analogRead(line_7)/16; lineValue_8 = analogRead(line_8)/16;

  Serial.print("Line :");    Serial.print('\t');
  Serial.print(lineValue_1);  Serial.print('\t');
  Serial.print(lineValue_2);  Serial.print('\t');
  Serial.print(lineValue_3);  Serial.print('\t');
  Serial.print(lineValue_4);  Serial.print('\t');
  Serial.print(lineValue_5);  Serial.print('\t');
  Serial.print(lineValue_6);  Serial.print('\t');
  Serial.print(lineValue_7);  Serial.print('\t');
  Serial.println(lineValue_8);
}
