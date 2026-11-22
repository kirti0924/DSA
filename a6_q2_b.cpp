#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *prev;
    node *next;
};

node *head = NULL;

void insert_beg(int x) {
    node *t = new node;
    t->data = x;
    t->prev = NULL;
    t->next = head;

    if (head != NULL)
        head->prev = t;

    head = t;
}

void insert_end(int x) {
    node *t = new node;
    t->data = x;
    t->next = NULL;

    if (head == NULL) {
        t->prev = NULL;
        head = t;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = t;
    t->prev = temp;
}

void insert_after(int key, int x) {
    node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    node *t = new node;
    t->data = x;
    t->prev = temp;
    t->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = t;

    temp->next = t;
}

void insert_before(int key, int x) {
    node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (temp == head) {
        insert_beg(x);
        return;
    }

    node *t = new node;
    t->data = x;
    t->prev = temp->prev;
    t->next = temp;

    temp->prev->next = t;
    temp->prev = t;
}

void delete_node(int key) {
    node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (temp == head)
        head = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Deleted\n";
}

void search(int key) {
    node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;
    }

    cout << "Not found\n";
}

void display() {
    node *temp = head;

    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int choice, x, key;

    do {
        cout << "\n1. Insert at beginning";
        cout << "\n2. Insert at end";
        cout << "\n3. Insert after a node";
        cout << "\n4. Insert before a node";
        cout << "\n5. Delete a node";
        cout << "\n6. Search";
        cout << "\n7. Display";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            insert_beg(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            insert_end(x);
            break;

        case 3:
            cout << "Enter existing value and new value: ";
            cin >> key >> x;
            insert_after(key, x);
            break;

        case 4:
            cout << "Enter existing value and new value: ";
            cin >> key >> x;
            insert_before(key, x);
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> key;
            delete_node(key);
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> key;
            search(key);
            break;

        case 7:
            display();
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