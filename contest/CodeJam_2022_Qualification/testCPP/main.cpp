#include<bits/stdc++.h>
using namespace std;
int n;
char a[21][1001];

struct A{
    int idx,last;
    bool operator < (const A &r)const{
        return strcmp(strcat(a[idx] + last,a[r.idx] + r.last), strcat(a[r.idx] + r.last, a[idx] + last)) > 0;
    }
};

priority_queue<A> pq;

int main(){
    scanf("%d",&n);
    for(int i=0,j;i<n;i++){
        scanf(" %s",a[i]);
        printf("[%s]\n",a[i]);
        pq.push({i,0});
    }
    int ang = 0;

    a[0] = strcat(a[0], a[1]);
    printf("%s",a[0]);
    //printf("[%s]", strcat(a[0], a[1]));
    //printf("[%s]", strcat(a[1], a[0]));
    while(!pq.empty()){
        int idx, last;
        idx = pq.top().idx; last = pq.top().last; pq.pop();
        printf("[%d %d]",idx,last);
        printf("%c",a[idx][last]);
        if(a[idx][last + 1] != '\0')
            pq.push({idx,last + 1});


        if(++ang == 2) break;
    }

    return 0;
}
