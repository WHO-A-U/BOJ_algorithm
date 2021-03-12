
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

vll d[10][10]; // 자릿수  , 값  
void sumArr(vll &a , vll &b){
    for(int i=0;i<a.size();i++){
        a[i]+=b[i];
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            d[i][j].assign(10,0);
        }
    }
    
    for(int i=1;i<10;i++){
        d[0][i][i]=1;
    }


    for(int i=1;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                sumArr(d[i][j],d[i-1][k]);
            }
            if(j==0){
                d[i][j][1]++;
            }
            d[i][j][0]+=(i-1)+1;
            if(j!=0){
                d[i][j][j]+=pow(10LL,i)-1;
                d[i][j][(j+1)%10]++;
            }
            if(j==9){
                d[i][j][1]++;
                // d[i][j][0]+=(i-1)+1;
            }
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<d[2][i][j]<<" ";
        }
        cout<<"\n";
    }
    
}