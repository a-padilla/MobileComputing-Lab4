
#include "Button.hpp"

using namespace std::chrono_literals;

void Button::log_push(){
    button_push_count++;
}

void Button::clear_log(){
    button_push_count = 0;
}

string Button::Atlas_get_log(){
    return button_push_count;
}
