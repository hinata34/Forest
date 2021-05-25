#include "SplayTree.h"

SplayTree::SplayTree(super::RGB color)
{
	this->color = color;
	this->phases.resize(1000000, nullptr);
}

void SplayTree::insert(int64_t key)
{
	if (countHeight() == 0) {
		phases[index] = new super::Node(nullptr, nullptr, key, 1, 0, color);
	}
	else {
	    insertTrue(phases[index], key);
        this->phases[this->index] = splayTrue(this->phases[this->index], key);
	}
}
bool checkSplay(super::Node* elem, int64_t key) {
    if (elem == nullptr) {
        return false;
    }
    if (elem->key == key) {
        return true;
    }
    return (checkSplay(elem->right, key) || checkSplay(elem->left, key));
}
void SplayTree::remove(int64_t key)
{

    if (countHeight() != 0 && checkSplay(this->phases[this->index], key)) {
        this->phases[this->index] = removeTrue(this->phases[this->index], key);
    }
}

void SplayTree::splay(int64_t key)
{
    if (countHeight() != 0) {
        this->phases[this->index] = splayTrue(this->phases[this->index], key);
    }
}

void SplayTree::insertTrue(super::Node* top, int64_t key)
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


super::Node* SplayTree::rightRotate(super::Node* x)
{
	super::Node* y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

super::Node* SplayTree::leftRotate(super::Node* x)
{
	super::Node* y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

super::Node* SplayTree::splayTrue(super::Node* root, int64_t key)
{
    if (root == nullptr || root->key == key)
        return root;

    if (root->key > key)
    {
        if (root->left == nullptr) return root;

        if (root->left->key > key)
        {
            root->left->left = splayTrue(root->left->left, key);

            root = rightRotate(root);
        }
        else if (root->left->key < key) 
        {
            root->left->right = splayTrue(root->left->right, key);

            if (root->left->right != nullptr)
                root->left = leftRotate(root->left);
        }

        return (root->left == nullptr) ? root : rightRotate(root);
    }
    else 
    {
        if (root->right == nullptr) return root;

        if (root->right->key > key)
        {
            root->right->left = splayTrue(root->right->left, key);

            if (root->right->left != nullptr)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key) 
        {
            root->right->right = splayTrue(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

super::Node* SplayTree::removeTrue(super::Node* root, int64_t key)
{
    super::Node* temp;
    if (!root)
        return nullptr;

    root = splayTrue(root, key);


    if (key != root->key)
        return root;
 
    if (!root->left)
    {
        temp = root;
        root = root->right;
    }

    else
    {
        temp = root;


        root = splayTrue(root->left, key);

        root->right = temp->right;
    }


    delete(temp);

    return root;

}