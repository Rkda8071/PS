#include<bits/stdc++.h>
#define n 4
using namespace std;
using ull = unsigned long long;
using p = pair<int,int>;
using pp = pair<int,p>;

const ull target =0x0123456789ABCDEFull;
const ull vmask[5] = {0,0xF000F000F000F000
                 ,0x0F000F000F000F00
                 ,0x00F000F000F000F0
                 ,0x000F000F000F000F};
const ull hmask[5] = {0,0xFFFF000000000000
                 ,0x0000FFFF00000000
                 ,0x00000000FFFF0000
                 ,0x000000000000FFFF};

map<ull,int> m,m2;
queue<ull> q;
vector<int> dap;
ull vert(ull cur,int i,int k){
    return ((cur&vmask[i])>>k*16) | ((cur&vmask[i])<<(4-k)*16) | (cur&(~vmask[i]));
}
ull hori(ull cur,int i,int k){
    return ((((cur&hmask[i])>>k*4) | ((cur&hmask[i])<<(4-k)*4)) & hmask[i]) | (cur&(~hmask[i]));
}
int main(){
    ull s = 0,x,y,z;
    for(int i=1;i<=16;i++) {
        scanf("%lld",&x); --x;
        s = (s<<4) | x;
    }
    q.push(target); q.push(0);
    while(!q.empty()){
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        if(y>3) continue;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=3;j++){
                z = vert(x,i,j);
                if(m.find(z)==m.end()) {
                    m[z] = 8*i + 2*(4-j) + 0;
                    q.push(z); q.push(y+1);
                }
                z = hori(x,i,j);
                if(m.find(z)==m.end()) {
                    m[z] = 8*i + 2*(4-j) + 1;
                    q.push(z); q.push(y+1);
                }
            }
        }
    }

    ull inter;
    q.push(s); q.push(0);
    while(!q.empty()){
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        if(m.find(x)!=m.end()){
            inter = x;
            break;
        }
        if(y>3) continue;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=3;j++){
                z = vert(x,i,j);
                if(m2.find(z)==m2.end()) {
                    m2[z] = 8*i + 2*j + 0;
                    q.push(z); q.push(y+1);
                }
                z = hori(x,i,j);
                if(m2.find(z)==m2.end()) {
                    m2[z] = 8*i + 2*j + 1;
                    q.push(z); q.push(y+1);
                }
            }
        }
    }
    int cnt = 0;
    x = inter;
    while(x!=s){
        ++cnt;
        y = m2[x];
        if(y%2)
            x = hori(x,y/8,4-y/2%4);
        else
            x = vert(x,y/8,4-y/2%4);
        dap.push_back(y);
    }
    reverse(dap.begin(),dap.end()); x = inter;
    while(x!=target){
        ++cnt;
        y = m[x];
        if(y%2)
            x = hori(x,y/8,y/2%4);
        else
            x = vert(x,y/8,y/2%4);
        dap.push_back(y);
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%d %d %d\n",2-dap[i]%2,dap[i]/8,dap[i]/2%4);
    }
}
