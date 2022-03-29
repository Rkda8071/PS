#include<bits/stdc++.h>
using namespace std;
set<int> s;
int c[110],a[110];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    a[0] = c[0] = 2000000000;
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        if(s.size() == n){ // ²Ë Ã¡À½?
            if(s.find(x) != s.end()) c[x]++;
            else{ // ¾øÀ½!
                int mini = 0;
                for(auto it=s.begin(); it!=s.end(); it++)
                    if(c[mini]>c[(*it)])
                        mini = (*it);
                    else if(c[mini] == c[(*it)] && a[mini]>a[(*it)])
                        mini = (*it);

                s.erase(mini);
                c[mini] = 0;

                s.insert(x);
                a[x] = i;
                c[x]++;
            }
        }else{ // ºñ¾úÀ½
            s.insert(x);
            if(c[x] == 0) a[x] = i;
            c[x]++;
        }
    }
    for(auto it=s.begin(); it!=s.end(); it++)
        printf("%d ",*it);
    return 0;
}
