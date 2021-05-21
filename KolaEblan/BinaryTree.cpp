#include "BinaryTree.h"

BinaryTree::BinaryTree(super::RGB color)
{	
	this->color = color;
	this->phases.resize(1000000, nullptr);
}

void BinaryTree::insert(int64_t key)
{
	if (countHeight() == 0) {
		phases[index] = new super::Node(nullptr, nullptr, key, 0, 0, color);
	}
	else {
		insertTrue(phases[index], key);
	}
}


void BinaryTree::remove(int64_t key)
{
	removeTrue(phases[index], key);
}

void BinaryTree::insertTrue(super::Node* top, int64_t key)
{
	if (top == nullptr) {
		return;
	}
	if (top->key < key) {
		if (top->right == nullptr) {
			top->right = new super::Node(nullptr, nullptr, key, 0, 0, top->color);
		}
		else {
			insertTrue(top->right, key);
		}
	}
	else {
		if (top->key > key) {
			if (top->left == nullptr) {
				top->left = new super::Node(nullptr, nullptr, key, 0, 0, top->color);
			}
			else {
				insertTrue(top->left, key);
			}
		}
	}
}

void BinaryTree::removeTrue(super::Node* top, int64_t key)
{
	if (top == nullptr) {
		return;
	}
	if (top->right != nullptr) {
		if (top->right->key == key) {
			;
		}
	}
}
