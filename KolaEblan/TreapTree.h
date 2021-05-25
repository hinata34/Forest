#pragma once
#include "Tree.h"
class TreapTree :
    public Tree
{
public:
	TreapTree(super::RGB color);
	void insert(int64_t key) override;

	void remove(int64_t key) override;
private:
	void splitTree(super::Node* point_tree, int64_t key, super::Node*& left, super::Node*& right);
	super::Node* mergeTree(super::Node* left, super::Node* right);
};

