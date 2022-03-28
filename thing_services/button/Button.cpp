
#include "Button.hpp"

#include <chrono>
#include <thread>
#include <iomanip>
#include <time.h>

using namespace std::chrono_literals;


Button::Button()
{
}

void Button::log_push(){
    auto timenow =
      chrono::system_clock::to_time_t(chrono::system_clock::now());
  
    cout << ctime(&timenow) << "\n";
    push_log.push_back(timenow);
}

void Button::clear_log(){
    push_log.clear();
}

string Button::Atlas_get_log(){
    string temp;
    for (auto &&time : push_log)
    {
        auto local = localtime(&time);
        temp += asctime(local);
    }
    
    return temp;
}
