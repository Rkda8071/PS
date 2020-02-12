#include<bits/stdc++.h>
using namespace std;
char a[500],ang[500];
int chk[500],d[500];
int main(){
    int t,sw,s;
    scanf("%d",&t);
    t++;
    while(--t){
        scanf("%s",a+1);
        chk[a[1] - 'a'] = t; d[a[1]-'a'] = 100;
        ang[100] = a[1];
        sw = 1; s = 100;
        for(int i=2;a[i]!=NULL;i++){
            if(chk[a[i]-'a'] == t){
                if(abs(d[a[i]-'a'] - d[a[i-1]-'a'])!=1){
                    s= 0; break; //NO
                } else sw = d[a[i]-'a'] - d[a[i-1]-'a'];
            }
            else{
                int x = ang[d[a[i-1]-'a']+sw];
                if(x!=0 && chk[x-'a'] == t) {s=0; break;} //NO
                else {
                    d[a[i]-'a'] = d[a[i-1]-'a']+sw;
                    ang[d[a[i-1]-'a']+sw] = a[i];
                    chk[a[i]-'a'] = t;
                    s = min(s,d[a[i]-'a']);
                }
            }
        }
        if(s==0) printf("NO");
        else{
            printf("YES\n");
            for(int i=s; chk[ang[i]-'a']==t; i++){
                printf("%c",ang[i]);
            }
            for(int i=0;i<26;i++){
                if(chk[i] != t) printf("%c",i+'a');
            }
        }
        puts("");
    }
}
