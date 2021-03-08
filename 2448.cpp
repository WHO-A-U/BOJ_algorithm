#include<iostream>
using namespace std;
using pii = pair<int,int>;
char d[4000][10000];
void draw(pii start , int size){
    if(size==1){
        for(int i=0;i<3;i++)d[start.first+i][start.second+i]='*';
        for(int i=0;i<3;i++)d[start.first+i][start.second-i]='*';
        for(int i=0;i<5;i++)d[start.first+2][start.second-2+i]='*';
        return ;
    }
    int Aheight = size*3/2,Awidth = ((size/2)*5 + (size/2-1)+1)/2;
    draw(start,size/2);
    draw({start.first+Aheight,start.second+Awidth},size/2);
    draw({start.first+Aheight,start.second-Awidth},size/2);
    return ;
}
int main(){
    int n;
    cin>>n;
    int num = n/3, width = num*5 + (num-1),height = n;
    draw({0,width/2},num);
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<(d[i][j]=='*'?"*":" ");
        }
        cout<<"\n";
    }
}