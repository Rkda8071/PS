#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> p;
int n,m,cnt,chk[100010];
p pa[100010];
void init(int id){
    if(chk[id] != cnt){
        pa[id] = p(0LL, id);
        chk[id] = cnt;
    }
}
p fin(int x){
    if(pa[x].second == x) return pa[x];
    p tmp = fin(pa[x].second);
    return pa[x] = p(tmp.first + pa[x].first, tmp.second);
}
int main(){
    scanf("%d %d",&n,&m);
    while(n+m){
        cnt++;
        while(m--){
            char q;
            int x,y;
            scanf(" %c %d %d",&q,&x,&y);
            init(x); init(y);
            if(q == '!'){
                ll z;
                scanf("%lld",&z);
                p px = fin(x), py = fin(y);
                if(px.second == py.second) continue;
                pa[px.second] = p(z - pa[x].first + pa[y].first,py.second);
            }
            else{
                //y가 x보다 얼마나 무겁나
                p px = fin(x), py = fin(y);
                if(px.second != py.second)
                    printf("UNKNOWN\n");
                else{
                    printf("%lld\n",pa[x].first-pa[y].first);
                }
            }
        }

        scanf("%d %d",&n,&m);
    }
}