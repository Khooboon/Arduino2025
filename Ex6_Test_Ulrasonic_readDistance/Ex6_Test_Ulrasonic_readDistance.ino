///////////////////////////////////////////////////////////////////////////////////////
// Robot 2WD Line Tracking Ultrasonic             Version 3.0                        //
// Create : Mr.Chartthai Santhanaboun by #EarthElectronics #ThaiRoboShop #ThaiRobo3D //
// Date : 19/05/2025                                                                 //
// Hardware : Robot 2WD, Arduino ESP32, Line Sensor Module, Ultrasonic Sensor, LED   //
// Software : Version 3.0                                                            //
///////////////////////////////////////////////////////////////////////////////////////

#include <NewPing.h>

const int TRIGGER_PIN   = 13;  // กำหนดตำแหน่งขา trigger ของ ultrasonic sensor.
const int ECHO_PIN      = 5;  // กำหนดตำแหน่งขา echo ของ ultrasonic sensor.
const int MAX_DISTANCE  = 60;// กำหนดระยะทางสูงสุดที่ต้องการตรวจจับหน่วยเป็น (centimeters) 3-400cm

// Create Ultrasonic object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // ตั้งค่าตำแหน่งขาที่ใช้ของ ultrasonic และระยะสูงสุดที่ต้องการอ่านค่า

void setup() {
  Serial.begin(115200);                     // ประกาศ Buadrate เริ่มต้นอยู่ที่ 115200
  Serial.println("Robot_Ready");            // พิมพ์ข้อความโชว์ผ่านทาง Serial Monitor ว่า "Robot_Ready"
  delay(1000);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}