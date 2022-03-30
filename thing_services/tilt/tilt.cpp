#include <wiringPi.h>
#include <iostream>

#define TILT_PIN 24

int read_tilt() {
    wiringPiSetupGpio();
    pinMode(TILT_PIN, INPUT);

    if(digitalRead(TILT_PIN) == HIGH) {
        return 1;
    }
    else {
        return 0;
        
    }
}

int main() {
    while(true){
        std::cout << read_tilt() << std::endl;
    }
}
