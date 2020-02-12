#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,g,b,m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld",&n,&g,&b);
        m = (n+1)/2;
        //printf("%lld",(m/g-1))
        if(m<=g) printf("%lld\n",n);
        else if(m%g==0) printf("%lld\n",max(n,((m/g)-1)*(g+b) + g));
        else printf("%lld\n",max(n,(m/g)*(g+b) + m%g));

    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,g,b,m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld",&n,&g,&b);
        m = (n+1)/2;
        if(m<=g) printf("%lld\n",n);
        else printf("%lld\n",((m/g)-1)*(g+b) + g);
    }
}
*/
