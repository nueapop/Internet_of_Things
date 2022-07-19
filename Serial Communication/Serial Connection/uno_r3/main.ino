/*
    ให้นักศึกษาเขียนโปรแกรม เพื่ออ่าน DHT11 จาก ESP8266 ส่งข้อมูลผ่าน RS232 ไปยัง NodeMCU อีกตัว หลังจากนั้น แสดงผลบน LCD
*/

#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#include "SoftwareSerial.h"

#define RX 0
#define TX 1

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial UnoSerial(RX, TX);

void setup()
{
    pinMode(RX, INPUT);
    pinMode(TX, OUTPUT);
    Serial.begin(115200);
    UnoSerial.begin(57600);
    lcd.begin();
    lcd.backlight();
    Serial.println("NodeMCU/ESP8266 Running...");
}

void loop()
{
    while (UnoSerial.available() > 0)
    {
        int humidity_data = UnoSerial.parseInt();
        float temperature_data = UnoSerial.parseFloat();
        if (UnoSerial.read() == '\n')
        {
            Serial.print("humidity: ");
            Serial.print(humidity_data);
            Serial.print("    temperature: ");
            Serial.println(temperature_data);
            lcd.setCursor(0, 0);
            lcd.print("Temp: ");
            lcd.setCursor(6, 0);
            lcd.print(temperature_data);
            lcd.setCursor(0, 1);
            lcd.print("Humidity: ");
            lcd.setCursor(10, 1);
            lcd.print(humidity_data);
        }
    }
}