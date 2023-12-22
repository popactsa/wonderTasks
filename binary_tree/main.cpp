#include <vector>
#include <iostream>
#include "Tree_class.h"

int main(){
	std::vector<int> values = {20, 5, 23, 2, 16, 21, 28};
	Tree t(values);
	t.push(6);
	t.print();
	t.pop(28);
	t.print();
}