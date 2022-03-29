#include<bits/stdc++.h>
using namespace std;
int a[61],cnt[1010],dap[61];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ang = 0;
    while(1){
        if(++ang == 100) break;
        for(int i=n;i>1;i-=2){
            if(a[i-1]+1 == a[i]) swap(a[i-1],a[i]);
        }
        for(int i=n-1;i>1;i-=2){
            if(a[i-1]+1 == a[i]) swap(a[i-1],a[i]);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    /*for(int i=1;i<=n;i++){
        s.insert(a[i]);
        cnt[a[i]]++;
    }
    d.push_back(a[1]); s.erase(s.find(a[1]));
    auto ang = s.begin();
    for(auto it = s.begin(); it!=s.end(); it++){
        if(d[d.size()-1] + 1<*it){
            d.push_back(*it);
            s.erase(it);
            it = ang;
        }
        ang = it;
    }
    ang = s.begin(); int m = 1,j = 0;
    dap[0] = -20000;
    while(1){
        int x = 2000000000, y = 2000000000;
        if(ang == s.end() && j == d.size()) break;
        if(ang != s.end() && dap[m-1]+1 != *ang) x = *ang;
        if(j != d.size() && dap[m-1]+1 != d[j]) y = d[j];
        if(x<y){
            dap[m++] = x;
            if(--cnt[x] == 0) ang++;
        }else{
            dap[m++] = y;
            if(--cnt[y] == 0) ++j;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",dap[i]);
    }*/
    return 0;
}
