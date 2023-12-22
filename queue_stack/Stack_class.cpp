#include <iostream>
#include <vector>
#include "Stack_class.h"


int Stack::pop(){
    int temp;
        if (data.size() != 0){
            temp = data[data.size()-1];
            data.pop_back();
            return temp;
        }
        else{
            std::cout<<"error"<<std::endl;
            return INT_MAX;
        }
}