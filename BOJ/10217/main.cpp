#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
//pair<int,int> d[110][10010]; // d[���° ����][�� ���] = (�ҿ� �ð�, �� ��° ���ɿ��� ���ȴ���)
int d[110][10010];
priority_queue<tp, vector<tp>, greater<tp> > pq;
vector<tp> a[110];
int n,m,k;
int main(){
    int cnt;
    scanf("%d",&cnt);
    cnt++;
    while(--cnt){
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) d[i][j] = int(1e9);
        for(int i=1;i<=k;i++){
            int u,v,c,cc;
            scanf("%d %d %d %d",&u,&v,&c,&cc);
            a[u].push_back(tp(cc,c,v)); // �ҿ�ð�, ���, ��ġ
        }
        pq.emplace(0,0,1);          // �ҿ�ð�, ���, ��ġ
        d[1][0] = 0; // 1������ �ʱ�ȭ
        int mini = 2000000000;
        while(!pq.empty()){
            int t,c,x; // �ҿ�ð�, ���, ��ġ
            tie(t,c,x) = pq.top(); pq.pop();
            if(d[x][c] < t) continue;     // ������ ���� ���ǿ��� �� ���� ����� ������ �Ÿ�
            if(mini<d[x][c]) continue;    // ������ ������ �Ÿ�
            if(x==n){                     // ��������
                mini = d[x][c];
                continue;
            }
            for(int i=0;i<a[x].size();i++){
                int tt,cc,xx; // �������� �� �� �ҿ�ð� ��� ��ġ
                tie(tt,cc,xx) = a[x][i];
                if(c+cc <= m && d[xx][c+cc]>t+tt){
                    d[xx][c+cc] = t+tt;
                    pq.emplace(t+tt,c+cc,xx);
                }
            }
        }
        if(mini == 2000000000) printf("Poor KCM\n");
        else printf("%d\n",mini);
    }
    return 0;
}
