#include <vector>
#include <iostream>
#include "Queue_class.h"

int Queue::pop(){
    int temp;
        if (data.size() != 0){
            temp = *data.begin();
            data.erase(data.begin());
            return temp;
        }
        else{
            std::cout<<"error"<<std::endl;
            return INT_MAX;
        }
}