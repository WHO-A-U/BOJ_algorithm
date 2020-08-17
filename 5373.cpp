#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char d[13][13];
void init(){
    pair<int,int> point[] = {{1,4},{4,1},{4,4},{4,7},{7,4},{10,4}};
    char color[]={'o','g','w','b','r','y'};
    for(int k=0;k<6;k++){
        int cr = point[k].first;
        int cc = point[k].second;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int nr = cr+i;
                int nc = cc+j;
                d[nr][nc]=color[k];
            }
        }
    }
}
void spinUp(){
    char tmp[13][13];
    for(int i=1;i<=12;i++){
        for(int j=1;j<=9;j++){
            tmp[i][j]=d[i][j];
        }
    } 
    for(int i=0;i<=1;i++){
        for(int j=0;j<=2;j++){
            d[3+i][4+j]=tmp[6-j][3+i];
            d[6+i][4+j]=tmp[6-j][6+i];
            d[4+j][i+3]=tmp[7-i][4+j];
            d[4+j][6+i]=tmp[4-i][4+j];
        }
    }
}
void spinDown(){
    char tmp[13][13];
    for(int i=1;i<=12;i++)
        for(int j=1;j<=9;j++)
            tmp[i][j]=d[i][j];
    for(int i=0;i<3;i++){
        d[9][4+i]=tmp[4+i][1];
        d[4+i][1]=tmp[1][6-i];
        d[1][4+i]=tmp[4+i][9];
        d[4+i][9]=tmp[9][6-i];
        d[10][4+i]=tmp[12-i][4];
        d[10+i][4]=tmp[12][4+i];
        d[12][4+i]=tmp[12-i][6];
        d[10+i][6]=tmp[10][4+i];
    }
}
void spinFront(){
char tmp[13][13];
    for(int k=0;k<3;k++){
        for(int i=1;i<=12;i++){
            for(int j=1;j<=9;j++){
                tmp[i][j]=d[i][j];
            }
        }
        for(int i=0;i<8;i++){
            d[6][2+i]=tmp[6][1+i];
        }
        d[10][6]=tmp[6][9];
        for(int i=0;i<2;i++){
            d[10][5-i]=tmp[10][6-i];
        }
        d[6][1]=tmp[10][4];
    }
    for(int k=0;k<3;k++){
        d[7][4+k]=tmp[9-k][4];
        d[7+k][4]=tmp[9][4+k];
        d[9][k+4]=tmp[9-k][6];
        d[9-k][6]=tmp[7][6-k];
    }
}
void spinBack(){
char tmp[13][13];
    for(int k=0;k<3;k++){
        for(int i=1;i<=12;i++){
            for(int j=1;j<=9;j++){
                tmp[i][j]=d[i][j];
            }
        }
        for(int i=0;i<8;i++){
            d[4][1+i]=tmp[4][i+2];
        }
        d[4][9]=tmp[12][6];
        for(int i=0;i<2;i++){
            d[12][6-i]=tmp[12][5-i];
        }
        d[12][4]=tmp[4][1];
    }
    for(int k=0;k<3;k++){
        d[3][4+k]=tmp[3-k][6];
        d[3-k][6]=tmp[1][6-k];
        d[1][6-k]=tmp[1+k][4];
        d[1+k][4]=tmp[3][4+k];
    }
}
void spinRight(){
    char tmp[13][13];
    for(int k=0;k<3;k++){
        for(int i=1;i<=12;i++){
            for(int j=1;j<=9;j++){
                tmp[i][j]=d[i][j];
            }
        }
        for(int i=0;i<11;i++)
            d[i+1][6]=tmp[i+2][6];
        d[12][6]=tmp[1][6];
    }
    for(int i=0;i<3;i++){
        d[4+i][7]=tmp[6][7+i];
        d[6][7+i]=tmp[6-i][9];
        d[6-i][9]=tmp[4][9-i];
        d[4][9-i]=tmp[4+i][7];
    }
}
void spinLeft(){
    char tmp[13][13];
    for(int k=0;k<3;k++){
        for(int i=1;i<=12;i++){
            for(int j=1;j<=9;j++){
                tmp[i][j]=d[i][j];
            }
        }
        for(int i=0;i<11;i++)
            d[i+2][4]=tmp[i+1][4];
        d[1][4]=tmp[12][4];
    }
    for(int i=0;i<3;i++){
        d[4+i][3]=tmp[4][i+1];
        d[4][i+1]=tmp[6-i][1];
        d[4+i][1]=tmp[6][1+i];
        d[6][i+1]=tmp[6-i][3];
    }
}
void rotate(char dir,char clock){
    int cnt = (clock=='+'?1:3);
    if(dir=='U')while(cnt--)spinUp();
    if(dir=='D')while(cnt--)spinDown();
    if(dir=='F')while(cnt--)spinFront();
    if(dir=='B')while(cnt--)spinBack();
    if(dir=='R')while(cnt--)spinRight();
    if(dir=='L')while(cnt--)spinLeft();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        init();
        cin>>k;
        while(k--){
            cin>>str;
            rotate(str[0],str[1]);
        }
        for(int i=4;i<=6;i++){
            for(int j=4;j<=6;j++)
                cout<<d[i][j];
            cout<<'\n';
        }
    }
}