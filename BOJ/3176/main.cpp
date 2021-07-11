#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
vector<tp> a[100100];
int n,nn;
tp seg[800000];

void init(){

}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(tp(y,z));
        a[y].push_back(tp(x,z));
    }

    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d %d",&x,&y);
        //x,y중에서 최소간선

    }
}
