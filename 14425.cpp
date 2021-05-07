// #include <bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define MAX_CHAR 28
using namespace std;

struct Trie{
    Trie* go[MAX_CHAR];
    int end;

    Trie(): end(0){fill(go,go+MAX_CHAR,nullptr);}
    
    ~Trie(){
        for(int i=0;i<MAX_CHAR;i++){
            if(go[i]){
                delete(go[i]);
            }
        }
    }

    void insert(char * str){
        if(*str!='\0'){
            if(!go[*str-'a']){
                go[*str-'a'] = new Trie();
            }  
            go[*str-'a']->insert(str+1);
        }else{
            end++;
        }
   }

    int find(char * str){
        if(*str!='\0'){
            if(go[*str-'a']){
                return go[*str-'a']->find(str+1);
            }
            return 0;
        }else{
            return end;
        }

    }
};
int main(){
    int n,m,answer=0;
    cin>>n>>m;
    Trie* root = new Trie();
    for(int i=0;i<n;i++){
        char str[555];
        scanf("%s",&str);
        root->insert(str);
    }
    for(int i=0;i<m;i++){
        char str[555];
        scanf("%s",str);
        answer+=(root->find(str));
    }
    cout<<answer;
}

