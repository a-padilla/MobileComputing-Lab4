

#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <ctime>
#include <chrono>
using namespace std;

class Button
{
private:

    int button_push_count;

public:
    Button() : button_push_count(0) {}
    void log_push();
    void clear_log();
    string Atlas_get_log();
};
