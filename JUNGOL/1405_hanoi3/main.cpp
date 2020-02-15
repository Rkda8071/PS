#include<bits/stdc++.h>
using namespace std;
int n,d[30],opt[30];
void hanoi3(int x,int from,int by,int to,int ang){
    if(x==1) {printf("%d : %c->%c\n",x+ang,'A'+from,'A'+to); return;}
    hanoi3(x-1,from,to,by,ang);
    printf("%d : %c->%c\n",x+ang,'A'+from,'A'+to);
    hanoi3(x-1,by,from,to,ang);
}
void hanoi4(int x,int from,int by1,int by2,int to){
    if(x==0) return;
    hanoi4(opt[x],from,by2,to,by1);
    hanoi3(x-opt[x],from,by2,to,opt[x]);
    hanoi4(opt[x],by1,from,by2,to);
}
int main(){
    scanf("%d",&n);
    d[1] = 1;// d[2] = 3; d[3] = 5;
    for(int i=2;i<=n;i++) d[i] = 2000000000;
    for(int i=2;i<=n;i++){
        opt[i] = 0;
        for(int j=1;j<=i-1;j++){
            if(d[j]*2 + (1<<(i-j)) - 1 < d[i]){
                opt[i] = j;
                d[i] = d[j]*2 + (1<<(i-j)) - 1;
            }
            // 기둥 a에서 j개를 4기둥을 이용해서 b로      d[j]
            // 기둥 a에서 n-j개를 3기둥을 이용해서 d로    1<<(i-j)-1
            // 기둥 b에서 j개를 4기둥을 이용해서 d로      d[j]
        }
    }
    printf("%d\n",d[n]);
    hanoi4(n,0,1,2,3);
    return 0;
}
