#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Answer;
int n,m;
int main(int argc, char** argv)
{
	int T, test_case;
    cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        scanf("%d %d",&n,&m);
        vector<ll> a[n];
        ll dap,m1,m2;
        dap = m1 = m2 = 0LL;
        for(int i=0;i<n;i++){
            int k;
            ll x;
            scanf("%d",&k);
            for(int j=0;j<k;j++){
                scanf("%lld",&x);
                a[i].push_back(x);
            }
            sort(a[i].begin(),a[i].end());
            if(k%2==0){
                ll ang = a[i][2] + a[i][3];
                dap += a[i][0]+a[i][1]+ang;
                if(m1<ang){
                    m2 = m1;
                    m1 = ang;
                }else if(m2<ang){
                    m2 = ang;
                }
            }else{
                ll ang = a[i][2] +a[i][3];
                dap += a[i][0]*2+a[i][1]+ang;
                if(m1<ang){
                    m2 = m1;
                    m1 = ang;
                }else if(m2<ang){
                    m2 = ang;
                }
            }
        }

		cout << "Case #" << test_case+1 << endl;
        printf("%lld\n",dap - m1 - m2);
	}

	return 0;//Your program should return 0 on normal termination.
}
