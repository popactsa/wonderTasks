#include <iostream>
#include <new>

int main(void){
    double **p = 0;
    double *l = new double(2);
    p = &l;
    std::cout << **p << std::endl;
    delete l;
}