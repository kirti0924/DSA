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

    node *temp = head->link;

    while (temp != NULL && temp != head) {
        temp = temp->link;
    }

    if (temp == head)
        return true;

    return false;
}

int main() {
    node *head = new node;
    node *n2 = new node;
    node *n3 = new node;
    node *n4 = new node;
    node *n5 = new node;

    head->data = 2;
    head->link = n2;

    n2->data = 4;
    n2->link = n3;

    n3->data = 6;
    n3->link = n4;

    n4->data = 7;
    n4->link = n5;

    n5->data = 5;
    n5->link = head;  // Last node points to head

    if (isCircular(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}