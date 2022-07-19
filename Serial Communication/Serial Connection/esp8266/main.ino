/*
    ให้นักศึกษาเขียนโปรแกรม เพื่ออ่าน DHT11 จาก ESP8266 ส่งข้อมูลผ่าน RS232 ไปยัง NodeMCU อีกตัว หลังจากนั้น แสดงผลบน LCD
*/

#include "DHT.h"
#include "SoftwareSerial.h"

#define DHTPIN D4
#define DHTTYPE DHT11
#define RX D2
#define TX D3

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial NodeSerial(RX, TX);

void setup()
{
    pinMode(RX, INPUT);
    pinMode(TX, OUTPUT);
    Serial.begin(115200);
    NodeSerial.begin(57600);
    dht.begin();
    Serial.println("Status\tHumidity (%)\tTemperature (C)");
}

void loop()
{
    int humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    Serial.print("\t");
    Serial.print(humidity, 1);
    Serial.print("\t\t");
    Serial.print(temperature, 1);
    Serial.print("\t\t");
    Serial.println("");
    NodeSerial.print(humidity);
    NodeSerial.print(" ");
    NodeSerial.print(temperature);
    NodeSerial.print("\n");
    delay(1000);
}