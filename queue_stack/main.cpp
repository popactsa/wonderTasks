#include <iostream>
#include <vector>
#include <algorithm>
#include "List_class.h"

// template <class T>

// void reverse(T& given_type_unit){
//     std::reverse(given_type_unit.data.begin(), given_type_unit.data.end());
// }

int main(){
    std::vector<int> vec{1, 2, 3, 4, 5};
    List q(vec);
    int temp;
    q.print();
    q.pop();
    q.print();
    return 0;
}