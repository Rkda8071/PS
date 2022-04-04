#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD

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
=======
typedef long long int ll;
typedef pair<ll, ll> pii;
pii p[4];

int ccw(pii a, pii b, pii c){
    ll d = a.first* b.second + b.first * c.second + c.first * a.second -
        a.second * b.first - b.second * c.first - c.second * a.first;

    if (d > 0)
        return 1;
    else if (d < 0)
        return -1;
    else
        return 0;
}


int main(){

    for (int i = 0; i < 4; i++)
        scanf("%lld %lld",&p[i].first,&p[i].second);

    int a = ccw(p[0], p[1], p[2]);
    int b = ccw(p[0], p[1], p[3]);
    int c = ccw(p[2], p[3], p[0]);
    int d = ccw(p[2], p[3], p[1]);

    if (a * b > 0 || c * d > 0)
        printf("0");
    else if (a * b == 0 && c * d == 0)
    {
        if (p[0] > p[1])
            swap(p[0], p[1]);
        if (p[2] > p[3])
            swap(p[2], p[3]);

        if (p[1]<p[2] || p[3] < p[0])
            printf("0");
        else
            printf("1");
    }
    else
        printf("1");

>>>>>>> 519336d2ebe4b6acc46db998758e5263ad13a71c
}
