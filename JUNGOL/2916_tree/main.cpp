// BOJ 10838 트리
#include<bits/stdc++.h>
using namespace std;

int root[100100],v[100100];
int c1,c2;
int n;
int chk[100100] = {0};
int chknum;

int lca(int x,int y){
    chk[x] = ++chknum;
    if(x==y) return x;
    for(int i=0;i<1000 && x;i++){
        x = root[x];
        chk[x] = chknum;
    }
    while(chk[y]!=chknum){
        y = root[y];
    }
    return y;
}

void paint(int x,int y,int z){
    int k = lca(x,y);
    while(x!=k){
        v[x] = z;
        x = root[x];
    }
    while(y!=k){
        v[y] = z;
        y = root[y];
    }
}
int cnt(int x,int y){
    int k = lca(x,y);
    set<int> m;
    while(x!=k){
        m.insert(v[x]);
        x = root[x];
    }
    while(y!=k){
        m.insert(v[y]);
        y = root[y];
    }
    return m.size();
}
int main(){
    //freopen("input.txt","r",stdin);
    int a,x,y,z,k;
    scanf("%d %d",&n,&k);
    while(k--){
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            scanf("%d %d %d",&x,&y,&z); //x~y 까지 z로 paint
            paint(x,y,z);
            break;

        case 2:
            scanf("%d %d",&x,&y); // x를 y의 자식 노드로 move
            root[x] = y;
            break;
        case 3:
            scanf("%d %d",&x,&y); // x와 y에서 서로 다른 값들의 개수 count
            printf("%d\n",cnt(x,y));
            break;
        }

    }
}
