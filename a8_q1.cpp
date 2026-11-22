#include <iostream>
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

void preorder(node *root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    cout << "Pre-order: ";
    preorder(root);

    cout << "\nIn-order: ";
    inorder(root);

    cout << "\nPost-order: ";
    postorder(root);

    return 0;
}