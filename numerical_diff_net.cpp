#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

double f(double x){
    double res;
    res = sinh(1/(1+pow(x,2)));
    return res;
}

double rdiff(double x, double h){
    double res;
    res = (f(x+h) - f(x))/h;
    return res;
}

double ldiff(double x, double h){
    double res;
    res = (f(x-h) + f(x))/h;
    return res;
}

double cdiff(double x, double h){
    double res;
    res = (f(x+h) - f(x-h))/(2*h);
    return res;
}

double redge_diff(double x, double h){
    double res;
    res = (3*f(x) - 4*f(x-h) + f(x-2*h))/(2*h);
    return res;
}

double ledge_diff(double x, double h){
    double res;
    res = (-3*f(x) + 4*f(x+h) - f(x+2*h))/(2*h);
    return res;
}

void rvalues_builder(double a, double b, double h, std::vector<double>xnet, std::vector<double>& rf1values){
    double temp;
    unsigned short i;

    temp = a;
    i = 0;
    while(temp < b){
        rf1values.push_back(rdiff(xnet[i], h));
        i++;
        temp += h;
    }
    rf1values.push_back(ldiff(xnet[i], h));
}

void cvalues_builder(double a, double b, double h, std::vector<double>xnet, std::vector<double>& cf1values){
    double temp;
    temp = a;
    cf1values.push_back(ledge_diff(xnet[0], h));

    unsigned short i;
    i = 1;
    while(temp < b){
        cf1values.push_back(cdiff(xnet[i], h));
        i++;
        temp += h;
    }
    cf1values.push_back(redge_diff(xnet[i], h));
}

double c2diff2(double x, double h){
    double res;
    res = (f(x-h) - 2*f(x) + f(x+h))/pow(h, 2);
    return res;
}

double ledge_2diff2(double x, double h){
    double res;
    res = (2*f(x) - 5*f(x+h) + 4*f(x+2*h)-f(x+3*h))/pow(h, 2);
    return res;
}

double redge_2diff2(double x, double h){
    double res;
    res = (-2*f(x-3*h) + 5*f(x-2*h) - 4*f(x-h) + f(x))/pow(h, 2);
    return res;
}

void c2values2_builder(double a, double b, double h, std::vector<double>xnet, std::vector<double>& cf2values2){
    double temp;
    temp = a;
    cf2values2.push_back(ledge_2diff2(xnet[0], h));

    unsigned short i;
    i = 1;
    while(temp < b){
        cf2values2.push_back(c2diff2(xnet[i], h));
        i++;
        temp += h;
    }
    cf2values2.push_back(redge_2diff2(xnet[i], h));
}

double ledge_2diff4(double x, double h){
    double res;
    res = (15/4*f(x) - 77/6*f(x+h) + 107/6*f(x+2*h) - 13*f(x+3*h) + 61/12*f(x+4*h) - 5/6*f(x+5*h))/pow(h, 2);
    return res;
}

double redge_2diff4(double x, double h){
    double res;
    res = (-15/4*f(x-5*h) + 77/6*f(x-4*h) - 107/6*f(x-3*h) + 13*f(x-2*h) - 61/12*f(x-h) + 5/6*f(x))/pow(h, 2);
    return res;
}

double c2diff4(double x, double h){
    double res;
    res = (-1/12*f(x-2*h) + 4/3*f(x-h) - 5/2*f(x) + 4/3*f(x+h) - 1/12*f(x+2*h))/pow(h, 2);
    return res;
}

void c2values4_builder(double a, double b, double h, std::vector<double>xnet, std::vector<double>& cf2values4, int steps){
    double temp;
    temp = a;
    cf2values4.push_back(ledge_2diff4(xnet[0], h));
    cf2values4.push_back(ledge_2diff4(xnet[0], h));

    unsigned short i;
    i = 2;
    while(i < steps - 2){
        cf2values4.push_back(c2diff4(xnet[i], h));
        i++;
        temp += h;
    }
    cf2values4.push_back(redge_2diff4(xnet[steps - 2], h));
    cf2values4.push_back(redge_2diff4(xnet[steps - 1], h));
}

int main(){
    double a, b, h;
    a = -3.0;
    b = 3.0;
    h = 0.1;
    std::vector<double>xnet;
    double temp;
    temp = a;

    int steps;
    steps = 0;
    while (temp <= b){
        ++steps;
        xnet.push_back(temp);
        temp += h;
    }
    std::cout<<steps;
    std::vector<double>rf1values;
    std::vector<double>cf1values;
    rvalues_builder(a, b, h, xnet, rf1values);
    cvalues_builder(a, b, h, xnet, cf1values);

    std::ofstream outf1("data1.txt");
    for (int i = 0; i < steps; ++i){
        outf1 << xnet[i] << ' ' << rf1values[i] << ' ' << cf1values[i] << std::endl;
    }
    outf1.close();

    std::vector<double>cf2values2;
    c2values2_builder(a, b, h, xnet, cf2values2);

    std::ofstream outf2("data2.txt");
    for (int i = 0; i < steps; ++i){
        outf2 << xnet[i] << ' ' << cf2values2[i] << std::endl;
    }
    outf2.close();

    std::vector<double>cf2values4;
    c2values4_builder(a, b, h, xnet, cf2values4, steps);

    std::ofstream outf3("data3.txt");
    for (int i = 0; i < steps; ++i){
        outf3 << xnet[i] << ' ' << cf2values2[i] << std::endl;
    }
    outf3.close();
}