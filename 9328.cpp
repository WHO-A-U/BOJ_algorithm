#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
map<char , vpii> m;
map<char,int> key;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vvc map;
    int t,h,w,ans;

    cin>>t;
    while(t--){
        ans=0;
        m.clear();
        map.clear();
        key.clear();
        cin>>h>>w;
        string s;
        vc tmp(w+2,'.');
        map.push_back(tmp);
        for(int i=0;i<h;i++){
            cin>>s;
            s = "."+s+".";
            vc t(s.begin(),s.end());
            map.push_back(t);
        }
        map.push_back(tmp);

        h+=2;
        w+=2;
        
        cin>>s;
        if(s!="0"){
            for(char x : s){
                key[x]++;
            }
        }

        vvb visit(h,vb(w,false));
        
        visit[0][0]=true;
        queue<pii> q;
        q.push({0,0});

        while(!q.empty()){
            auto [cr,cc] = q.front();
            q.pop();


            for(int i=0;i<4;i++){
                int nr = cr+dx[i];
                int nc = cc+dy[i];
                if(nr>=0&&nr<h&&nc>=0&&nc<w){
                    if(!visit[nr][nc]){
                        if(map[nr][nc]=='.'){
                            q.push({nr,nc});
                            visit[nr][nc]=true;
                        }
                        else if(map[nr][nc]>='a'&&map[nr][nc]<='z'){
                            if(key.find(map[nr][nc])==key.end()){
                                if(m.find(map[nr][nc]+('A'-'a'))!=m.end()){
                                    for(auto p : m[map[nr][nc]+('A'-'a')]){
                                        q.push(p);
                                    }
                                    m.erase(map[nr][nc]);
                                }
                                key[map[nr][nc]]++;
                            }
                            q.push({nr,nc});
                            visit[nr][nc]=true;
                        }else if(map[nr][nc]>='A'&&map[nr][nc]<='Z'){
                            char needKey = map[nr][nc]-('A'-'a');
                            if(key.find(needKey)!=key.end()){
                                q.push({nr,nc});
                                visit[nr][nc]=true;
                            }else{
                                if(m.find(map[nr][nc])!=m.end()){
                                    m[map[nr][nc]].push_back({nr,nc});
                                }else{
                                    vpii tmp;
                                    tmp.push_back({nr,nc});
                                    m[map[nr][nc]]=tmp;
                                }
                            }
                        }
                        else if (map[nr][nc]=='$'){
                            ans++;
                            q.push({nr,nc});
                            visit[nr][nc]=true;
                        }

                    }
                }
            }
        }

        cout<<ans<<"\n";
    }
}