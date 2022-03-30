#include <wiringPi.h>
#include <iostream>

#define TILT_PIN 24

int read_tilt() {
    // WiringPi GPIO Setup
    wiringPiSetupGpio();
    // Pin mode is input since we are reading
    pinMode(TILT_PIN, INPUT);

    // If upright, should read high
    if(digitalRead(TILT_PIN) == HIGH) {
        // so return 1
        return 1;
    }
    else {
        // else it's inverted so return 0
        return 0;
        
    }
}

int main() {
    // continously read the orientation
    while(true){
        std::cout << read_tilt() << std::endl;
    }
}
