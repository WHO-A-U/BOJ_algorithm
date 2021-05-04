#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;
using vvpll = vector<vpll>;
using vvs = vector<vs>;
int n,x,a;
int d[21][21];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vi studentsOrder;
vvi studentsFavorite;
int maxCnt=0;
bool isValid(int r , int c){
    return r>=0&&r<n&&c>=0&&c<n;
}
int getNearCount(int r, int c,int student_num){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(isValid(nr,nc)){
            for(auto x : studentsFavorite[student_num]){
                if(d[nr][nc]==x){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
vpii getNearMostSpace(vpii & pre){
    
    vpii ret;
    int maxCnt=0;
    
    for(auto coord : pre){
        int r = coord.first;
        int c = coord.second;
        
        int cnt=0;

        for(int i=0;i<4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(isValid(nr,nc) && d[nr][nc]==-1){
                cnt++;
            }
        }
        if(maxCnt<cnt){
            ret.clear();
            maxCnt=cnt;
        }
        if(maxCnt==cnt){
            ret.push_back(coord);
        }
    }
    return ret;
}
void put_student(int student_num){
    vpii pre;
    int maxCnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]==-1){
                int cnt = getNearCount(i,j,student_num);
                if(maxCnt<cnt){
                    maxCnt=cnt;
                    pre.clear();
                }
                if(maxCnt==cnt){
                    pre.push_back({i,j});
                }
            }
        }
    }
    
    if(pre.size()>1){
        pre = getNearMostSpace(pre);
    }


    sort(all(pre));
    int tr = pre[0].first;
    int tc = pre[0].second;
    d[tr][tc]=student_num;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(d,-1,sizeof(d));

    cin>>n;

    studentsOrder.assign(n*n,0);
    studentsFavorite.assign(n*n+1,vi());

    for(int i=0;i<n*n;i++){
        cin>>x;
        studentsOrder[i]=x;
        vi student;
        for(int j=0;j<4;j++){
            cin>>a;
            student.push_back(a);
        }
        studentsFavorite[x] = student;
    }

    for(int i=0;i<n*n;i++){
        put_student(studentsOrder[i]);
    }
    
    
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt = getNearCount(i,j,d[i][j]);
            switch (cnt)
            {
                case 0: 
                    break;
                case 1: 
                    answer+=1;
                    break;
                case 2: 
                    answer+=10;
                    break;
                case 3: 
                    answer+=100;
                    break;
                case 4: 
                    answer+=1000;
                    break;
                default:
                    break;
            }            
        }
    }
    cout<<answer;
    
}