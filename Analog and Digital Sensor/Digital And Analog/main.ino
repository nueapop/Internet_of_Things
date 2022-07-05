/*
    โปรแกรม อ่านค่า ความเข้มแสง อุณหภูมิ เป็นเซนเซียส และ ฟาเรนไฮส์ แสดงผลทางจอ console ทุกๆ 1000 ms
*/

#include "DHT.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

#define DHTPIN D4
#define DHTTYPE DHT11
#define BRIGHTPIN A0

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(115200);
    dht.begin();
    lcd.begin();
    lcd.backlight();
    pinMode(BUILTIN_LED, OUTPUT);
}

void loop()
{
    float c = dht.readTemperature();
    float f = dht.readTemperature(true);
    int b = analogRead(BRIGHTPIN);
    if (isnan(c) || isnan(f) || isnan(b))
    {
        Serial.println("Failed to read from sensor!");
        return;
    }
    else
    {
        if (b > 500)
        {
            digitalWrite(BUILTIN_LED, LOW);
            lcd.setCursor(0, 1);
            lcd.print("Bright: ZZZ");
        }
        else
        {
            digitalWrite(BUILTIN_LED, HIGH);
            lcd.setCursor(0, 1);
            lcd.print("Bright: ");
            lcd.setCursor(8, 1);
            lcd.print(b);
        }
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.setCursor(6, 0);
        lcd.print(c);
        lcd.setCursor(12, 0);
        lcd.print(f);
        Serial.print("Temp: ");
        Serial.print(c);
        Serial.print(" C ");
        Serial.print("Temp: ");
        Serial.print(f);
        Serial.print(" F ");
        Serial.print("Bright: ");
        Serial.print(b);
        Serial.println("");
    }
    delay(1000);
}