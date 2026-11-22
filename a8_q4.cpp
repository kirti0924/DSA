#include <iostream>
#include <climits>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
};

node* createNode(int x) {
    node *t = new node;
    t->data = x;
    t->left = NULL;
    t->right = NULL;
    return t;
}

bool isBST(node *root, long long minValue, long long maxValue) {
    if (root == NULL)
        return true;

    if (root->data <= minValue || root->data >= maxValue)
        return false;

    return isBST(root->left, minValue, root->data) &&
           isBST(root->right, root->data, maxValue);
}

int main() {
    node *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    if (isBST(root, LLONG_MIN, LLONG_MAX))
        cout << "The binary tree is a BST";
    else
        cout << "The binary tree is not a BST";

    return 0;
}