#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include "CRational.h"

int CRational::euclid_algorithm(int num1, int num2){
	if (num2 == 0){
		return num1;
	}
	else{
		return euclid_algorithm(num2, num1 % num2);
	}
}

CRational::CRational(int nu, int deno){
	try{
		if (deno == 0){
			throw("deno = 0");
		}
	}
	catch(const char*){
		std::cout<<"Denominator equals 0"<<std::endl;
		exit(0);
	}
	int gcd = euclid_algorithm(nu, deno);
	nu /= gcd;
	deno /= gcd;
	numerator = nu;
	denominator = deno;
	decimal = float(numerator) / float(denominator);
}

CRational::CRational(float dec_value){
	int temp_nu = int(dec_value / 1.0);
	float temp = std::remainder(dec_value, 1.0);
	int temp_deno = int(temp * 1.0e4);
	int gcd = euclid_algorithm(temp_nu*10000 + temp_deno, 10000);
	denominator = 10000 / gcd;
	numerator = (temp_nu*10000 + temp_deno)/gcd;

	decimal = float(numerator) / float(denominator);
}

void CRational::getDecimal(){
	std::cout<<decimal<<std::endl;
}

void CRational::getRational(){
	std::cout<<numerator<<" / "<<denominator<<std::endl;
}

const CRational operator + (const CRational& init_value, const CRational& add_value){
	int sum_numerator;
	int sum_denominator;
	sum_numerator = init_value.numerator*add_value.denominator + init_value.denominator*add_value.numerator;
	sum_denominator = init_value.denominator*add_value.denominator;
	return CRational(sum_numerator, sum_denominator);
}

const CRational operator - (const CRational& init_value, const CRational& sub_value){
	int sub_numerator;
	int sub_denominator;
	sub_numerator = init_value.numerator*sub_value.denominator - init_value.denominator*sub_value.numerator;
	sub_denominator = init_value.denominator*sub_value.denominator;
	return CRational(sub_numerator, sub_denominator);
}

const CRational operator * (const CRational& init_value, const CRational& mult_value){
	int mult_numerator;
	int mult_denominator;
	mult_numerator = init_value.numerator*mult_value.numerator;
	mult_denominator = init_value.denominator*mult_value.denominator;
	return CRational(mult_numerator, mult_denominator);
}

