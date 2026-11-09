/*
Write a program to find first non-repeating character in a string using Queue.
Sample I/P: a a bc Sample O/P: a a-1 bb
*/

#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<char> q;
    string s;
    int freq[26] = {0};
    cout<<"Enter string: ";
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i];
        freq[ch-'a']++;
        q.push(ch);
        while(!q.empty() && freq[q.front()-'a'] > 1)
        {
            q.pop();
        }
        if(q.empty())
        {
            cout<<"-1 ";
        }
        else
        {
            cout<<q.front()<<" ";
        }
    }
    return 0;
}
