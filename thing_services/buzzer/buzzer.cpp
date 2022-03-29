#include <wiringPi.h>
#include <iostream>

#define BUZZ_PIN 23

void pulse_buzz() {
    wiringPiSetupGpio();
    pinMode(BUZZ_PIN, OUTPUT);
    
    digitalWrite(BUZZ_PIN, HIGH);
    delay(2000);
    digitalWrite(BUZZ_PIN, LOW);
    
}

int main() {
	pulse_buzz();
	delay(1000);
	pulse_buzz();
}
