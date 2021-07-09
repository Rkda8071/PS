#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, r1_start, r2_start;
vector<pair<int, int>> bridge[100100];
vector<int> path;
int vis[100100]={0};
int dfs(int k)
{
    if(k==r2_start)
        return 1;

    int found = 0;
    for(int i=0; i<bridge[k].size(); i++)
    {
        if(!vis[bridge[k][i].first]){
            vis[bridge[k][i].first] = 1;
            if(dfs(bridge[k][i].first)){
                path.push_back(bridge[k][i].second);
                found = 1;
            }
        }
    }

    return found;


}
int main()
{
    scanf("%d %d %d",&n,&r1_start,&r2_start);
    for(int i=0; i<n-1; i++){
        int u,v,cost;
        scanf("%d %d %d",&u,&v,&cost);
        bridge[u].push_back({v,cost});
        bridge[v].push_back({u,cost});
    }
    vis[r1_start]=1;
    dfs(r1_start);
    sort(path.begin(), path.end());
    int ans = 0;
    for(int i=0; i<(int)(path.size()-1); i++)
        ans += path[i];

    printf("%d",ans);

}
