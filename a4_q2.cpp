/*Develop a menu driven program demonstrating the following operations on 
Circular Queues: enqueue, dequeue), isEmpty, isFullO, displayO, and peekO.*/

#include<iostream>
using namespace std;
#define size 6
int q[size];
int front = -1;
int rear = -1;
void enqueue(int n)
{
    if((rear+1)%size == front)
    {
        cout<<"Queue is full"<<endl;
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear] = n;
    }
    else
    {
        rear = (rear+1)%size;
        q[rear] = n;
    }
}
void dequeue()
{
    if(front == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front+1)%size;
    }
}
void isEmpty()
{
    if(front == -1)
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue is not empty"<<endl;
}
void isFull()
{
    if((rear+1)%size == front)
        cout<<"Queue is full"<<endl;
    else
        cout<<"Queue is not full"<<endl;
}
void display()
{
    if(front == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        int i = front;
        while(true)
        {
            cout<<q[i]<<" ";
            if(i == rear)
                break;
            i = (i+1)%size;
        }
        cout<<endl;
    }
}
void peek()
{
    if(front == -1)
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Front element: "<<q[front]<<endl;
}
int main()
{
    int ch, n;
    do
    {
        cout<<"\n1. Enqueue";
        cout<<"\n2. Dequeue";
        cout<<"\n3. isEmpty";
        cout<<"\n4. isFull";
        cout<<"\n5. Display";
        cout<<"\n6. Peek";
        cout<<"\n7. Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter element to enqueue: ";
                cin>>n;
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout<<"Exiting...";
                break;
            default:
                cout<<"Invalid choice";
        }
    }while(ch != 7);
    return 0;
}
