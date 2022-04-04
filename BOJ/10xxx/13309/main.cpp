#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
int p[200010],r[200010],d[200010],cnt[200010];
//  부모 노드, 루트 노드, 노드의 색깔, 해당 색깔 노드의 개수
int main(){
    scanf("%d %d",&n,&q);
    for(int i=2;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) d[i] = 1;
    r[1] = 1; cnt[1] = n;

    for(int i=1;i<=q;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(z){
            if(d[x]!=d[y]){
                swap(x,y);
                printf("NO\n");
            }else printf("YES\n");
            if(p[x]){
                p[x] = 0;
                r[++cnt] = x;
            }
        }
    }
    return 0;
}
