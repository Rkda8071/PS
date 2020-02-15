#include<bits/stdc++.h>
using namespace std;
struct A{
    int a[4];
}ang;
char b[5][10];
int a[5][10],chk[5];
int xxx[3][4] = {{1,2,3,4},{1,5,3,6},{2,5,4,6}};
bitset<4> bit[4];
vector<A> dap;
void f(int x){
    if(x==4){
        for(int i=dap.size()-1;i>=0;i--){
            for(int j=0;j<4;j++){
                if(dap[i].a[j] == ang.a[0]){
                    x = j;
                    break;
                }
            }
            for(int j=1;j<4;j++){
                if(ang.a[j] != dap[i].a[(j+x)%4]){
                    x = -1;
                    break;
                }
            }
            if(x!=-1) return;
        }
        dap.push_back(ang);
        return;
    }
    for(int i=1;i<=4;i++){
        if(!chk[i]){
            chk[i] = 1;
            for(int j=0;j<4;j++){ // xxx
                for(int l=0;l<3;l++){ // l번 밀기 나다라가 다라가나
                    bool cc = true;
                    for(int k=0;k<4;k++){ // 확인
                        if(bit[k].test(a[i][xxx[j][(k+l)%4]])){
                            cc = false;
                            break;
                        }
                    }
                    if(cc){
                        for(int k=0;k<4;k++) {
                            bit[k].set(a[i][xxx[j][(k+l)%4]],true);
                            ang.a[k] = (ang.a[k]<<2) + a[i][xxx[j][(k+l)%4]];
                        }

                        f(x+1);
                        for(int k=0;k<4;k++) {
                            bit[k].set(a[i][xxx[j][(k+l)%4]],false);
                            ang.a[k] = (ang.a[k]>>2);
                        }
                    }
                }
            }
            chk[i] = 0;
        }
    }

}
int main(){
    for(int i=1;i<=4;i++) scanf("%s",b[i]+1);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=6;j++){
            switch(b[i][j]){
            case 'R':
                a[i][j] = 0;
                break;
            case 'G':
                a[i][j] = 1;
                break;
            case 'B':
                a[i][j] = 2;
                break;
            case 'Y':
                a[i][j] = 3;
                break;
            }
        }
    }
    f(0);
    printf("%d",dap.size());
    return 0;
}
