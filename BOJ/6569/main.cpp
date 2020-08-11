#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int> tp;
queue<tp> q;
int n,m;
ll d[12][1<<11];
ll dap[12][12];
void solve(){
    n = 11;
    for(m=1;m<=11;m++){
        for(int i=0;i<n;i++)
            for(int j=0;j<(1<<m);j++)
                d[i][j] = 0LL;


        // i ���� ���Ʒ��� ����� 1 �¿�� ����� 0
        // (���Ʒ��� �������) 1�� �������� �տ� 1�� �ְų� �տ� 00�� �־����
        q.emplace(0,2); q.emplace(1,1);
        while(!q.empty()){
            int x,cur;
            tie(x,cur) = q.front(); q.pop();
            if(cur == m){
                d[0][x] += 1L;
                continue;
            }
            if(cur+1 <= m) // 1���� ��
                q.emplace(x|(1<<cur),cur+1);
            if(cur+2 <= m) // 0���� ��
                q.emplace(x,cur+2);
        }

        for(int i=1;i<n;i++){
            // 1. �� ������ �ߴ� �͵� q���ٰ� �� ���� �ֱ�
            // 2. q ������
            // ����
            for(int j=0;j<(1<<m);j++){
                if(d[i-1][j]){
                    // f = j , t = d[i-1][j];
                    q.emplace(0,0);
                    while(!q.empty()){
                        int x,cur;
                        tie(x,cur) = q.front(); q.pop();
                        if(cur == m){
                            d[i][x] += d[i-1][j];
                            continue;
                        }
                        int chk = 0;
                        for(int l=cur;l<m;l++){
                            if(!(j&(1<<l))){ //�������?
                                if(l+1 <= m)// 1���� ��
                                    q.emplace(x|(1<<l),l+1);
                                if(l+2 <= m && !(j&(1<<(l+1)))) // 0���� ��
                                    q.emplace(x,l+2);
                                chk = 1;
                                break;
                            }
                        }
                        if(chk) continue;
                        else d[i][x] += d[i-1][j];
                    }
                }
            }
        }
        for(int i=m;i<=n;i++){
            dap[i][m] = d[i-1][0];
        }
    }
}
int main(){
    solve();
    //printf("%lld",d[n-1][0]);
    while(1){
        int x,y;
        scanf("%d %d",&x,&y);
        if(!x && !y) break;
        if(y>x) swap(y,x);
        printf("%lld\n",dap[x][y]);
    }
    return 0;
}
