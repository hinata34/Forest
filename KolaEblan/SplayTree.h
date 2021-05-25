#pragma once
#include "Tree.h"
class SplayTree :
    public Tree
{
public:
	SplayTree(super::RGB color);
	void insert(int64_t key) override;

	void remove(int64_t key) override;

	void splay(int64_t key);
private:
	void insertTrue(super::Node* node, int64_t key);
	super::Node* removeTrue(super::Node* root, int64_t key);
	super::Node* rightRotate(super::Node* x);
	super::Node* leftRotate(super::Node* x);
	super::Node* splayTrue(super::Node* root, int64_t key);
};

