#include<bits/stdc++.h>
using namespace std;

struct S{
   int x;
   int y;
};
int a[55][55], ch[55][55];
queue<S> q;

int main(){
   int w, h, i, j, k, l, cnt=0;

   while(1){
      scanf("%d %d", &h, &w);

      if(!w&&!h){
         return 0;
      }

      for(i=0;i<w;i++){
         for(j=0;j<h;j++){
            scanf("%d", &a[i][j]);
         }
      }

      for(i=0;i<w;i++){
         for(j=0;j<h;j++){
            if(a[i][j]&&!ch[i][j]){
               q.push({i, j});

               while(!q.empty()){
                  int x=q.front().x;
                  int y=q.front().y;

                  if(x<w-1&&!ch[x+1][y]&&a[x+1][y]){
                     ch[x+1][y]=1;
                     q.push({x+1, y});
                  }
                  if(y<h-1&&!ch[x][y+1]&&a[x][y+1]){
                     ch[x][y+1]=1;
                     q.push({x, y+1});
                  }
                  if(x>0&&!ch[x-1][y]&&a[x-1][y]){
                     ch[x-1][y]=1;
                     q.push({x-1, y});
                  }
                  if(y>0&&!ch[x][y-1]&&a[x][y-1]){
                     ch[x][y-1]=1;
                     q.push({x, y-1});
                  }
                  if(x<w-1&&y<h-1&&!ch[x+1][y+1]&&a[x+1][y+1]){
                     ch[x+1][y+1]=1;
                     q.push({x+1, y+1});
                  }
                  if(x<w-1&&y>0&&!ch[x+1][y-1]&&a[x+1][y-1]){
                     ch[x+1][y-1]=1;
                     q.push({x+1, y-1});
                  }
                  if(x>0&&y<h-1&&!ch[x-1][y+1]&&a[x-1][y+1]){
                     ch[x-1][y+1]=1;
                     q.push({x-1, y+1});
                  }
                  if(x>0&&y>0&&!ch[x-1][y-1]&&a[x-1][y-1]){
                     ch[x-1][y-1]=1;
                     q.push({x-1, y-1});
                  }
                  q.pop();
               }

               cnt++;
            }
         }
      }
        for(k=0;k<50;k++){
           for(l=0;l<50;l++){
              ch[k][l]=0;
              a[k][l]=0;
           }
        }
      printf("%d\n", cnt);
      cnt=0;
   }
}
