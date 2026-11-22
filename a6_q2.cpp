#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *link;
};

int main() {
    node *head = NULL;
    node *tail = NULL;

    int a[] = {20, 100, 40, 80, 60};

    for (int i = 0; i < 5; i++) {
        node *t = new node;
        t->data = a[i];
        t->link = NULL;

        if (head == NULL) {
            head = t;
            tail = t;
        } else {
            tail->link = t;
            tail = t;
        }
    }

    tail->link = head;

    node *temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->link;
    } while (temp != head);

    cout << head->data << endl;

    return 0;
}