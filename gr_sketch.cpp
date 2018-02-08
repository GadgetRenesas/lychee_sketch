/* GR-LYCHEE Sketch Template V1.02 */
#include <Arduino.h>

#define INTERVAL 200

void setup()
{
	Serial.begin(9600);
    pinMode(LED_RED,    OUTPUT);
    pinMode(LED_ORANGE, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN,  OUTPUT);
    pinMode(USER_BUTTON0, INPUT);
}

void loop()
{
    while(digitalRead(USER_BUTTON0) == 0){
        digitalWrite(LED_GREEN, 1);
        delay(INTERVAL);
        digitalWrite(LED_GREEN, 0);
        delay(INTERVAL);
    	Serial.println("I'm LYCHEE!");
    }
    digitalWrite(LED_RED, 1);
    delay(INTERVAL);
    digitalWrite(LED_RED, 0);
    digitalWrite(LED_ORANGE, 1);
    delay(INTERVAL);
    digitalWrite(LED_ORANGE, 0);
    digitalWrite(LED_YELLOW, 1);
    delay(INTERVAL);
    digitalWrite(LED_YELLOW, 0);

}