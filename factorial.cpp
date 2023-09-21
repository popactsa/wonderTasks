#include <iostream>
#include <string>

unsigned long long factorial(unsigned long long num){
    unsigned long long res = 1;
    for (unsigned long long i = 1; i <= num; ++i){
        res *= i;
    }
    return res;
}

int main(){
    std::string num_entered;
    entry:
    std::cin>>num_entered;
    std::cout<<std::endl;
    for(auto i : num_entered){
        if(i < '0' ^ i > '9'){
            std::cout<<"unappropriate value"<<std::endl;
            goto entry;
        }
    }
    //
    unsigned long long num = stoi(num_entered);
    if (num > 1000){
        std::cout<<"a value is too big"<<std::endl;
        goto entry;
    }
    std::cout<<num<<std::endl;
    std::cout<<factorial(num);
    return 0;
}