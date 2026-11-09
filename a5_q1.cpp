/*
Develop a menu driven program for the following operations on a Singly Linked List.
(a) Insertion at the beginning.
(b) Insertion at the end.
(c) Insertion in between (before or after a node having a specific value, say 'Insert a new Node 35 before/after the Node 30).
(d) Deletion from the beginning.
(e) Deletion from the end.
(1) Deletion of a specific node, say 'Delete Node 60).
(g) Search for a node and display its position from head.
(h) Display all the node values.
*/

#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *link;
};
node *head = NULL;
void insert_beg(int n)
{
    node *t = new node();
    t->data = n;
    t->link = NULL;
    if(head == NULL)
    {
        head = t;
    }
    else
    {
        t->link = head;
        head = t;
    }
}
void insert_end(int n)
{
    node *t = new node();
    t->data = n;
    t->link = NULL;
    if(head == NULL)
    {
        head = t;
    }
    else
    {
        node *temp = head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = t;
    }
}
void insert_before()
{
    int n, x;
    cout<<"Enter value to insert: ";
    cin>>n;
    cout<<"Enter value before which you want to insert: ";
    cin>>x;
    node *t = new node();
    t->data = n;
    t->link = NULL;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
        delete t;
        return;
    }
    if(head->data == x)
    {
        t->link = head;
        head = t;
    }
    else
    {
        node *temp = head;
        while(temp->link != NULL && temp->link->data != x)
        {
            temp = temp->link;
        }
        if(temp->link == NULL)
        {
            cout<<"Node not found"<<endl;
            delete t;
        }
        else
        {
            t->link = temp->link;
            temp->link = t;
        }
    }
}
void insert_after()
{
    int n, x;
    cout<<"Enter value to insert: ";
    cin>>n;
    cout<<"Enter value after which you want to insert: ";
    cin>>x;
    node *temp = head;
    while(temp != NULL && temp->data != x)
    {
        temp = temp->link;
    }
    if(temp == NULL)
    {
        cout<<"Node not found"<<endl;
    }
    else
    {
        node *t = new node();
        t->data = n;
        t->link = temp->link;
        temp->link = t;
    }
}
void delete_beg()
{
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        node *temp = head;
        head = head->link;
        cout<<"Deleted node: "<<temp->data<<endl;
        delete temp;
    }
}
void delete_end()
{
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(head->link == NULL)
    {
        cout<<"Deleted node: "<<head->data<<endl;
        delete head;
        head = NULL;
    }
    else
    {
        node *temp = head;
        while(temp->link->link != NULL)
        {
            temp = temp->link;
        }
        cout<<"Deleted node: "<<temp->link->data<<endl;
        delete temp->link;
        temp->link = NULL;
    }
}
void delete_specific()
{
    int n;
    cout<<"Enter value to delete: ";
    cin>>n;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(head->data == n)
    {
        node *temp = head;
        head = head->link;
        delete temp;
    }
    else
    {
        node *temp = head;
        while(temp->link != NULL && temp->link->data != n)
        {
            temp = temp->link;
        }
        if(temp->link == NULL)
        {
            cout<<"Node not found"<<endl;
        }
        else
        {
            node *t = temp->link;
            temp->link = t->link;
            delete t;
        }
    }
}
void search()
{
    int n, pos = 1;
    cout<<"Enter value to search: ";
    cin>>n;
    node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == n)
        {
            cout<<"Node found at position "<<pos<<endl;
            return;
        }
        temp = temp->link;
        pos++;
    }
    cout<<"Node not found"<<endl;
}
void display()
{
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->link;
        }
        cout<<endl;
    }
}
int main()
{
    int ch, n;
    do
    {
        cout<<"\n\n1. Insert at beginning";
        cout<<"\n2. Insert at end";
        cout<<"\n3. Insert before a specific node";
        cout<<"\n4. Insert after a specific node";
        cout<<"\n5. Delete from beginning";
        cout<<"\n6. Delete from end";
        cout<<"\n7. Delete a specific node";
        cout<<"\n8. Search a node";
        cout<<"\n9. Display";
        cout<<"\n10. Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter value to insert: ";
                cin>>n;
                insert_beg(n);
                break;
            case 2:
                cout<<"Enter value to insert: ";
                cin>>n;
                insert_end(n);
                break;
            case 3:
                insert_before();
                break;
            case 4:
                insert_after();
                break;
            case 5:
                delete_beg();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_specific();
                break;
            case 8:
                search();
                break;
            case 9:
                display();
                break;
            case 10:
                cout<<"Exiting...";
                break;
            default:
                cout<<"Invalid choice";
        }
    }while(ch != 10);
    return 0;
}
