#include "CRectangleClass.h"
#include <iostream>

int main()
{
    CRectangleClass rectangle1("rectangle_data.txt", 0);
    CRectangleClass rectangle2("rectangle_data.txt", 1);
    bool status = rectangle1.check_collision(rectangle2);
    std::cout<<status;
}