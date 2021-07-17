
#include<bits/stdc++.h>
using namespace std;

int Answer;
int p[100100],chk[100100],n;
int fin(int x){
    if(p[x] == x) return x;
    return p[x] = fin(p[x]);
}
void uni(int x,int y){
    x = fin(x);
    y = fin(y);
    p[y] = x;
}
int main(int argc, char** argv)
{
	int T, test_case;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
	    scanf("%d",&n);
	    for(int i=1;i<=n;i++)
	        p[i] = i;
	    for(int i=1;i<=n;i++){
	        int x;
	        scanf("%d",&x); // i´Â i+x¶û Ä£±¸´Ù
	        if(i+x>n) continue;
	        uni(i,i+x);
	    }
	    for(int i=1;i<=n;i++){
            if(chk[fin(i)] != test_case+1){
                chk[fin(i)] = test_case+1;
                Answer++;
            }
	    }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
