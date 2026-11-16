/*
Write a program to find the middle of a linked list.
Input: 1->2->3->4->5
Output: 3
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
    {
        head = t;
    }
    else
    {
        node *temp = head;
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = t;
    }
}
void middle()
{
    node *slow = head;
    node *fast = head;
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }
    while(fast != NULL && fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;
    }
    cout << "Middle element: " << slow->data;
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    middle();
    return 0;
}