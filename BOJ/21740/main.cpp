#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
    string raw,val,rev;
    bool operator<(const A &r)const{
        return rev + r.rev < r.rev + rev;
    }
}a[100010];
void init(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    string tmp = "0";
    for(int i=0;i<n;i++){
        int x = 0, cnt = 0;
        cin >> a[i].raw;
        for(int j = a[i].raw.length() - 1; j>=0; j--){
            x *= 10;
            int y = a[i].raw[j] - '0';

            if(y==6) x += 9;
            else if(y==9) x+=6;
            else x += y;

            if(x == 0 && y == 0) cnt++;
        }
        a[i].val = to_string(x);
        for(int j = a[i].raw.length() - 1; j>=0 && a[i].raw[j] == '0'; j--)
            a[i].rev += '0';
        a[i].rev += a[i].val;
    }
}
int main(){
    int maxim = 0;
    init();
    sort(a,a+n);
    for(int i=1;i<n;i++){
        if(a[maxim].rev.length() < a[i].rev.length()){
            maxim = i;
        }else if(a[maxim].rev.length() == a[i].rev.length() && a[maxim].rev < a[i].rev){
            maxim = i;
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i].raw;
        if(i==maxim) cout << a[i].raw;
    }
    return 0;
}
