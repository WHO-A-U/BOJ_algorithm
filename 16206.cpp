#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    
    int n,m,x,ans=0;
    cin>>n>>m;
    
    vector<int> d;
    vector<int> z;

    for(int i=0;i<n;i++){
        cin>>x;

        if(x%10 == 0)
            z.push_back(x);
        else
            d.push_back(x);
    }

    sort(d.begin(),d.end());
    sort(z.begin(),z.end());

    for(int cur : z){
        if( m <= 0 && cur != 10 ) //칼질 못함
            break;
        
        if( m >= (cur/10) -1 ){ //칼질 충분
            m -= ((cur/10) -1);
            ans += (cur/10);
        }
        else{ //칼질 부족
            if( (cur/10) > 1 && m>0){ //남은 칼질 사용
                ans += m;
                m = 0 ;
            }
            //기본 빵조각
            // ans+=1;
        }
    }

    for(int cur : d){
        
        while(cur/10 >= 1){
            
            if(m<=0)
                break;
            cur-=10;
            m--;
            ans++;
        }
        if(m<=0)
            break;
    }
    cout<<ans;
}