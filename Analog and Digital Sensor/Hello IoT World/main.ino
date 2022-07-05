/*
    แสดงข้อความ “Hello IoT World” ทางจอ console ทุก ๆ วินาที
*/

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.println("Hello IoT World");
    delay(1000);
}