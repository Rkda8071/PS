#include<bits/stdc++.h>
using namespace std;
int t;
char a[200];
bool f(){
    int cnt = 0,chk = 0;
    for(int i=1;a[i]!=NULL;i++){
        if(a[i] == '?') chk++;
        else if(a[i] == ')') cnt--;
        else cnt++;
    }
    int cc=0, ang = 0;
    for(int i=1;a[i]!=NULL;i++){
        if(a[i] == '?'){
            if(chk/2 + cnt>cc) ang++;
            else ang--;
            cc++;
        }else if(a[i] == ')') ang--;
        else ang++;
        if(ang<0) return false;
    }
    if(ang == 0) return true;
    else return false;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",a+1);
        if(f()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
