/* Write a program interleave the first half of the queue with second half
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9 */

#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    queue<int> temp;
    int n, x;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter queue elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        q.push(x);
    }
    for(int i=0; i<n/2; i++)
    {
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty())
    {
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();
    }
    cout<<"Interleaved queue: ";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
