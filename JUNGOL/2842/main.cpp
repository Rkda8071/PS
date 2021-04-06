#include<bits/stdc++.h>
using namespace std;
int fail[1000100],chk[1000100],cnt[1000100];
char s[1000100];
char t[1000100];
int main(){
    scanf("%s %s",s+1,t+1);
    int n,m;
    for(n=1;s[n+1]!=NULL;n++);
    for(m=1;t[m+1]!=NULL;m++);

    for(int i=2,k=0; t[i]!=NULL;i++){
        while(k && t[k+1] != t[i])
            k = fail[k];
        if(t[k+1] == t[i])
            fail[i] = ++k;
    }

    for(int i=1,k=0; s[i]!=NULL;i++){
        while(k && t[k+1] != s[i])
            k = fail[k];
        if(t[k+1] == s[i]){
            k++;
            if(k==m){
                int ang = 0;
                for(int j=0;j<m;j++){
                    while(chk[i-j-ang]) ang += m;
                    chk[i-j-ang] = 1;
                }
                k = cnt[i-m-ang];
            }
        }
        cnt[i] = k;
    }
    for(int i=1;i<=n;i++)
        if(!chk[i]) printf("%c",s[i]);
    return 0;
}


//ababcababababcabab
