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

node* insert(node *root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// (a) Recursive search
bool searchRecursive(node *root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return searchRecursive(root->left, key);

    return searchRecursive(root->right, key);
}

// (a) Non-recursive search
bool searchNonRecursive(node *root, int key) {
    node *temp = root;

    while (temp != NULL) {
        if (temp->data == key)
            return true;

        if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return false;
}

// (b) Maximum element
node* maximum(node *root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// (c) Minimum element
node* minimum(node *root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// (d) In-order successor
node* successor(node *root, int key) {
    node *current = root;
    node *succ = NULL;

    while (current != NULL) {
        if (key < current->data) {
            succ = current;
            current = current->left;
        } else if (key > current->data) {
            current = current->right;
        } else {
            if (current->right != NULL)
                return minimum(current->right);

            return succ;
        }
    }

    return NULL;
}

// (e) In-order predecessor
node* predecessor(node *root, int key) {
    node *current = root;
    node *pred = NULL;

    while (current != NULL) {
        if (key > current->data) {
            pred = current;
            current = current->right;
        } else if (key < current->data) {
            current = current->left;
        } else {
            if (current->left != NULL)
                return maximum(current->left);

            return pred;
        }
    }

    return NULL;
}

int main() {
    node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (searchRecursive(root, key))
        cout << "Found using recursive search\n";
    else
        cout << "Not found using recursive search\n";

    if (searchNonRecursive(root, key))
        cout << "Found using non-recursive search\n";
    else
        cout << "Not found using non-recursive search\n";

    node *minNode = minimum(root);
    node *maxNode = maximum(root);

    cout << "Minimum element: " << minNode->data << endl;
    cout << "Maximum element: " << maxNode->data << endl;

    node *s = successor(root, key);
    if (s != NULL)
        cout << "In-order successor: " << s->data << endl;
    else
        cout << "No in-order successor\n";

    node *p = predecessor(root, key);
    if (p != NULL)
        cout << "In-order predecessor: " << p->data << endl;
    else
        cout << "No in-order predecessor\n";

    return 0;
}