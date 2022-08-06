#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> chk;
set<int> s;
vector<int> a[200010];
char b[200010];
bool solve(){
    for(int i=0;i<chk.size();i++){
        int ang = a[chk[i]][0];
        auto it = s.lower_bound(ang);
        if(it == s.end()) return false;
        a[chk[i]].push_back(*it);
        s.erase(it);
    }
    int mini = 1;
    if(s.empty()) return true; 
    for(int i=2;i<=m;i++){
        if(a[mini][a[mini].size()-1] > a[i][a[i].size()-1])
            mini = i;
    }
    if(a[mini][a[mini].size()-1] > *(s.begin())) return false;
    for(auto it : s){
        a[mini].push_back(it);
    }
    return true;
}
int main(){
    int sw = 0;
    char imsi[10];
    scanf("%d %d",&n,&m);
    for(int i=1;i<=2*n;i++)
        s.insert(i);
    
    for(int i=1,x;i<=m;i++){
        scanf(" %c %s %d",&b[i],imsi,&x);
        a[i].push_back(x);
        s.erase(a[i][0]);
        if(i && b[i] == b[i-1]) chk.push_back(i-1);
    }
    if(b[m] == 'A') chk.push_back(m);

    if(solve()){
        printf("YES\n");
        for(int i=1;i<=m;i++){
            printf("%c BLOCK %d\n",'A' + sw, a[i][0]);
            sw = (sw+1)%2;
            for(int j=1;j<a[i].size();j++){
                printf("%c CHAIN %d\n",'A' + sw, a[i][j]);
                sw = (sw+1)%2;
            }
        }
    }else{
        printf("NO");
    }

}