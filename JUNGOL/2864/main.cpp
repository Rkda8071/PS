#include<bits/stdc++.h>
using namespace std;
int d[51][51][51][51];
int main(){
    int h1,w1,h2,w2;
    scanf("%d %d %d %d",&h1,&w1,&h2,&w2);
    for(int hh=0;hh<=h2;hh++){
        for(int ww=0;ww<=w2;ww++){
            if(hh && !ww) continue;
            for(int h=hh+1;h<=h1;h++){
                for(int w=ww+1;w<=w1;w++){

                }
            }
        }
    }
}
