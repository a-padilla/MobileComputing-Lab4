#include <wiringPi.h>

#define TILT_PIN = 24
using namespace std;

int read_tilt() {
    wiringPiSetupGpio();
    pinMode(TILT_PIN, INPUT);

    if(digital_read(TILT_PIN) == HIGH) {
        return 1;
    }
    else {
        return 0;
        
    }
}

int main() {
    while(true){
        printf(read_tilt());
    }
}


