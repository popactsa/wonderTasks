#ifndef CRECTANGLECLASS_H
#define CRECTANGLECLASS_H

#include <string>

class CRectangleClass
{
private:
    double a;
    double b;
    double x1, y1;
    double x2, y2;

public:
    CRectangleClass(double xlength, double ylength, double lup_x, double lup_y); 
    CRectangleClass(std::string file, int num);
    bool check_collision(CRectangleClass& another_rectangle);
};

#endif