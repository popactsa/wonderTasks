#include <iostream>
#include <string>
#include <stdio.h>   
#include <stdlib.h> 

struct for_a5{
    int m;
};

int main(void){
    int a1[5]{};

    using type_for_a2 = int[5];
    type_for_a2 a2;

    int *a3 = (int*)malloc(5*sizeof(int));
    if (a3){
        // for (int i = 0; i < 5; ++i){
        //     a3[i] = i;
        //     std::cout << (a3[i]) << std::endl ;
        // }
    }

    int *a4;
    a4 = (int*) calloc(5* sizeof(int));
    if (a4){
        // for (int i = 0; i < 5; ++i){
        //     a4[i] = i;
        //     std::cout << (a4[i]) << std::endl ;
        // }
    }
    for_a5 a5[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; ++i){
        std::cout << 
    }
}