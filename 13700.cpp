#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
입력
첫째 줄에 N, S, D, F, B, K가 주어지고,
 K > 0인 경우에는 둘째 줄에 경찰서의 위치 l1, l2, …, lK가 주어진다. 
 (1 ≤ S, D, k ≤ N ≤ 100000, 0 ≤ F, B ≤ 100000, 0 ≤ K ≤ N/2, S ≠ D ≠ l) 

출력
첫째 줄에 대도 X가 건물 S에서 자신의 집 D로 무사히 가기 위해
 지언이가 버튼을 눌러야 하는 최소 횟수를 출력한다
 . 만약, D에 도달할 수 없는 데이터인 경우 “BUG FOUND”를 출력한다.
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