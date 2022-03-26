#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
typedef tuple<int,int,int> ttp;
int n,m,q,cnt,lev[200100];
ttp p[200100];
vector<tp> v[200100];
map<int, int> ma[200100];
void init(int id,int pc){
    for(auto i : v[id]){
        int y,c;
        tie(y,c) = i;
        if(c != pc && ma[id][c] == 0) cnt++;
        if(!lev[y]){
            lev[y] = lev[id] + 1;
            ma[id][c]++;
            ma[y][c]++;
            init(y,c);
        }
    }
}
void rep(int id,int old,int neww){
    if(--ma[id][old] == 0) cnt--;
    if(ma[id][neww]++ == 0) cnt++;
}
int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int x,y,c,i=1;i<n;i++){
        scanf("%d %d %d",&x,&y,&c);
        p[i] = ttp(x,y,c);
        v[x].push_back(tp(y,c));
        v[y].push_back(tp(x,c));
    }
    lev[1] = 1;
    init(1, 0);
    while(q--){
        int id,c,x,y,z;
        scanf("%d %d",&id,&c);
        tie(x,y,z) = p[id];
        p[id] = ttp(x,y,c);

        rep(x,z,c);
        rep(y,z,c);
        printf("%d\n",cnt);
    }
}
