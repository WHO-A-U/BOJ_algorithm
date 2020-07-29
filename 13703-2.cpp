#include<iostream>
#include<cstring>
using namespace std;

const int DEPTHMAX = 63 *2 +1;
const int MAX=63+1;

int k,n;
long long cache[DEPTHMAX][MAX];

long long isAlive(int depth,int seconds){
    if(!depth) 
        return 0;
    else if(!seconds)
            return 1;
    long long &result = cache[depth][seconds];
    if(result !=-1)
        return result;
    result = isAlive(depth+1,seconds-1)+isAlive(depth-1,seconds-1);
    return result;
}

int main(){
    cin>>k>>n;
    memset(cache,-1,sizeof(cache));
    cout<<isAlive(k,n)<<endl;
    return 0;
}