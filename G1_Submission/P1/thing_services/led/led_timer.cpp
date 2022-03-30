#include <wiringPi.h>
//#include <iostream>

#define LED_PIN 16

void pulse_led(int time) {
    // Setup WiringPi GPIO pins
    wiringPiSetupGpio();
    // Pin mode is output since this is an actuator
    pinMode(LED_PIN, OUTPUT);
    
    // Write high to turn on LED
    digitalWrite(LED_PIN, HIGH);
    // Wait specified amount of time
    delay(time);
    // Write back low to turn off
    digitalWrite(LED_PIN, LOW);
    
}

int main() {
    // Call function with different inputs, delay to see both pulses.
	pulse_led(2000);
	delay(1000);
	pulse_led(4000);
}
