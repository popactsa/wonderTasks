#include <iostream>
#include <fstream>
#include "CRectangleClass.h"

CRectangleClass::CRectangleClass(double xlength, double ylength, double lup_x, double lup_y): a(xlength), b(ylength), x1(lup_x), x2(lup_x - xlength), y1(lup_y), y2(lup_y - ylength){};

CRectangleClass::CRectangleClass(std::string file, int num){
    std::ifstream fin(file);
        std::string temp;
        if (!fin.is_open()){
            std::cout<<"Error";
        }
        else{
            for (int i = 0; i < num; ++i){
            std::getline(fin, temp);
        }
            fin >> a >> b >> x1 >> y1 >> x2 >> y2;
        }
};

bool CRectangleClass::check_collision(CRectangleClass& another_rectangle){
    if ((another_rectangle.x1 - x1 <= another_rectangle.a) && (another_rectangle.y1 - y1 <= another_rectangle.b)){
            return true;
        }
        else{
            return false;
        }
};