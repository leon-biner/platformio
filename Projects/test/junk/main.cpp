#include <Arduino.h>

unsigned long blink(bool& state)
{
    if (state == HIGH)
    {
      digitalWrite(13, LOW);
      state = LOW;
      return millis();
    }
    else 
    {
      digitalWrite(13, HIGH);
      state = HIGH;
      return millis();
    }
}


void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
}

bool current_state = LOW;
unsigned int blinking_time = 1000;
unsigned long time_since_last_blink = 0;
bool previous_state = LOW;
unsigned int time_increase_by_button = 100;

void loop() 
{
  if ((millis() - time_since_last_blink) > blinking_time)
    time_since_last_blink = blink(current_state);
  if (digitalRead(7) && !previous_state)
  {
    previous_state = HIGH;
    blinking_time += time_increase_by_button;
    Serial.print("button pressed\n");
  }
  if (previous_state == HIGH && !digitalRead(7))
  {
    previous_state = LOW;
    Serial.print("button released\n");
  }
}