#include<iostream>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    priority_queue<int> q;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        if(a==0)
        {
            if(q.empty())
                cout<<"0\n";
            else
            {
                cout<<q.top()<<'\n';
                q.pop();
            }
            
        }
        else
        {
            q.push(a);
        }
        
    }
}