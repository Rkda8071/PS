#include<bits/stdc++.h>
using namespace std;
char in[300100];
int ans;
vector<int> a[3];
int main(){
    scanf("%s",in);
    for(int i=0;in[i];i++) a[in[i]-'A'].push_back(i);
    int ib,ia;
    ia = ib = 0;
    for(int x : a[2]){
        while(ib < a[1].size() && a[1][ib] < x){
            ib++;
            ans++;
            break;
        }
    }
    for(;ib<a[1].size();ib++){
        while(ia < a[0].size() && a[0][ia] < a[1][ib]){
            ia++;
            ans++;
            break;
        }
    }
    printf("%d",ans);
}