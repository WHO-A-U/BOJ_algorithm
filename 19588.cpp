#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<functional>
using namespace std;
vector < pair <int,int>> person;
vector <long long> score[100001];
vector <long long> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,a,b,Q;
    long long ans;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        person.push_back({a,b});
    }
    sort(person.begin(),person.end(),greater<pair<int,int>>());

    int tmp =person[0].second;
    for(int i=1;i<M;i++){
        tmp^=person[i].second;
    }


    s.push_back(tmp);
    for(int i=1;i<=N-M;i++){
        tmp^=person[i-1].second;
        tmp^=person[i+M-1].second;
        s.push_back(tmp);
    }

    for(int i=0;i<M;i++){
        score[i].push_back(0);
    }

    for(int i=0;i<s.size();i++){
        score[i%M].push_back(s[i]);
    }
   

    for(int i=0;i<M;i++){
        for(int j=1;j<score[i].size();j++){
            score[i][j]+=score[i][j-1];
        }
    }

 
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>a>>b;
        ans=score[b%M][a+b/M]-score[b%M][b/M];
        cout<<ans<<'\n';
    }
}