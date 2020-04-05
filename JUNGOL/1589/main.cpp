#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
char a[11][11];
tp d[10];
int max_y,max_x,min_y=11,min_x=11;
int chk = 0,cnt;
void f(){
    sort(d+1,d+4);
    for(int i=1;i<=3;i++) printf("%d %d\n",get<0>(d[i]),get<1>(d[i]));
}
int main(){
    for(int i=1;i<=10;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(a[i][j]=='1'){
                max_y = max(max_y,i); min_y = min(min_y,i);
                max_x = max(max_x,j); min_x = min(min_x,j);
            }
        }
    }
    //printf("%d %d %d %d",max_y,min_y,max_x,min_x);

    if(a[max_y][min_x] == '1') {chk |= (1<<0); d[++cnt] = tp(max_y,min_x);}
    if(a[max_y][max_x] == '1') {chk |= (1<<1); d[++cnt] = tp(max_y,max_x);}
    if(a[min_y][min_x] == '1') {chk |= (1<<2); d[++cnt] = tp(min_y,min_x);}
    if(a[min_y][max_x] == '1') {chk |= (1<<3); d[++cnt] = tp(min_y,max_x);}
    int y,x;
    if(cnt == 3){
        if(max_y - min_y == max_x - min_x) f();
        else printf("0");
    } else if(cnt==2){
        if(chk == 3 && a[min_y][(min_x+max_x)/2] == '1'){ // 0011
            y = min_y; x = (min_x+max_x)/2;
            for(int i=y;i<=max_y;i++){
                for(int j=0;j<=i-y;j++){
                    if()
                }
            }
            d[++cnt] = tp(min_y,(min_x+max_x)/2);
            f();
        } else if(chk == 5 && a[(max_y+min_y)/2][max_x] == '1'){ //0101
            d[++cnt] = tp((max_y+min_y)/2,max_x);
            f();
        } else if(chk == 10 && a[(max_y+min_y)/2][min_x] == '1'){ //1010
            d[++cnt] = tp((max_y+min_y)/2,min_x);
            f();
        } else if(chk == 12 && a[max_y][(min_x+max_x)/2] == '1'){  //1100
            d[++cnt] = tp(max_y,(min_x+max_x)/2);
            f();
        } else printf("0");
    } else printf("0");
    return 0;
}
