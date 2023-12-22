#ifndef BINARY_NODE_H
#define BINARY_NODE_H


class BNode{
	public:
		int key;
		BNode* left;
		BNode* right;
		BNode(int value): key(value), right(nullptr), left(nullptr){};
};

#endif