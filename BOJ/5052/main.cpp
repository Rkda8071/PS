#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A{
    char c[11];
    ll d;
    bool operator<(const A &r){
        return d<r.d;
    }
}a[10010];
//char a[10010][11];
//ll d[10010];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%s",&a[i].c);
        for(int i=0;i<n;i++){
            a[i].d = 0;
            for(int j=0;j<10;j++){
                if(a[i].c[j] == NULL){
                    for(int l=j;l<10;l++) a[i].d *= 10;
                    break;
                }
                a[i].d = a[i].d*10 + a[i].c[j] - '0';
            }
        }
        sort(a,a+n);
        bool ang = true;
        for(int i=0;i<n-1;i++){
            bool chk = true;
            for(int j=0;a[i].c[j]!=NULL;j++){
                if(a[i].c[j]!=a[i+1].c[j]) {
                    chk = false;
                    break;
                }
            }
            if(chk){
                ang = false;
                break;
            }
        }
        if(ang) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
