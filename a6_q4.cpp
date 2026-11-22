#include <iostream>
using namespace std;

class node {
public:
    char data;
    node *prev;
    node *next;
};

int main() {
    node *head = NULL;
    node *tail = NULL;

    int n;
    char x;

    cout << "Enter number of characters: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter character: ";
        cin >> x;

        node *t = new node;
        t->data = x;
        t->prev = tail;
        t->next = NULL;

        if (head == NULL)
            head = t;
        else
            tail->next = t;

        tail = t;
    }

    node *left = head;
    node *right = tail;

    bool palindrome = true;

    while (left != NULL && right != NULL &&
           left != right && left->prev != right) {

        if (left->data != right->data) {
            palindrome = false;
            break;
        }

        left = left->next;
        right = right->prev;
    }

    if (palindrome)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}