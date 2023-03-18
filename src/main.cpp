#include <Arduino.h>

/*
 *  Project 01-blink_01
 *      Blinks a LED changing blink frequency by pushing a key
 *      Key connected to ground, so program must add pullup resistor
 *      Prints delay in milliseconds
 *      Austral 2023 - Electronica Digital - EAM
 */

#define LONG_DELAY  1000
#define SHORT_DELAY 100


int old_val = 0;    //  variable to remember present delay

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
#if 1       // High level programming way. Change to '#if 0' to use alternate code, save and compile

    int delay_val;
    int led_now;

    led_now = digitalRead(LED);                 //  LED state now !!
    digitalWrite(LED,!led_now);                 //  Change to other state

    if( digitalRead(PUSH) == HIGH )             //  Is key opened
        delay_val = LONG_DELAY;                 //  Yes, select long delay
    else
        delay_val = SHORT_DELAY;                //  No, key is closed, select short delay

    if( delay_val != old_val )
        Serial.println(old_val = delay_val);    //  Print only on delay change

    delay(delay_val);

#else   // Efficient programming way

    int delay_val;

    digitalWrite(LED, !digitalRead(LED));       //  Change state of LED
    delay_val = digitalRead(PUSH) == HIGH ? LONG_DELAY: SHORT_DELAY;    // Select short delay iff key closed
    if( delay_val != old_val )
        Serial.println(old_val = delay_val);    // Print only on delay change
    delay(delay_val);                           // do delay selected

#endif
}

