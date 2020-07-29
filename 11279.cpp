#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int h[100001];
int idx=0;
void push(int a)
{
    h[++idx]=a;
    for(int i=idx;i>1;i/=2)
    {
        if(h[i/2]<h[i]){
            swap(h[i],h[i/2]);
        }
        else
        {
            break;
        }
    }
}
bool isempty()
{
    if(idx==0)
        return true;
    return false;
}
int pop()
{
    int retval=h[1];
    h[1]=h[idx];
    h[idx--]=0;
    for(int i=1;i*2<=idx;)
    {
        if(h[i]>h[i*2]&&h[i]>h[i*2+1])
            break;
        else 
            {
                if(h[i*2]>h[i*2+1])
                {
                    swap(h[i],h[i*2]);
                    i=i*2;
                }
                else{
                    swap(h[i],h[i*2+1]);
                    i=i*2+1;
                }   
            }
    }
    return retval;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(h,-1,sizeof(h));
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x==0)
        {
            if(idx==0)
                cout<<"0"<<'\n';
            else
                cout<<pop()<<'\n';
        }
        else
        {
            push(x);
        }
    }
}
