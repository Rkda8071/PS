#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
int yyy[4] = {2,0,-2,0}, xxx[4] = {0,-2,0,2};
int d[4][1010][1010];
int n,m,w,cnt;
char a[1010][1010];
vector<int> ans;
// s ����
// l ��ȸ��
// r ��ȸ��
// 0: ��, 1: ��, 2: ��, 3: ��
int f(int y,int x,int t){
    if(d[t][y][x]) return 0;
    d[t][y][x] = 1;
    if(a[y][x] == 'R'){
        if(--t<0) t = 3;
    }
    else if(a[y][x] == 'L'){
        t = (t+1)%4;
    }
    int yy=y+yyy[t],xx=x+xxx[t];

    if(xx<0) xx = m*2-1;
    if(xx>m*2-1) xx = 1;
    if(yy<0) yy = n*2-1;
    if(yy>n*2-1) yy = 1;

    return f(yy,xx,t)+1;
}

int main(){
    n = 2;
    m = 1;

    a[1][1] = 'R';
    a[3][1] = 'R';

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                if(d[k][i*2+1][j*2+1]) continue;
                //d[k][i][j] = 1;
                ans.push_back(f(i*2+1,j*2+1,k));
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int x:ans){
        printf("%d ",x);
    }
    //return ans;
=======

int main(){
    vector<int> v;
    cout << typeid(v.size()).name();
>>>>>>> 3faccd4f72ac869485130781e8b7d4e7a2f95cce
}
