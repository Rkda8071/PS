#include <bits/stdc++.h>
using namespace std;

int Answer;
int b[100100],a[100100];
int n,t;

int main(int argc, char** argv)
{
    //setbuf(stdout, NULL);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++){
        scanf("%d %d",&n,&t);
        for(int i=1;i<=n;i++){
            scanf("%1d",&b[i]);
            a[i] = 0;
        }
        for(int i=1;i<=t;i++)
            if(b[i] && i+t<=n)
                a[i+t] = 1;
        for(int i=n;i>n-t;i--)
            if(b[i] && 1<=i-t)
                a[i-t] = 1;
        for(int i=t+1;i<=n-t;i++){
            if(b[i]){
                if(a[i+t]==0 && a[i-t]==0){
                    if(i+t+t>n || (i+t+t<=n && b[i+t+t]))
                        a[i+t] = 1;
                    else
                        a[i-t] = 1;
                }
            }
        }

        cout << "Case #" << test_case+1 << endl;
        for(int i=1;i<=n;i++)
            printf("%d",a[i]);
        puts("");
	}

	return 0;
}
