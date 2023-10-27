#include <iostream>
#include <fstream>
#include "CRectangleClass.h"

int main()
{
    CRectangleClass rectangle_file("rectangle_data.txt");
    CRectangleClass rectangle1(1.0, 2.0, 1.0, 2.0);
    CRectangleClass rectangle2(3.0, 2.0, 200.0, 3.0);
    bool status = rectangle_file.check_collision(rectangle2);
    std::cout<<status;
}