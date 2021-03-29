#include <bits/stdc++.h>
using namespace std;
struct Trie{
    Trie *next[2];
    Trie(){
        memset(next , 0 , sizeof(next));
    };
    void insert(const char * key){
        if(*key!='\0'){
            if(!next[*key-'0'])
                next[*key-'0'] = new Trie;
            next[*key-'0']->insert(key+1);
        }
    } 

    int getMax(const char * key,int j){
        if(*key=='\0'||j<0)
            return 0;
        
        int cur = *key-'0',maxVal=0;

        if(next[1-cur])
            maxVal = max(maxVal, (1<<j)+next[1-cur]->getMax(key+1,j-1)); 
        else if(next[cur])
            maxVal = max(maxVal, next[cur]->getMax(key+1,j-1)); 
        
        return maxVal;
    }
};
char c[100001][33];
char s[32];
int n,x,maxVal=0;;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    Trie *root  = new Trie;
    for(int i=0;i<n;i++){
        cin>>x;
        for(int j=31;j>=0;j--){
            if(x%2)
                s[j]='1';
            else
                s[j]='0';
            x/=2;
        }
        for(int j=0;j<32;j++){
            c[i][j]=s[j];
        }
        c[i][32]='\0';
        root->insert(c[i]);
    }
    for(int i=0;i<n;i++){
        maxVal = max(maxVal , root->getMax(c[i],31));
    }
    cout<<maxVal;
}