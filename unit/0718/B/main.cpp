#include<bits/stdc++.h>
using namespace std;
// k�� ���� -> ����
// ������ ���� n��
// �ּ� ���� L
typedef long long ll;
ll n,m,l,k;
ll t[100100],d[100100],cnt[100100];
vector<ll> a[100100];
queue<ll> q;
int main(){
    scanf("%lld %lld %lld %lld",&n,&m,&l,&k);
    for(ll i=1LL;i<=n;i++)
        scanf("%lld",&t[i]);
    for(ll i=1LL;i<=n;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y); //y�� �Ϸ��� x�� �ؾ���
        cnt[y]++; a[x].push_back(y);
    }

    for(ll i=1LL;i<=n;i++){
        if(cnt[i] == 0LL){
            q.push(i);
            break;
        }
    }

    while(!q.empty()){
        ll x,y;
        x = q.front(); q.pop(); // ���� ����
        d[x] += t[x]; // x������ ������ ���� �ð�
        if(x==l) break; // L ���� �Ϸ�!
        for(auto i=a[x].begin(); i!=a[x].end(); i++){
            y = *i;
            d[y] = max(d[y],d[x]);
            if(--cnt[y] == 0LL)
                q.push(y);
        }
    }
    if(0LL<d[l] && d[l]<=k) printf("%lld",d[l]);
    else printf("Give Up :(");
    return 0;
}

/*
    �����ؾ��� ��
    ���� ���� ���� ������� ���° ��������
    -> �� �ڵ忡���� ���ǻ� 1��° �������� ������
*/
