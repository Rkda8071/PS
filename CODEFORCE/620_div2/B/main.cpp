#include<bits/stdc++.h>
using namespace std;
char a[110][61];
int chk[110];
stack<char> s;
queue<char> q;
int main(){
    int n,m,k;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=1;i<n;i++){
        if(chk[i]) continue;
        for(int j=i+1;j<=n;j++){
            if(i==j || chk[j]) continue;
            bool ang = true;
            for(int l=1;l<=m;l++){
                if(a[i][l]!=a[j][m-l+1]){
                    ang = false;
                    break;
                }
            }
            if(ang){
                chk[i] = j; chk[j] = 2;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(chk[i]) continue;
        bool ang =true;
        for(int j=1;j<=m/2;j++){
            if(a[i][j]!=a[i][m-j+1]){
                ang = false;
                break;
            }
        }
        if(ang){
            chk[i] = -1;
        }
    }
    k = 0;
    for(int i=1;i<=n;i++){
        if(chk[i]>0){
            k+=m*2;
            chk[chk[i]] = 0; chk[i] = 0;
            for(int j=1;j<=m;j++){
                q.push(a[i][j]);//printf("%c",a[i][j]);
                s.push(a[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(chk[i]==-1){
            k+=m;
            for(int j=1;j<=m;j++) q.push(a[i][j]);//printf("%c",a[i][j]);
            break;
        }
    }
    printf("%d\n",k);
    while(!q.empty()){
        printf("%c",q.front()); q.pop();
    }
    while(!s.empty()){
        printf("%c",s.top()); s.pop();
    }
    return 0;
}
