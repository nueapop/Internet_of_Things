/*
    รับข้อมูลทาง console และแสดงข้อมูลที่รับมาทาง console
*/

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if (Serial.available() > 0)
    {
        Serial.println("Input String -> " + Serial.readString());
    }
}