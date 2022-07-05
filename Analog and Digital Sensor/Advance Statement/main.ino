/*
    เขียนโปรแกรมรับข้อมูลทาง console โดยมีเงื่อนไขดังนี้
    “1” ให้ LED onboard กระพริบ ทุก ๆ 1000 ms
    “0” ให้ปิด LED
    “+” ให้กระพริบเร็วขึ้น 100ms
    “-” ให้กระพริบช้าลง 100ms
*/

int D = 1000;

void setup()
{
    Serial.begin(115200);
    pinMode(BUILTIN_LED, OUTPUT);
}

void loop()
{
    if (Serial.available() > 0)
    {
        unsigned char c = Serial.read();
        if (c == '1')
        {
            D = 1000;
        }
        else if (c == '0')
        {
            D = 0;
        }
        else if (c == '+')
        {
            D -= 100;
        }
        else if (c == '-')
        {
            D += 100;
        }
    }
    else
    {
        Serial.print("Delay = ");
        Serial.println(D);
        if (D > 0)
        {
            digitalWrite(BUILTIN_LED, LOW);
            delay(D);
            digitalWrite(BUILTIN_LED, HIGH);
            delay(D);
        }
    }
}