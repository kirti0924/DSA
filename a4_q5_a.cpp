/*
Write a program to implement a stack using (a) Two queues
*/

#include<iostream>
#include<queue>
using namespace std;
queue<int> q1, q2;
void push(int n)
{
    q2.push(n);
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}
void pop()
{
    if(q1.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Deleted element: "<<q1.front()<<endl;
        q1.pop();
    }
}
void top()
{
    if(q1.empty())
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Top element: "<<q1.front()<<endl;
}
void display()
{
    if(q1.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        queue<int> temp = q1;

        while(!temp.empty())
        {
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
}
int main()
{
    int ch,n;
    do
    {
        cout<<"\n1. Push";
        cout<<"\n2. Pop";
        cout<<"\n3. Top";
        cout<<"\n4. Display";
        cout<<"\n5. Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter element: ";
                cin>>n;
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                display();
                break;
            case 5:
                cout<<"Exiting...";
                break;
            default:
                cout<<"Invalid choice";
        }
    }while(ch!=5);
    return 0;
}
