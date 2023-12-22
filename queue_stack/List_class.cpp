#include <vector>
#include <iostream>
#include "List_class.h"

bool List::is_empty(){
	if (first == nullptr){
		return true;
	}
	else{
		return false;
	}
}

List::List(std::vector<int> init){
	List();
	for (auto it : init){
		push(it);
	}
}

void List::push(int pushed_element){
	Node* p = new Node(pushed_element);
	if (is_empty()){
		first = p;
		return;
	}
	else{
		p->next = first;
		first = p;
	}
}

int List::pop(){
	Node* temp = first;
	int res = first->value;
	first = first->next;
	std::cout<<res<<std::endl;
	delete temp;
	return res;
}

void List::print(){
	Node* p = first;
	while (p->next != nullptr){
		std::cout<<p->value<<" ";
		p = p->next;
	}
	std::cout<<p->value<<" ";
	std::cout<<std::endl;
}