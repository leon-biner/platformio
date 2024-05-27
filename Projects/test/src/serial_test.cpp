#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(8, INPUT);
}

void loop()
{
    while (digitalRead(8) == LOW){}
    digitalWrite(13, HIGH);
    Serial.print("new_program\n");
    delay(1000);
    digitalWrite(13, LOW);
    Serial.print("light off\n");
    delay(1000);
}