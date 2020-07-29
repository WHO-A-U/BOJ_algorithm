#include<iostream>
using namespace std;
int d[101][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int row,col,x;
    cin>>row>>col;
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<=row;j++)
        {
            for(int k=1;k<=col;k++)
            {
                cin>>x;
                d[j][k]+=x;
            }
        }
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<'\n';

    }
}