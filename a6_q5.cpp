#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *link;
};

bool isCircular(node *head) {
    if (head == NULL)
        return false;

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->link != NULL) {
        slow = slow->link;
        fast = fast->link->link;

        if (slow == fast)
            return true;
    }

    return false;
}

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
        t->link = NULL;

        if (head == NULL) {
            head = t;
            tail = t;
        } else {
            tail->link = t;
            tail = t;
        }
    }

    if (isCircular(head))
        cout << "Linked List is Circular";
    else
        cout << "Linked List is Not Circular";

    return 0;
}