#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,nn,m,k;
ll seg[4000000];
void init_seg(){
    scanf("%d %d %d",&n,&m,&k);
    for(nn=1;nn<n;nn*=2);
    for(int i=0;i<n;i++)
        scanf("%lld",&seg[i+nn]);
    for(int i=n;i<=nn;i++)
        seg[i+nn] = 1LL;
    for(int i=nn-1;i>=1;i--)
        seg[i] = (seg[i*2] * seg[i*2+1]) % 1000000007LL;
}
ll fin(int lev,int x,int y,int l,int r){
    if(r<x || y<l) return 1LL;
    if(x<=l && r<=y) return seg[lev];
    return (fin(lev*2,x,y,l,(l+r)/2) * fin(lev*2+1,x,y,(l+r)/2+1, r))%1000000007LL;
}

int main(){
    init_seg();
    for(int i=0;i<m+k;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(x==1){ //y번째 수를 z로
            int lev = y+nn-1;
            seg[lev] = z;
            while(lev){
                lev/=2;
                seg[lev] = (seg[lev*2] * seg[lev*2+1]) % 1000000007LL;
            }
        }else // y~z
            printf("%lld\n",fin(1,y,z,1,nn));
    }

}
