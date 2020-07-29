#include<functional>
#include<algorithm>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>>q;
    while(n--)
    {
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