#include<bits/stdc++.h>
// O(10*10 * 4^10)
// == 1�� �� �ѳ�
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
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%c",a[i][j]);
        puts("");
    }
    puts("");*/
    if(a[2][3] == 'W' && a[3][3] == 'B'){
        w = w;
    }
    if(a[2][3] == 'W' && a[3][2] == 'B'){
        w = w;
    }
    //��������
    int curw = w;
    if(pre != 1){
        for(int i=2;i<n;i++){
            int x = 2;
            if(w<0) break;
            for(int j=2;j<m;j++){
                if(a[i][j] == '#') x = j+1; // ���ο� ���̴�
                else if(a[i][j] == 'O') x = j;
                else if(j == x && a[i][j] != '.') x++;
                else if(j != x && a[i][j] != '.'){
                    // ������ ������
                    if(a[i][x] == '.') a[i][x++] = a[i][j];
                    else{ // �������� ����
                        if(a[i][j] == 'W') --w;
                        else w = -1;
                    }
                    a[i][j] = '.';
                }
            }
        }
        if(w>=0) f(cnt+1,w,1);
    }
    // ����������
    if(pre !=2){
        w = curw;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = cur[i][j];
        for(int i=2;i<n;i++){
            int x = m-1;
            if(w<0) break;
            for(int j=m-1;j>=2;j--){
                if(a[i][j] == '#') x = j-1; // ���ο� ���̴�
                else if(a[i][j] == 'O') x = j;
                else if(j == x && a[i][j] != '.') x--;
                else if(j != x && a[i][j] != '.'){
                    // ������ ������
                    if(a[i][x] == '.') a[i][x--] = a[i][j];
                    else{ // �������� ����
                        if(a[i][j] == 'W') --w;
                        else w = -1;
                    }
                    a[i][j] = '.';
                }
            }
        }
        if(w>=0) f(cnt+1,w,2);
    }
    // �Ʒ�������
    if(pre!=3){
        w = curw;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = cur[i][j];
        for(int j=2;j<m;j++){
            if(pre == 3) break;
            int y = n-1;
            for(int i=n-1;i>=2;i--){
                if(a[i][j] == '#') y = i-1; // ���ο� ���̴�
                else if(a[i][j] == 'O') y = i;
                else if(i == y && a[i][j] != '.') y--;
                else if(i != y && a[i][j] != '.'){
                    // ������ ������
                    if(a[y][j] == '.') a[y--][j] = a[i][j];
                    else{ // �������� ����
                        if(a[i][j] == 'W') --w;
                        else w = -1;
                    }
                    a[i][j] = '.';
                }
            }
        }
        if(w>=0) f(cnt+1,w,3);
    }
    // ��������
    if(pre!=4){
        w = curw;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = cur[i][j];
        for(int j=2;j<m;j++){
            if(pre == 4) break;
            int y = 2;
            for(int i=2;i<n;i++){
                if(a[i][j] == '#') y = i+1; // ���ο� ���̴�
                else if(a[i][j] == 'O') y = i;
                else if(i == y && a[i][j] != '.') y++;
                else if(i != y && a[i][j] != '.'){
                    // ������ ������
                    if(a[y][j] == '.') a[y++][j] = a[i][j];
                    else{ // �������� ����
                        if(a[i][j] == 'W') --w;
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
        for(int j=1;j<=m;j++) if(a[i][j] == 'W') wcnt++;
    f(0,wcnt,0);
    if(mini > 10) printf("-1");
    else printf("%d",mini);
    return 0;
}
