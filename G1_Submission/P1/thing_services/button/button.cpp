#include <wiringPi.h>
#include <iostream>

#define BUTTON_PIN 12

int isButtonPushed() {
	// Setup WiringPi GPO
	wiringPiSetupGpio();
	//Pin mode is input for this sensor since we are reading.
	pinMode(BUTTON_PIN, INPUT);

	// If we read low, return 1 (Button is active low)
	if (digitalRead(BUTTON_PIN)==LOW) {
		return 1;
	}
	// Else return 0
	return 0;
}


int main() {
	// Print if button is pushed or not (1/0)
	std::cout<<"Is button pushed: "<<isButtonPushed()<<std::endl;
}
