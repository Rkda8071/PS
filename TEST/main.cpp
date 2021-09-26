#include <bits/stdc++.h>
using namespace std;


int main()
{
    char p[50];
    int kmp[50];
    scanf("%s",p);

    int m = strlen(p);

    int k = -1;
    kmp[0] = -1;
    for(int i=1;i<m;i++){
        while(1){
            if(p[k+1] == p[i]){
                kmp[i] = ++k;
                break;
            }else{
                if(k==-1){
                    kmp[i] = -1;
                    break;
                }
                k = kmp[k];
            }
        }
    }

    for (int i = 0; p[i] != '\0'; i++) {
        printf("f(%d) : %d", i, kmp[i]);
    }

    return 0;
}
