
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>
#include <new>

double func(double x){
    return pow((x / 10), sin(x));
}

int main(){
    double a, b;
    a = 0.;
    b = 10.;
    int ticks = 50;
    double h = double((b - a) / ticks);
    ticks += 1;
    double *x_knots = new double[ticks];
    double *y_knots = new double[ticks];
    for (int i = 0; i < ticks; ++i){
        x_knots[i] = h * i;
        y_knots[i] = func(x_knots[i]);
        std::cout<<x_knots[i]<<std::endl;
    }

    int ticks_ = 20;
    double h_ = double(10. / ticks_);
    ticks_ += 1;
    double *x_interpolation_points = new double[ticks_];
    double *y_interpolation_points = new double[ticks_];
    for (int i = 0; i < ticks_; ++i){
        x_interpolation_points[i] = h_ * i;
        y_interpolation_points[i] = 0.0;
        // std::cout<<x_interpolation_points[i]<<' '<<y_interpolation_points[i]<<std::endl;
    }
    
    double temp_multiplier = 1;
    for (int num = 0; num < ticks_; ++num){
        for (int j = 0; j < ticks; ++j){
            for (int i = 0; i < ticks; ++i){
                if (i != j){
                    temp_multiplier *= (x_interpolation_points[num] - x_knots[i])/(x_knots[j] - x_knots[i]);
                }
            }
            temp_multiplier *= y_knots[j];
            y_interpolation_points[num] += temp_multiplier;
            temp_multiplier = 1;
        }
    }

    std::ofstream outf("data_numerical_interpolate.txt");
    // for (int i = 0; i < ticks_; ++i){
    //     outf << x_interpolation_points[i] << " " << y_interpolation_points[i] << std::endl;
    // }
    // for (int i = 0; i < ticks_; ++i){
    //     std::cout << y_interpolation_points[i] << std::endl;
    // }
    double *x_knots_ch = new double[ticks];
    double *y_knots_ch = new double[ticks];

    for (int i = 0; i < ticks; ++i){
            x_knots_ch[i] = (b+a)/2 + (b-a)/2*cos((2*(ticks-1 - i)+1)*M_PI/(2*ticks));
            // std::cout<<x_knots_ch[i]<<std::endl;
            y_knots_ch[i] = func(x_knots_ch[i]);
    }

    double *y_interpolation_points_ch = new double[ticks_];
    for (int i = 0; i < ticks_; ++i){
        y_interpolation_points_ch[i] = 0.0;
    }

    int counter = 0;
    temp_multiplier = 1;
    for (int num = 0; num < ticks_; ++num){
        for (int j = 0; j < ticks; ++j){
            for (int i = 0; i < ticks; ++i){
                if (i != j){
                    temp_multiplier *= (x_interpolation_points[num] - x_knots_ch[i])/(x_knots_ch[j] - x_knots_ch[i]);
                    counter++;
                }
            }
            temp_multiplier *= y_knots_ch[j];
            y_interpolation_points_ch[num] += temp_multiplier;
            temp_multiplier = 1;
            counter += 3;
        }
    }

    std::cout<<counter<<std::endl;

    for (int i = 0; i < ticks_; ++i){
        outf << x_interpolation_points[i] << " " << y_interpolation_points_ch[i] << std::endl;
    }
    outf.close();
    // for (int i = 0; i < ticks_; ++i){
    //     std::cout << y_interpolation_points[i] << std::endl;
    // }
    delete x_knots_ch, y_knots_ch, x_knots, y_knots, y_interpolation_points, y_interpolation_points_ch, x_interpolation_points;
}