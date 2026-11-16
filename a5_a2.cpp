/*
Write a program to count the number of occurrences of a given key in a singly linked list and then delete all the occurrences.
Input: Linked List: 1->2->1-2->1->3->1, key: 1
Output: Count: 4, Updated Linked List: 2->2->3.
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
void insert(int n)
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
void count_delete(int key)
{
    int c = 0;
    while(head != NULL && head->data == key)
    {
        node *temp = head;
        head = head->link;
        delete temp;
        c++;
    }
    node *temp = head;
    while(temp != NULL && temp->link != NULL)
    {
        if(temp->link->data == key)
        {
            node *t = temp->link;
            temp->link = t->link;
            delete t;
            c++;
        }
        else
        {
            temp = temp->link;
        }
    }

    cout<<"Count: "<<c<<endl;
}
void display()
{
    if(head == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->link;
        }
    }
}
int main()
{
    int n, x, key;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter linked list elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        insert(x);
    }
    cout<<"Enter key: ";
    cin>>key;
    count_delete(key);
    cout<<"Updated Linked List: ";
    display();
    return 0;
}
