/*
    โปรแกรม อ่านค่า ความชื้น อุณหภูมิ เป็นเซนเซียส และ ฟาเรนไฮส์ แสดงผลทางจอ console ทุกๆ 1000 ms
*/

#include "DHT.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

#define DHTPIN D4
#define DHTTYPE DHT11
#define BRIGHTPIN D6

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(115200);
    dht.begin();
    lcd.begin();
    lcd.backlight();
    pinMode(BRIGHTPIN, OUTPUT);
}

void loop()
{

    float c = dht.readTemperature();
    float f = dht.readTemperature(true);
    float h = dht.readHumidity();
    if (isnan(c) || isnan(f) || isnan(h))
    {
        Serial.println("Failed to read from sensor!");
        return;
    }
    else
    {
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.setCursor(6, 0);
        lcd.print(c);
        lcd.setCursor(12, 0);
        lcd.print(f);
        lcd.setCursor(0, 1);
        lcd.print("Humidity: ");
        lcd.setCursor(10, 1);
        lcd.print(h);
        Serial.print("Temp: ");
        Serial.print(c);
        Serial.print(" C ");
        Serial.print("Temp: ");
        Serial.print(f);
        Serial.print(" F ");
        Serial.print("Humidity: ");
        Serial.print(h);
        Serial.println("");
        digitalWrite(BRIGHTPIN, LOW);
        delay(500);
        digitalWrite(BRIGHTPIN, HIGH);
        delay(500);
    }
}