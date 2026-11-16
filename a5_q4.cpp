/*
Write a program to reverse a linked list.
Input: 1->2->3->4->NULL
Output: 4->3->2->1->NULL
*/
#include <iostream>
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
    node *t = new node;
    t->data = n;
    t->link = NULL;
    if(head == NULL)
        head = t;
    else
    {
        node *temp = head;
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = t;
    }
}
void reverse()
{
    node *prev = NULL;
    node *temp = head;
    node *next = NULL;
    while(temp != NULL)
    {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}
void traverse()
{
    node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->link;
    }
    cout << "NULL";
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    cout << "Original List: ";
    traverse();
    reverse();
    cout << "\nReversed List: ";
    traverse();
    return 0;
}