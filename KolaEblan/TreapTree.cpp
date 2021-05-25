#include "TreapTree.h"

TreapTree::TreapTree(super::RGB color)
{
	this->color = color;
	this->phases.resize(1000000, nullptr);
}
bool checkTreap(super::Node* elem, int64_t key) {
    if (elem == nullptr) {
        return false;
    }
    if (elem->key == key) {
        return true;
    }
    return (checkTreap(elem->right, key) || checkTreap(elem->left, key));
}
void TreapTree::insert(int64_t key)
{
    if (checkTreap(this->phases[this->index], key)) {
        return;
    }
    super::Node* point_tmp = new super::Node(nullptr, nullptr, key, 0, rand() % 100000, color);
    super::Node* left_tree, * right_tree;

    splitTree(this->phases[this->index], key, left_tree, right_tree);

    this->phases[this->index] = mergeTree(left_tree, point_tmp);
    this->phases[this->index] = mergeTree(this->phases[this->index], right_tree);
}

void TreapTree::remove(int64_t key)
{
    if (!checkTreap(this->phases[this->index], key)) {
        return;
    }
    super::Node* left_tree, * right_tree;
    super::Node* left_tree_second, * right_tree_second;

    splitTree(this->phases[this->index], key, left_tree, right_tree);
    splitTree(right_tree, key + 1, left_tree_second, right_tree_second);

    this->phases[this->index] = mergeTree(left_tree, right_tree_second);
}

void TreapTree::splitTree(super::Node* point_tree, int64_t key, super::Node*& left, super::Node*& right)
{
    if (point_tree == nullptr) {
        left = nullptr;
        right = nullptr;
        return;
    }
    if (point_tree->key < key) {
        splitTree(point_tree->right, key, point_tree->right, right);
        left = point_tree;
    }
    else {
        splitTree(point_tree->left, key, left, point_tree->left);
        right = point_tree;
    }
}

super::Node* TreapTree::mergeTree(super::Node* left, super::Node* right)
{
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    if (left->priority > right->priority) {
        left->right = mergeTree(left->right, right);
        return left;
    }
    else {
        right->left = mergeTree(left, right->left);
        return right;
    }
}
