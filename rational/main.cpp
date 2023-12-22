#include <iostream>
#include "CRational.h"

int main(){
	CRational first(2, 0);
	CRational second(3, 7);
	CRational res;
	res = first + second;
	res.getRational();
}