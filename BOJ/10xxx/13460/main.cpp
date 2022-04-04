#include<bits/stdc++.h>
// O(10*10 * 4^10)
// == 1억 쫌 넘네
int n,m,mini = 11;
char a[20][20];
void f(int cnt,int w,int pre){
    if(mini<=cnt) return;
    if(w == 0){
        mini = cnt;
        return;
    }
    int cur[20][20];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cur[i][j] = a[i][j];
    //왼쪽으로
    int curw = w;
    if(pre != 1){
        for(int i=2;i<n;i++){
            int x = 2;
            if(w<0) break;
            for(int j=2;j<m;j++){
                if(a[i][j] == '#') x = j+1; // 새로운 벽이다
                else if(a[i][j] == 'O') x = j;
                else if(j == x && a[i][j] != '.') x++;
                else if(j != x && a[i][j] != '.'){
                    // 구슬이 있을때
                    if(a[i][x] == '.') a[i][x++] = a[i][j];
                    else{ // 구멍으로 가면
                        if(a[i][j] == 'R') --w;
                        else w = -1;
                    }
                    a[i][j] = '.';
                }
            }
        }
        if(w>=0) f(cnt+1,w,1);
    }
    // 오른쪽으로
    if(pre !=2){
        w = curw;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = cur[i][j];
        for(int i=2;i<n;i++){
            int x = m-1;
            if(w<0) break;
            for(int j=m-1;j>=2;j--){
                if(a[i][j] == '#') x = j-1; // 새로운 벽이다
                else if(a[i][j] == 'O') x = j;
                else if(j == x && a[i][j] != '.') x--;
                else if(j != x && a[i][j] != '.'){
                    // 구슬이 있을때
                    if(a[i][x] == '.') a[i][x--] = a[i][j];
                    else{ // 구멍으로 가면
                        if(a[i][j] == 'R') --w;
                        else w = -1;
                    }
                    a[i][j] = '.';
                }
            }
        }
        if(w>=0) f(cnt+1,w,2);
    }
    // 아래쪽으로
    if(pre!=3){
        w = curw;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = cur[i][j];
        for(int j=2;j<m;j++){
            if(pre == 3) break;
            int y = n-1;
            for(int i=n-1;i>=2;i--){
                if(a[i][j] == '#') y = i-1; // 새로운 벽이다
                else if(a[i][j] == 'O') y = i;
                else if(i == y && a[i][j] != '.') y--;
                else if(i != y && a[i][j] != '.'){
                    // 구슬이 있을때
                    if(a[y][j] == '.') a[y--][j] = a[i][j];
                    else{ // 구멍으로 가면
                        if(a[i][j] == 'R') --w;
                        else w = -1;
                    }
                    a[i][j] = '.';
                }
            }
        }
        if(w>=0) f(cnt+1,w,3);
    }
    // 위쪽으로
    if(pre!=4){
        w = curw;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = cur[i][j];
        for(int j=2;j<m;j++){
            if(pre == 4) break;
            int y = 2;
            for(int i=2;i<n;i++){
                if(a[i][j] == '#') y = i+1; // 새로운 벽이다
                else if(a[i][j] == 'O') y = i;
                else if(i == y && a[i][j] != '.') y++;
                else if(i != y && a[i][j] != '.'){
                    // 구슬이 있을때
                    if(a[y][j] == '.') a[y++][j] = a[i][j];
                    else{ // 구멍으로 가면
                        if(a[i][j] == 'R') --w;
                        else w = -1;
                    }
                    a[i][j] = '.';
                }
            }
        }
        if(w>=0) f(cnt+1,w,4);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf(" %s",a[i]+1);
    int wcnt = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if(a[i][j] == 'R') wcnt++;
    f(0,wcnt,0);
    if(mini > 10) printf("-1");
    else printf("%d",mini);
    return 0;
}
