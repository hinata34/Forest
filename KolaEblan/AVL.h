#pragma once
#include "Tree.h"
class AVL :
    public Tree
{
public:
	AVL(super::RGB color);
	void insert(int64_t key) override;

	void remove(int64_t key) override;
private:
	super::Node* insertTrue(super::Node* node, int64_t key);
	super::Node* removeTrue(super::Node* root, int64_t key);
	super::Node* rightRotate(super::Node* y);
	super::Node* leftRotate(super::Node* x);
};

