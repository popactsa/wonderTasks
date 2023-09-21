#include <iostream>
#include <string>

void fibonacci(unsigned int num){
    unsigned int res = 1;
    unsigned int prev = 0;
    unsigned int temp = 0;

    std::cout<<temp<<' ';
    for (unsigned long long i = 0; i <= num-2; ++i){
        std::cout<<res<<' ';
        temp = res;
        res += prev;
        prev = temp;
    }
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
    unsigned int num = stoi(num_entered);
    if (num > 100 ^ num == 0){
        std::cout<<"incorrect value"<<std::endl;
        goto entry;
    }
    std::cout<<num<<std::endl;
    fibonacci(num);
    return 0;
}