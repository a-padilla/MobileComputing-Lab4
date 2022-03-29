#include <wiringPi.h>
#include <iostream>
#define BUTTON_PIN 12

int isButtonPushed() {
	wiringPiSetupGpio();
	pinMode(BUTTON_PIN, INPUT);

	if (digitalRead(BUTTON_PIN)==LOW) {
		return 1;
			
	}
	return 0;
}


int main() {
	std::cout<<"Is button pushed: "<<isButtonPushed()<<std::endl;
	
}
