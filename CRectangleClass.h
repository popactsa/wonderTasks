#ifndef CRECTANGLECLASS_H
#define CRECTANGLECLASS_H

class CRectangleClass
{
private:
    double a;
    double b;
    double x1, y1;
    double x2, y2;

public:
    CRectangleClass(double xlength, double ylength, double lup_x, double lup_y)
    {
        a = xlength;
        b = ylength;
        x1 = lup_x;
        y1 = lup_y;
        x2 = lup_x - xlength;
        y2 = lup_y - ylength;
    };
    CRectangleClass(std::string file){
        std::ifstream fin(file);
        if (!fin.is_open()){
            std::cout<<"Error";
        }
        else{
            fin >> a >> b >> x1 >> y1 >> x2 >> y2;
        }
    };
    bool check_collision(CRectangleClass another_rectangle)
    {
        if ((another_rectangle.x1 - x1 <= another_rectangle.a) && (another_rectangle.y1 - y1 <= another_rectangle.b)){
            return true;
        }
        else{
            return false;
        }
    };
};

#endif