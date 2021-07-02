#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> p;
p a[4];

int ccw(p a1,p a2, p b) {
    int x1,y1,x2,y2,x3,y3;
    tie(x1,y1) = a1;
    tie(x2,y2) = a1;
    tie(x3,y3) = b;

    int temp = x1*y2+x2*y3+x3*y1;
    temp = temp - y1*x2-y2*x3-y3*x1;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    } else {
        return 0;
    }
}

int isIntersect(p a,p b,p c,p d) {
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return c<=b && a<=d;
    }
    return ab <= 0 && cd <= 0;
}

int main(){
    for(int i=0;i<4;i++)
        scanf("%d %d",&a[i].first,&a[i].second);
    printf("%d",isIntersect(a[0],a[1],a[2],a[3]));
}
