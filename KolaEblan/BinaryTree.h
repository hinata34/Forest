#pragma once
#include "Tree.h"
class BinaryTree : public Tree{
public:
	BinaryTree(super::RGB color);
	void insert(int64_t key) override;
	
	void remove(int64_t key) override;
private:
	void insertTrue(super::Node* top, int64_t key);
	void removeTrue(super::Node* top, int64_t key);
};

