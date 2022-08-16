/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
using namespace std;
int n,k,a[300][300],hap[300][300];
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            hap[i][j] = hap[i-1][j] + hap[i][j-1] - hap[i-1][j-1] + a[i][j];
}
int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
	int T, test_case;
	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{
        int ans = 0;
        init();
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            for(int ii=i;ii<=n;ii++) for(int jj=j;jj<=n;jj++){
                int mini = n+1;
                for(int l=i;l<=ii;l++) for(int k=j;k<=jj;k++)
                    mini = min(mini,a[l][k]);
                int ang = hap[ii][jj] - hap[ii][j-1] - hap[i-1][jj] + hap[i-1][j-1];
                int m = (ii-i+1) * (jj-j+1);
                if(2*m*mini == 2*ang-m*m+m) ans++;
                else printf("[%d %d %d]",mini,m,ang);
            }
        }

		printf("Case #%d\n",test_case+1);
		printf("%d\n",ans);
	}

	return 0;//Your program should return 0 on normal termination.
}