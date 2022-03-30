#include <wiringPi.h>
#include <iostream>

#define BUZZ_PIN 23

void pulse_buzz(int time) {
    // Setup WiringPi GPIO
    wiringPiSetupGpio();
    // Pin is output since it's an actuator
    pinMode(BUZZ_PIN, OUTPUT);
    
    // Write high on pin to start buzzer
    digitalWrite(BUZZ_PIN, HIGH);
    // Wait the specified amount of time
    delay(time);
    // Write back low to turn off
    digitalWrite(BUZZ_PIN, LOW);
    
}

int main() {
    // Call function with different times. Wait inbetween calls to make sure you can hear the pulses
	pulse_buzz(2000);
	delay(1000);
	pulse_buzz(2000);
}
