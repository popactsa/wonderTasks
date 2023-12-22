#include "Tree_class.h"
#include <vector>
#include <iostream>

Tree::Tree(std::vector<int> values)
{
	root = nullptr;
	for (const auto value : values)
	{
		push_call(root, value, nullptr, false); // false = left, true = right
	}
}

void Tree::push_call(BNode *temp_root, int value, BNode *prev, bool side)
{
	if (temp_root == nullptr)
	{
		temp_root = (BNode *)malloc(sizeof(BNode));
		temp_root->left = nullptr;
		temp_root->right = nullptr;
		temp_root->key = value;
		if (prev == nullptr)
		{
			root = temp_root;
		}
		else
		{
			if (side == false)
			{
				prev->left = temp_root;
			}
			else
			{
				prev->right = temp_root;
			}
		}
	}
	else
	{
		if (value < temp_root->key)
		{
			push_call(temp_root->left, value, temp_root, 0);
		}
		else
		{
			push_call(temp_root->right, value, temp_root, 1);
		}
	}
}

void Tree::push(int value)
{
	BNode *temp = root;
	push_call(temp, value, nullptr, 0);
}

bool Tree::is_empty()
{
	if (root->left == nullptr && root->right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Tree::print()
{
	print_call(root);
}

void Tree::print_call(BNode *p)
{
	if (p != nullptr)
	{
		std::cout << p->key << " ";
		print_call(p->left);
		print_call(p->right);
	}
}

BNode* Tree::find_call(int value, BNode *p, BNode* prev, bool in_return = 1){ // 0 - previous, 1 - exact
	if (p != nullptr)
	{
		if (p->key == value){
			if (in_return == 1){
				return p;
			}
			else{
				return prev;
			}
		}
		else{
		find_call(value, p->left, p, in_return);
		find_call(value, p->right, p, in_return);
		}
		return nullptr; // "no such value" error
	}
}

BNode* Tree::find(int value, bool in_return = 1){// 0 - previous, 1 - exact
	BNode *p = find_call(value, root, nullptr, in_return);
	return p;
}	

int Tree::pop(int value){
	BNode*p = find(value);
	int case_status = 0; // 0 - no descendants, 1 - one descen., 2 - both
	if (p->left != nullptr){
		case_status++;
	}
	else if (p->right != nullptr){
		case_status++;
	}
	BNode* prev = find(value, false);
	bool side;
	if (prev->left == p){
		side = false;
	}
	else{
		side = true;
	}
	if (case_status == 0){
		if (side == false){
			prev->left = nullptr;
			free(p);
		}
		else{
			prev->right = nullptr;
			free(p);
		}
	}
	else if (case_status == 1){
		bool leaf_side;
		if (p->left != nullptr){
			leaf_side == false;
		}
		else{
			leaf_side == true;
		}
		if (side == false){
			if (leaf_side == false){
				prev->left = p->left;
				free(p);
			}
			else{
				prev->left = p->right;
				free(p);
			}
		}
		else{
			if (leaf_side == false){
				prev->right = p->left;
				free(p);
			}
			else{
				prev->right = p->right;
				free(p);
			}
		}
	}
	else if(case_status == 2){
		BNode* spar = p->right;
		BNode* spar_prev = p;
		while(spar->left != nullptr){
			spar_prev = spar;
			spar = spar->left;
		}
		if (spar == p->right && spar->right == nullptr){
			p->key = spar->key;
			p->right = spar->right;
			free(spar);
		}
		else if(spar != p->right && spar->right == nullptr){
			p->key = spar->key;
			free(spar);
		}
		else if(spar == p->right && spar->right != nullptr){
			p->key = spar->key;
			p->right = spar->right;
			free(spar);
		}
		else if(spar != p->right && spar->right != nullptr){
			p->key = spar->key;
			spar_prev->left = spar->right;
			free(spar);
		}
	}
	return value;
}
