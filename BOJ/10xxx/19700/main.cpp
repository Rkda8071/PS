#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,cur,chk,pre;
tp a[500010];
multiset<int> s;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&y,&x);
        a[i] = tp(y,x);
    }
    sort(a,a+n,greater<tp>());

    for(int i=0;i<n;i++){
        int yy,xx,y,x,flag=1;
        tie(y,x) = a[i];
        if(pre==y && chk<x){
            s.erase(s.find(cur));
            s.insert(++cur);
            flag = 0;
        }
        for(auto it = s.lower_bound(x);;){
            if(it == s.begin())
                break;
            it--;
            xx = *it;
            if(xx<x){
                s.erase(it);
                s.insert(xx+1);
                chk = xx;
                cur = xx+1;
                flag = 0;
            }
            break;
        }
        if(flag){
            s.insert(1);
            chk = 0;
            cur = 1;
        }
        pre = y;
    }
    printf("%d",(int)s.size());
    return 0;
}
