#ifndef BINARY_TREE_CLASS_H
#define BINARY_TREE_CLASS_H

#include "Binary_node_class.h"
#include <vector>

class Tree{
    private:
        BNode *root;
        void print_call(BNode *p);
        void push_call(BNode* temp_root, int value, BNode* prev, bool side);
        BNode* find_call(int value, BNode* p, BNode* prev, bool in_return);
    public:
        Tree(std::vector<int> values);
        void push(int value);
        bool is_empty();    
        void print(); //NLR
        BNode* find(int value, bool in_return);
        int pop(int value);
};

#endif