#include "Button.hpp"
#include <wiringPi.h>

#define BTN_PIN 24;

int main(){
    Button button_logger;

    wiringPiSetupGpio();
    pinMode(BTN_PIN, INPUT);

    while(true){
        if (digitalRead(BTN_PIN) == HIGH){
            button_logger.log_push();
        }
        while(digitalRead(BTN_PIN) == HIGH);
        delay(500);
    }

}