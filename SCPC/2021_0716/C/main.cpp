#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int Answer;
int n,m,k,dap[2010];
vector<int> a[2010];
tp b[2010];
int p,ans[2010];

bool dfs(int x){
    for(auto i=a[x].begin();i!=a[x].end();i++){
        int y = *i;
        if(y == p) return 1;
        if(dfs(y)) return 1;
    }
    return 0;
}

int main(int argc, char** argv){
    setbuf(stdout, NULL);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            a[i].clear();
        }
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            a[x].push_back(y);
        }
        for(int i=1;i<=k;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            b[i] = tp(x,y);
        }
        for(int i=1;i<=k;i++){
            int s,e;
            tie(s,e) = b[i];
            ans[i] = 0; p = s;
            a[s].push_back(e);
            if(!dfs(s)) continue;
            a[s].pop_back();

            ans[i] = 1; p = e;
            a[e].push_back(s);
            //dfs(e);
            //a[e].pop_back();
        }
		cout << "Case #" << test_case+1 << endl;
        for(int i=1;i<=k;i++)
            printf("%d",ans[i]);
        puts("");
	}

	return 0;//Your program should return 0 on normal termination.
}
