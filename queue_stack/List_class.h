#ifndef LIST_CLASS_H
#define LIST_CLASS_H

#include "Node_class.h"
#include <vector>

class List{
    private:
        Node *first;
    public:
        List(): first(nullptr){}
        List(std::vector<int> init);
        void push(int pushed_element);
        bool is_empty();    
        void print();
        int pop();
};

#endif