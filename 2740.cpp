#include<iostream>
using namespace std;
int A[101][101][2];
int ans[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int row,col,x;
    cin>>row>>col;
    for(int j=1;j<=row;j++)
    {
        for(int k=1;k<=col;k++)
        {
            cin>>A[j][k][0];
        }
    }
    int nrow,ncol;
    cin>>nrow>>ncol;
    for(int j=1;j<=nrow;j++)
    {
        for(int k=1;k<=ncol;k++)
        {
            cin>>A[j][k][1];
        }
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=ncol;j++)
        {
            for(int k=1;k<=col;k++)
            {
                ans[i][j]+=(A[i][k][0]*A[k][j][1]);
            }
        }
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=ncol;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}