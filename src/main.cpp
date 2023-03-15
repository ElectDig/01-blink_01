#include <Arduino.h>

/*
 *  Project 01-blink_01
 *      Blinks a LED changing blink frequency by pushing a key
 *      key connected to ground, so program must add pullup resistor
 *      Prints delay in milliseconds
 *      Austral 2023 - Electronica Digital - EAM
 */

#define LONG_DELAY  1000
#define SHORT_DELAY 100


int old_val = 0;

void
setup(void)
{
    pinMode(LED,OUTPUT);
    pinMode(PUSH,INPUT_PULLUP);
    digitalWrite(LED,LOW);
    Serial.begin(BAUD);
    old_val = LONG_DELAY;
}

void
loop(void)
{
    int delay_val;

    digitalWrite(LED, !digitalRead(LED));
    if( digitalRead(PUSH) == HIGH )
        delay_val = LONG_DELAY;
    else
        delay_val = SHORT_DELAY;

    if( delay_val != old_val )
        Serial.println(old_val = delay_val);

    delay(delay_val);
}
