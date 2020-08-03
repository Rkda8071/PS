#include<bits/stdc++.h>
using namespace std;

char a[1010],b[1010];
int d[1010][1010];

int main(){
    int n,m;
    scanf("%s",a+1);
    scanf("%s",b+1);
    for(n=1;a[n+1]!=NULL;n++);
    for(m=1;b[m+1]!=NULL;m++);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j] = max(d[i-1][j],d[i][j-1]);
            if(a[i] == b[j]) d[i][j] = max(d[i][j],d[i-1][j-1]+1);
        }
    }
    printf("%d\n",d[n][m]);
    stack<char> s;
    int y=n,x=m;
    while(y && x){
        if(d[y][x] == d[y-1][x]) --y;
        else if(d[y][x] == d[y][x-1]) --x;
        else{
            s.push(a[y]);
            --y; --x;
        }
    }
    while(!s.empty()){
        printf("%c",s.top()); s.pop();
    }
    return 0;
}
