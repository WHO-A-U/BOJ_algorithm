
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

ll ans[10];
void getSum(int x,int point){
    while(x>0){
        ans[x%10]+=point;
        x/=10;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int page ;
    int idx =1 , start=1;
    cin>>page;

    while (start <= page) {

        while (page % 10 != 9 && start <= page) {
            getSum(page,  idx);
            page--;
        }

        if (page < start) {
            break;
        }

        while (start % 10 != 0 && start <= page) {
            getSum(start,  idx);
            start++;
        }

        start /= 10;
        page /= 10;

        for (int i = 0; i < 10; i++) {
            ans[i] += (page - start + 1) * idx;
        }

        idx *= 10;
    }
    
        for (int i = 0; i < 10; i++) {
            cout<<ans[i]<<" ";
        }
}