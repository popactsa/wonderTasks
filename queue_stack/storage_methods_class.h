#ifndef STORAGE_METHODS_CLASS_H
#define STORAGE_METHODS_CLASS_H
#include <vector>

class Storage_methods{
    protected:
        virtual int pop() = 0;
        virtual void push(int pushed_element) = 0;
        ~Storage_methods(){};
};

#endif