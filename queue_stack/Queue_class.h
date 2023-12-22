#ifndef QUEUE_CLASS_H
#define QUEUE_CLASS_H
#include "general.h"
#include <vector>

class Queue: public General {
    public:
        Queue(std::vector<int> init): General(init) {}
        int pop();
};

#endif