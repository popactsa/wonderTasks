#ifndef CRATIONAL_H
#define CRATIONAL_H
#include <array>
#include <string>

class CRational{
	private:
		int numerator;
		int denominator;
		float decimal;
		int euclid_algorithm(int num1, int num2);
	public:
		CRational(){}
		CRational(int nu, int deno);
		CRational(float dec_value);
		void getDecimal();
		void getRational();
		friend const CRational operator + (const CRational& init_value, const CRational& add_value);
		friend const CRational operator - (const CRational& init_value, const CRational& sub_value);
		friend const CRational operator * (const CRational& init_value, const CRational& mult_value);
};

#endif