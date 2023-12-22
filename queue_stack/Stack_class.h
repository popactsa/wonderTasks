#ifndef STACK_CLASS_H
#define STACK_CLASS_H
#include "general.h"
#include <vector>

class Stack: public General {
    public:
        Stack(std::vector<int> init): General(init) {}
        int pop();
};

#endif