#include "general.h"
#include <iostream>

void General::push(int pushed_element) {
    data.push_back(pushed_element);
}

void General::print(){
    for (auto it : data){
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}