#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int d[3];
int l[3];
int tl[3];
int temp[3];
int v[3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            cin>>v[j];
        for(int j=0;j<3;j++)
        {
            temp[j]=0;
            tl[j]=0x3f3f3f;
            for(int k=-1;k<=1;k++) 
                if(j+k>=0 && j+k<=2)
                {
                    tl[j]=min(tl[j],l[j+k]);
                    temp[j]=max(temp[j],d[j+k]);
                }
        }
        for(int j=0;j<3;j++)
        {
            d[j]=temp[j]+v[j];
            l[j]=tl[j]+v[j];
        }

    }
    cout<<max(d[0],max(d[1],d[2]))<<" ";
    cout<<min(l[0],min(l[1],l[2]));

}