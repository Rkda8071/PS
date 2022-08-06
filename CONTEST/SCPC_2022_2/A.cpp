/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
using namespace std;
typedef long long ll;

ll n,k,a[100100];
int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
	int T, test_case;
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		scanf("%lld %lld",&n,&k);
        for(ll i=0;i<n;i++) scanf("%lld",&a[i]);
        ll up=0,co=0;
		ll l=0, r=n-1;
		while(l<=r){
		    if(a[l]+up >= k)
                l++;
            else if(a[r]+up >= k)
		        r--;
		    else if(a[l]+up < a[r]+up && a[r]+up < k){
		        ll ang = k-(a[r]+up);
		        up += ang;
		        co += (r-l+1)*ang;
		        r--;
		    }else{
		        ll ang = k-(a[l]+up);
		        up += ang;
		        co += (r-l+1)*ang;
		        l++;
		    }
		}
		printf("Case #%d\n",test_case+1);
		printf("%lld %lld\n",up,co);
	}

	return 0;//Your program should return 0 on normal termination.
}