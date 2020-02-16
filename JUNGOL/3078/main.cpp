#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
set<p> s;
queue<int> q;
int a,b,c,d;
void f(int x,int y,int z){
    //full x
    if(x<a){
        if(s.find(make_pair(a,y)) == s.end()){
            s.insert(make_pair(a,y));
            q.push(a); q.push(y); q.push(z+1);
        }
    }
    //empty x
    if(x>0){
        if(s.find(make_pair(0,y)) == s.end()){
            s.insert(make_pair(0,y));
            q.push(0); q.push(y); q.push(z+1);
        }
    }
    //full y
    if(y<b){
        if(s.find(make_pair(x,b)) == s.end()){
            s.insert(make_pair(x,b));
            q.push(x); q.push(b); q.push(z+1);
        }
    }
    if(y>0){
        if(s.find(make_pair(x,0)) == s.end()){
            s.insert(make_pair(x,0));
            q.push(x); q.push(0); q.push(z+1);
        }
    }
    int xx,yy;
    if(x>0 && y<b){
        xx = x - min(x,b-y);
        yy = y + min(x,b-y);
        if(s.find(make_pair(xx,yy)) == s.end()){
            s.insert(make_pair(xx,yy));
            q.push(xx); q.push(yy); q.push(z+1);
        }
    }
    //move y,x
    if(y>0 && x<a){
        xx = x + min(y,a-x);
        yy = y - min(y,a-x);
        if(s.find(make_pair(xx,yy)) == s.end()){
            s.insert(make_pair(xx,yy));
            q.push(xx); q.push(yy); q.push(z+1);
        }
    }
}
int main(){
    int x,y,z;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    q.push(0); q.push(0); q.push(0); s.insert(make_pair(0,0));
    while(!q.empty()){
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        z = q.front(); q.pop();
        if(x == c && y == d){
            printf("%d",z);
            x = -1; y = -1;
            break;
        }
        f(x,y,z);
    }
    if(x>=0 && y>=0) printf("-1");
    return 0;

}

/*int xe[100100],ye[100100];
int xf[100100],yf[100100];
queue<int> q;
int main(){
    int a,b,c,d;
    int x,y;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    q.push(0); q.push(0);
    while(!q.empty()){
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        if(x==0){
            // full x
            if(xf[y] == 0 || xf[y] > xe[y] + 1){
                xf[y] = xe[y] + 1;
                q.push(a); q.push(y);
            }
            // move y,x
            if(y>0){
                int xx = x + min(y,a-x), yy = y - min(y,a-x);
                if(c == xx && d == yy){
                    printf("%d",xf[y] + 1);
                    x = y = -1;
                    break;
                }
                if(xx == a && (xf[yy] == 0 || xf[yy]>xe[y] + 1){
                    xf[yy] = xe[y] + 1;
                    q.push(xx); q.push(yy);
                }
                if(yy == 0 && (ye[xx] == 0 || ye[xx]>xe[y] + 1)){
                    ye[xx] =xe[y] + 1;
                    q.push(xx); q.push(yy);
                }
            }
        }
        else if(x==a){

        }
        if(y==0){
            // full y
            if(yf[x] == 0 || yf[x] > ye[x] + 1){
                yf[x] = ye[x] + 1;
                q.push(x); q.push(b);
            }
        }
    }
    if(x>=0 && y>=0) printf("-1");
    return 0;
}*/
