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
    for(int i=0;i<n;i++){
        scanf(" %s",a[i]);
        pq.push({i,0});
    }
    int ang = 0;
    while(!pq.empty()){
        int idx, last;
        idx = pq.top().idx; last = pq.top().last; pq.pop();
        printf("[%d %d]",idx,last);
        printf("%c",a[idx][last]);
        if(a[idx][++last] != '\0')
            pq.push({idx,last});
    }

    return 0;
}
