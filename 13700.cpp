#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
�Է�
ù° �ٿ� N, S, D, F, B, K�� �־�����,
 K > 0�� ��쿡�� ��° �ٿ� �������� ��ġ l1, l2, ��, lK�� �־�����. 
 (1 �� S, D, k �� N �� 100000, 0 �� F, B �� 100000, 0 �� K �� N/2, S �� D �� l) 

���
ù° �ٿ� �뵵 X�� �ǹ� S���� �ڽ��� �� D�� ������ ���� ����
 �����̰� ��ư�� ������ �ϴ� �ּ� Ƚ���� ����Ѵ�
 . ����, D�� ������ �� ���� �������� ��� ��BUG FOUND���� ����Ѵ�.
*/
int d[100001];
bool v[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,S,D,F,B,K,x;
    cin>>N>>S>>D>>F>>B>>K;
    for(int i=0;i<K;i++)
    {
        cin>>x;
        d[x]=-1;
        v[x]=true;
    }
    queue<int> q;
    q.push(S);
    v[S]=true;
    while(!q.empty())
    {
        int p=q.front();//current position
        int fp=p+F;
        int bp=p-B;
        q.pop();
        if(fp>=1&&fp<=N&&v[fp]==false)
        {
            v[fp]=true;
            d[fp]=d[p]+1;
            q.push(fp);
        }
        if(bp>=1&&bp<=N&&v[bp]==false)
        { 
            v[bp]=true;
            d[bp]=d[p]+1;
            q.push(bp);
        }
    }
    if(d[D]<=0)
        cout<<"BUG FOUND";
    else
        cout<<d[D];
}