#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *prev;
    node *next;
};

int main() {
    node *head = NULL;
    node *tail = NULL;

    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter data: ";
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

    int count = 0;
    node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Size of Doubly Linked List = " << count;

    return 0;
}