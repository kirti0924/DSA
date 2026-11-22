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

// (a) Insert an element
node* insert(node *root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        cout << "Duplicate element not allowed\n";

    return root;
}

node* minimum(node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// (b) Delete an element
node* deleteNode(node *root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // No left child
        if (root->left == NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // No right child
        if (root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        node *temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// (c) Maximum depth
int maxDepth(node *root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if (leftDepth > rightDepth)
        return leftDepth + 1;

    return rightDepth + 1;
}

// (d) Minimum depth
int minDepth(node *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return minDepth(root->right) + 1;

    if (root->right == NULL)
        return minDepth(root->left) + 1;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (leftDepth < rightDepth)
        return leftDepth + 1;

    return rightDepth + 1;
}

void inorder(node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node *root = NULL;
    int choice, x;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display In-order";
        cout << "\n4. Maximum Depth";
        cout << "\n5. Minimum Depth";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element: ";
            cin >> x;
            root = insert(root, x);
            break;

        case 2:
            cout << "Enter element to delete: ";
            cin >> x;
            root = deleteNode(root, x);
            break;

        case 3:
            cout << "In-order: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Maximum depth: " << maxDepth(root) << endl;
            break;

        case 5:
            cout << "Minimum depth: " << minDepth(root) << endl;
            break;

        case 0:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}