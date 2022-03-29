#include<bits/stdc++.h>
using namespace std;
int m;
void hanoi(int n,int from,int by,int to){
    if(n == 1){
        printf("%d %d\n",from,to);
        return;
    } else{
        hanoi(n-1,from,to,by);
        printf("%d %d\n",from,to);
        hanoi(n-1,by,from,to);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    long long a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		b *= 2;
		a = a * 2 + 1;
		b += a / 1000000000000000000;
		a %= 1000000000000000000;
	}
	if(b>0) printf("%lld",b);
    printf("%lld\n",a);
    if(n<=20) hanoi(n,1,2,3);
    return 0;
}
