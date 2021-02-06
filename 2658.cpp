#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int d[10][10];
pair<int,int> getPoint(int idx){
    int r = idx/10;
    int c = idx%10;
    return {r,c};
}
bool verify(pair<int,int> edge[],int cnt){
    vector<pair<int,int>> v;
    int c=0;
    for(int i=0;i<3;i++){
        v.push_back(edge[i]);
    }
    sort(v.begin(),v.end());
    if(v[0].first==v[1].first&&v[0].second==v[2].second){
        int line = v[2].first-v[0].first;
        for(int i=v[0].first;i<=v[2].first;i++){
            for(int j=v[0].second;j<=v[1].second;j++){
                if(abs(i-v[0].first)+abs(j-v[0].second)<=line){
                    if(d[i][j]==1)
                        c++;
                    else{
                        return false;
                    }
                }
            }
        }
        if(c==cnt)return true;
        return false;
    }

    if(v[0].second==v[2].second&&v[1].first==v[2].first){
        int line = v[2].first-v[0].first;
        for(int i=v[0].first;i<=v[2].first;i++){
            for(int j=v[1].second;j<=v[2].second;j++){
                if(abs(v[2].first-i)+abs(v[2].second-j)<=line){
                    if(d[i][j]==1)
                        c++;
                    else{
                        return false;
                    }
                }
            }
        }
        if(c==cnt)return true;
        return false;
    }

    if(v[0].second==v[1].second&&v[1].first==v[2].first){
        int line = v[1].first-v[0].first;
        for(int i=v[0].first;i<=v[1].first;i++){
            for(int j=v[0].second;j<=v[2].second;j++){
                if(abs(i-v[1].first)+abs(j-v[1].second)<=line){
                    if(d[i][j]==1)
                        c++;
                    else{
                        return false;
                    }
                }
            }
        }
        if(c==cnt)return true;
        return false;
    }

    if(v[0].first==v[1].first&&v[1].second==v[2].second){
        int line = v[2].first-v[1].first;
        for(int i=v[0].first;i<=v[2].first;i++){
            for(int j=v[0].second;j<=v[1].second;j++){
                if(abs(i-v[1].first)+abs(j-v[1].second)<=line){
                    if(d[i][j]==1)
                        c++;
                    else{
                        return false;
                    }
                }
            }
        }
        if(c==cnt)return true;
        return false;
    }

    if(v[0].second==v[2].second&&(v[0].first+v[2].first)/2==v[1].first){
        int axt = abs(v[1].second-v[0].second)+1;
        int half = (cnt+axt)/2;
        pair<int,int> e[3];
        pair<int,int> mid = {(v[0].first+v[2].first)/2,v[0].second};
        e[0]=v[0];
        e[1]=mid;
        e[2]=v[1];
        if(!verify( e,half)){
            return false;
        }
        e[0]=v[2];
        if(!verify(e,half)){
            return false;
        }
        return true;
    }

    if(v[0].first==v[1].first&&(v[0].second+v[1].second)/2==v[2].second){
        int axt=v[2].first-v[0].first+1;
        int half = (cnt+axt)/2;
        pair<int,int> e[3];
        pair<int,int> mid = {v[0].first,(v[0].second+v[1].second)/2};
        e[0]=v[0];
        e[1]=mid;
        e[2]=v[2];
        if(!verify( e,half)){
            return false;
        }
        e[0]=v[1];
        if(!verify(e,half)){
            return false;
        }
        return true;
    }
    
    if(v[1].first==v[2].first&&(v[1].second+v[2].second)/2==v[0].second){
        int axt = v[1].first-v[0].first+1;
        int half = (cnt+axt)/2;
        pair<int,int> e[3];
        pair<int,int> mid = {v[1].first,(v[1].second+v[2].second)/2};
        e[0]=v[0];
        e[1]=mid;
        e[2]=v[2];
        if(!verify( e,half)){
            return false;
        }
        e[2]=v[1];
        if(!verify(e,half)){
            return false;
        }
        return true;
    }
    return false;
}
bool isRegtangle(pair<int,int> edge[]){
    if(edge[0].first==edge[1].first&&edge[1].first==edge[2].first)return false;
    if(edge[0].second==edge[1].second&&edge[1].second==edge[2].second)return false;
    bool flag=false;
    for(int i=0;i<3;i++){
        int next = (i+1)%3;
        if(edge[i].first == edge[next].first)flag=true;
        if(edge[i].second == edge[next].second)flag=true;
    }
    if(!flag)return false;
    vector<int> a;
    for(int i=0;i<3;i++){
        int next = (i+1)%3;
        a.push_back(abs(edge[i].first-edge[next].first)+abs(edge[i].second-edge[next].second));
    }
    sort(a.begin(),a.end());
    if(a[0]==a[1]&&a[1]==a[2])return true;
    if(a[0]==a[1]&&(a[2]==a[0]+a[1])) return true;
    return false;
}
int main(){
    string s;
    int cnt=0;
    for(int i=0;i<10;i++){
        cin>>s;
        for(int j=0;j<10;j++){
            d[i][j]=s[j]-'0';
            if(d[i][j]==1)cnt++;
        }
    }
    vector<pair<int,int>> ext;
    ext.push_back({4,3});
    ext.push_back({4,2});
    ext.push_back({3,3});
    sort(ext.begin(),ext.end());
    pair<int,int> edge[3];
    vector<pair<int,int>> ans;
    bool flag=false;
    for(int i=0;i<100;i++){
        edge[0]=getPoint(i);
        for(int j=i+1;j<100;j++){
            edge[1]=getPoint(j);
            for(int k=j+1;k<100;k++){
                edge[2]=getPoint(k);
                if(isRegtangle(edge)){
                    flag = verify(edge,cnt);
                }
                if(flag)break;
            }
            if(flag)break;
        }
        if(flag)break;
    }
    if(flag){
        for(int i=0;i<3;i++){
            ans.push_back(edge[i]);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<3;i++){
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
        }
    }else{
        cout<<"0";
    }
}