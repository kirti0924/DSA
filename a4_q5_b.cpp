/*
Write a program to implement a stack using (b) One Queue.
*/

#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
void push(int n)
{
    int s = q.size();
    q.push(n);
    for(int i=0; i<s; i++)
    {
        q.push(q.front());
        q.pop();
    }
}
void pop()
{
    if(q.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Deleted element: "<<q.front()<<endl;
        q.pop();
    }
}
void top()
{
    if(q.empty())
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Top element: "<<q.front()<<endl;
}
void display()
{
    if(q.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        queue<int> temp = q;

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
