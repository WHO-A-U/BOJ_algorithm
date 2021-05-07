#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[100001][90];
struct Trie{
    int end;
    int branch;
    Trie * go[26];

    Trie():end(0),branch(0){fill(go,go+26,nullptr);}

    ~Trie(){
        for(int i=0;i<26;i++)
            if(go[i])
                delete(go[i]);
        }

    void insert(char *s){
        if(*s!='\0'){
            if(!go[*s-'a']){
                go[*s-'a'] = new Trie();
                branch++;
            }
            go[*s-'a']->insert(s+1);
        }else{
            end++;
        }
    }

    int find(char *s,bool isBegin){
        if(*s!='\0'){
            int tmp=0;
            if(branch!=1||end!=0||isBegin){
                tmp++;
            }
            return tmp+go[*s-'a']->find(s+1,false);
        }
        return 0;
    }
};
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        memset(str,0,sizeof(str));
        Trie * root = new Trie();
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            root->insert(str[i]);
        }
        int answer=0;
        for(int i=0;i<n;i++){
            int tmp =root->find(str[i],true);
            answer+=tmp;
        }
        

        printf("%0.2f\n",(double)answer/n);
        delete(root);
    }
}
