#ifndef NODE_H
#define NODE_H

class Node{
	public:
		int value;
		Node* next;
		Node(int prev_value): value(prev_value), next(nullptr){};
};

#endif