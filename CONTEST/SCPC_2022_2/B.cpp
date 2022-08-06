#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int r[300010],b[300010],n,nn;
int seg[1200000];
vector<int> a[300010];
int fin(int id,int x,int y,int left,int right){
	if(x > right || y < left) return 0;
	if(x <= left && right <= y) return seg[id];
	return fin(id*2,x,y,left,(left+right)/2) + fin(id*2+1,x,y,(left+right)/2+1,right);
}
void up(int x){
	x += nn-1;
	seg[x] = 1;
	while(x/2){
		x/=2;
		seg[x] = seg[x*2] + seg[x*2+1];
	}
}
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i].clear();
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		a[b[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		r[i] = a[i].size();
		r[i]--;
	}
	for(nn=1;nn<n;nn*=2);
	for(int i=1;i<=nn*2;i++) seg[i] = 0;
}
int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
	int T, test_case;
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		ll ans = 0;
		init();
		for(int i=1;i<n;i++){
			int x = b[i];
			if(i>=a[x][r[x]]) continue;
			ans += (ll)(a[x][r[x]] - i - fin(1,i,a[x][r[x]],1,nn));
			up(a[x][r[x]]);
			r[x]--;
		}
		printf("Case #%d\n",test_case+1);
		printf("%lld\n",ans);
	}

	return 0;//Your program should return 0 on normal termination.
}