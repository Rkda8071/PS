#include<bits/stdc++.h>
using namespace std;
char s[1000100],t[100100];
vector<int> a[26];
int f(){
    int dap = 1,cnt = 0;
    for(int i=1;s[i]!=NULL;i++){
        int id = s[i]-'a';
        if(a[id].size()){
            if(cnt>=a[id][a[id].size()-1]){
                cnt = a[id][0];
                dap++;
            }else{
                auto ang = upper_bound(a[id].begin(),a[id].end(),cnt);
                cnt = *ang;
            }
        }else return -1;
    }
    return dap;
}
int main(){
    scanf("%s %s",s+1,t+1);
    for(int i=1;t[i]!=NULL;i++)
        a[t[i]-'a'].push_back(i);
    printf("%d",f());
}
