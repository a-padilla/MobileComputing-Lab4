

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

    vector<time_t> push_log;

public:
    Button(/* args */);
    void log_push();
    void clear_log();
    string Atlas_get_log();
};
