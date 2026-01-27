#include <Arduino.h>
#include <DHT22.h>
#include "SPIFFS.h" 

#define pinDATA SDA      // ขา DHT22 (ตรวจสอบขานี้ให้ตรงกับบอร์ดของคุณ)
#define BUTTON_PIN 16    // ปุ่ม SW1

DHT22 dht22(pinDATA); 

unsigned long startTime = 0; // ตัวแปรสำหรับจำเวลาเริ่มต้น

void setup() {
  Serial.begin(115200);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP); // ตั้งค่าปุ่ม
  
  if(!SPIFFS.begin(true)){
    Serial.println("SPIFFS Error");
    return;
  }

  // เริ่มต้นจับเวลา
  startTime = millis();
  Serial.println("System Ready.");
}

void loop() {
  
  // --- 1. เช็คปุ่มกดเพื่อลบข้อมูลและรีเซ็ตเวลา (กดปุ่ม 16) ---
  if (digitalRead(BUTTON_PIN) == LOW) { 
    Serial.println("\n!!! Reset Button Pressed !!!");
    
    // ลบไฟล์เก่า
    SPIFFS.remove("/data.txt"); 
    
    // สร้างไฟล์ใหม่ เขียนหัวตาราง
    File myFile = SPIFFS.open("/data.txt", FILE_WRITE);
    if(myFile) {
      myFile.println("Time(sec),Temperature,Humidity");
      myFile.close();
      Serial.println("Data Cleared.");
    }

    // *** รีเซ็ตตัวจับเวลาให้เริ่มนับ 0 ใหม่ ***
    startTime = millis(); 
    
    delay(1000); // หน่วงเวลาป้องกันการกดรัว
  }

  // --- 2. อ่านค่าและบันทึก (ทำงานทุก 5 วินาที) ---
  static unsigned long lastRun = 0;
  if (millis() - lastRun > 5000) { // ครบ 5 วินาทีหรือยัง?
    lastRun = millis();

    float t = dht22.getTemperature();
    float h = dht22.getHumidity();

    if (dht22.getLastError() == dht22.OK) {
      
      File myFile = SPIFFS.open("/data.txt", FILE_APPEND);
      if(myFile) {
        // คำนวณเวลาที่ผ่านไป (วินาที) ตั้งแต่เริ่มหรือกดรีเซ็ต
        unsigned long currentTimer = (millis() - startTime) / 1000;

        // บันทึก: วินาที,อุณหภูมิ,ความชื้น
        myFile.print(currentTimer);
        myFile.print(",");
        myFile.print(t, 1);
        myFile.print(",");
        myFile.println(h, 1);
        myFile.close();
        
        Serial.print("Saved at ");
        Serial.print(currentTimer);
        Serial.println(" sec");
        
        // --- อ่านข้อมูลออกมาโชว์ ---
        File fileRead = SPIFFS.open("/data.txt");
        if(fileRead){
           Serial.println("--- FILE DATA ---");
           while(fileRead.available()){
             Serial.write(fileRead.read());
           }
           fileRead.close();
           Serial.println("-----------------");
        }
      }
    } else {
      Serial.println("Sensor Error");
    }
  }
}