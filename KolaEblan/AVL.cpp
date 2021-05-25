#include "AVL.h"

AVL::AVL(super::RGB color)
{
	this->color = color;
	this->phases.resize(1000000, nullptr);
}

void AVL::insert(int64_t key)
{
	if (countHeight() == 0) {
		phases[index] = new super::Node(nullptr, nullptr, key, 1, -1, color);
	}
	else {
		phases[index] = insertTrue(phases[index], key);
	}
}

void AVL::remove(int64_t key)
{
    if (countHeight() == 0) {
        return;
    }
    else {
        phases[index] = removeTrue(phases[index], key);
    }
}
int height(super::Node* node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}
int getBalance(super::Node* node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
super::Node* AVL::insertTrue(super::Node* node, int64_t key)
{
    if (node == nullptr)
        return(new super::Node(nullptr, nullptr, key, 1, -1, color));

    if (key < node->key)
        node->left = insertTrue(node->left, key);
    else if (key > node->key)
        node->right = insertTrue(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));


    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
super::Node* minValueNode(super::Node* node)
{
    super::Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}
super::Node* AVL::removeTrue(super::Node* root, int64_t key)
{
    if (root == NULL)
        return root;


    if (key < root->key)
        root->left = removeTrue(root->left, key);


    else if (key > root->key)
        root->right = removeTrue(root->right, key);


    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            super::Node* temp = root->left ?
                root->left :
                root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp; 
            free(temp);
        }
        else
        {

            super::Node* temp = minValueNode(root->right);


            root->key = temp->key;

            root->right = removeTrue(root->right,
                temp->key);
        }
    }


    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));


    int balance = getBalance(root);


    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

super::Node* AVL::rightRotate(super::Node* y)
{
    super::Node* x = y->left;
    super::Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

super::Node* AVL::leftRotate(super::Node* x)
{
    super::Node* y = x->right;
    super::Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
