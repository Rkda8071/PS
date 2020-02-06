//9426랑 문제 같지만
//이 문제가 데이터 더 빡셈
// Tq 왜 멀티셋으로 안되냐
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<int> s;
multiset<int>::iterator it = s.begin();
int a[250100];
int n,k,x,y,l,r;
void update(){
    if(l>r) {it--;l--;r++;}
    if(l+1<r) {it++;l++;r--;}
}
int main(){
    freopen("input.txt","r",stdin);
    ll hap = 0;

    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        s.insert(a[i]);
        if(s.size() == 1) it = s.begin();
        else (*it>a[i]) ? l++ : r++;
        update();

        if(i<k) continue;
        hap+=(*it);
        (*it) == a[i-k+1] ? r-- : l--;
        if((*it) == a[i-k+1]) (it)++;
        s.erase(s.lower_bound(a[i-k+1]));
        update();
    }
    printf("%lld",hap);
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int seg[300000],a[250000];
int n,k,nn;
long long int hap;
void add(int x){
    int lev = x+nn;
    while(lev){
        seg[lev]++;
        lev/=2;
    }
}
void del(int x){
    int lev = x+nn;
    while(lev){
        seg[lev]--;
        lev/=2;
    }
}
int f(int lev,int x){
    if(lev>=nn) return lev-nn;
    if(seg[lev*2] && x+seg[lev*2]>=(k+1)/2) return f(lev*2,x);
    else if(seg[lev*2+1]) return f(lev*2+1,x+seg[lev*2]);
    else return 0;
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(nn=1;nn<65536;nn*=2);
    for(int i=1;i<=n;i++){
        add(a[i]);
        if(i<k) continue;
        hap += f(1,0);
        del(a[i-k+1]);
    }
    printf("%lld",hap);
    return 0;
}
