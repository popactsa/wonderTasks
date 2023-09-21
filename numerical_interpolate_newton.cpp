
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>
#include <new>
#include <vector>

int counter = 0;

double func(double x){
    return pow((x / 10.), sin(x));
}

void print(double x){
    std::cout<<x<<std::endl;
}

double div_diff(std::vector<double>& x){
    double temp = 0;
    int n = x.size();
    double sum = 0;
    for (int i = 0; i < n; ++i){
        temp = func(x[i]);
        for (int j = 0; j < n; ++j){    
            if (i != j){
                temp = temp / (x[i] - x[j]);
                counter++;
            }
        }
        sum += temp;
    }
    return sum;
}

std::vector<double> Newton_poly_producer(int ticks, int ticks_, std::vector<double>x_knots, std::vector<double>x){
    std::vector<double>res;
    std::vector<double>temp;
    for(int i = 0; i < ticks_; ++i){
        res.push_back(0.0);
    }
    for(int i = 0; i < ticks; ++i){
        temp.push_back(x_knots[i]);
    }

    for (int i = ticks-1; i > 0; i--){
        for(int j = 0; j < ticks_; ++j){
            res[j] += div_diff(temp);
            res[j] *= (x[j] - x_knots[i-1]);
            counter += 2;
        }
        temp.pop_back();
    }
    for(int i = 0; i < ticks_; ++i){
        res[i] += func(x_knots[0]);
        counter++;
    }
    temp.clear();
    return res;
}

int main(){
    double a, b;
    a = 0.;
    b = 10.;
    int ticks = 20;
    // double h = double((b - a) / ticks);
    ticks += 1;
    std::vector<double> x_knots;

    for (int i = 0; i < ticks; ++i){
        x_knots.push_back((b+a)/2 + (b-a)/2*cos((2*(ticks-1 - i)+1)*M_PI/(2*ticks)));
        // std::cout<<x_knots_ch[i]<<std::endl;
    }
    // for (int i = 0; i < ticks; ++i){
    //     x_knots.push_back(h*i);
    // }
    int ticks_ = 200;
    double h_ = double((b - a) / ticks_);
    ticks_ += 1;
    std::vector<double> x_interpolation_points;
    std::vector<double> y_interpolation_points;
    for (int i = 0; i < ticks_; ++i){
        x_interpolation_points.push_back(h_*i);
        y_interpolation_points.push_back(func(x_interpolation_points[i]));
        // std::cout<<x_interpolation_points[i]<<' '<<y_interpolation_points[i]<<std::endl;
    }

    std::ofstream outf("data_numerical_interpolate.txt");
    y_interpolation_points = Newton_poly_producer(ticks, ticks_, x_knots, x_interpolation_points);
    for (int i = 0; i < ticks_; ++i){
        outf << x_interpolation_points[i] << " " << y_interpolation_points[i] << std::endl;
    }
    outf.close();

    std::cout<<counter<<std::endl;


    return 0;
}