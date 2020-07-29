#include<iostream>
using namespace std;
long long go(int a,int b,int c)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%c;
    if(b%2==0)
    {
        long long tmp=go(a, (b/2),c) % c;
        return (tmp*tmp)%c;
    }
    else
    {
        return (a*go(a,b-1,c))%c;
    }
    
}
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<go(a,b,c);
}