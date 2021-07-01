#include<bits/stdc++.h>
using namespace std;
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

}
