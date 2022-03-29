#include <wiringPi.h>
#include <iostream>

#define BUZZ_PIN 23

void pulse_buzz(int time) {
    wiringPiSetupGpio();
    pinMode(BUZZ_PIN, OUTPUT);
    
    digitalWrite(BUZZ_PIN, HIGH);
    delay(time);
    digitalWrite(BUZZ_PIN, LOW);
    
}

int main() {
	pulse_buzz(2000);
	delay(1000);
	pulse_buzz(2000);
}
