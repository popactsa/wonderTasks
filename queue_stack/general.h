#ifndef GENERAL_H
#define GENERAL_H
#include "interface.h"
#include <vector>

class General: public Interface{
    public:
        std::vector<int> data;
        General(std::vector<int> init): data(init){};
        void push(int pushed_element);
        void print();
};

#endif