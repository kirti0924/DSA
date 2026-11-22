#include <iostream>
using namespace std;
class node {
public:
    int data;
    node *link;
};
node *head = NULL;
void insert_beg(int x) {
    node *t = new node;
    t->data = x;
    if (head == NULL) {
        head = t;
        t->link = head;
        return;
    }
    node *temp = head;
    while (temp->link != head)
        temp = temp->link;
    t->link = head;
    temp->link = t;
    head = t;
}
void insert_end(int x) {
    node *t = new node;
    t->data = x;
    if (head == NULL) {
        head = t;
        t->link = head;
        return;
    }
    node *temp = head;
    while (temp->link != head)
        temp = temp->link;
    temp->link = t;
    t->link = head;
}
void insert_after(int key, int x) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    node *temp = head;
    do {
        if (temp->data == key) {
            node *t = new node;
            t->data = x;
            t->link = temp->link;
            temp->link = t;
            cout << "Inserted\n";
            return;
        }
        temp = temp->link;
    } while (temp != head);
    cout << "Node not found\n";
}
void insert_before(int key, int x) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (head->data == key) {
        insert_beg(x);
        return;
    }
    node *prev = head;
    node *temp = head->link;
    while (temp != head) {
        if (temp->data == key) {
            node *t = new node;
            t->data = x;
            t->link = temp;
            prev->link = t;
            cout << "Inserted\n";
            return;
        }
        prev = temp;
        temp = temp->link;
    }
    cout << "Node not found\n";
}
void delete_node(int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    node *temp = head;
    node *prev = NULL;
    do {
        if (temp->data == key) {
            if (temp == head && temp->link == head) {
                head = NULL;
            } else {
                if (prev == NULL) {
                    node *last = head;
                    while (last->link != head)
                        last = last->link;
                    head = head->link;
                    last->link = head;
                } else {
                    prev->link = temp->link;
                }
            }
            delete temp;
            cout << "Deleted\n";
            return;
        }
        prev = temp;
        temp = temp->link;
    } while (temp != head);
    cout << "Node not found\n";
}
void search(int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    node *temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->link;
        pos++;
    } while (temp != head);
    cout << "Not found\n";
}
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->link;
    } while (temp != head);
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