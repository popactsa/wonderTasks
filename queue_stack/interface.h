#ifndef INTERFACE_H
#define INTERFACE_H

class Interface{
    protected:
        virtual int pop() = 0;
        virtual void push(int pushed_element) = 0;
        virtual void print() = 0;
};

#endif