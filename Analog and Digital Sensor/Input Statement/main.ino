/*
    รับข้อมูลทาง console หากมีค่าเป็น “A” ให้แสดงชื่อ หากเป็น “B” ให้แสดงรหัส
*/

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if (Serial.available() > 0)
    {
        String input = Serial.readString();
        if (input == "A")
        {
            Serial.println("Name");
        }
        else if (input == "B")
        {
            Serial.println("12345");
        }
    }
}