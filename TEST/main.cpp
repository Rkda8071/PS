<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int main(){
    printf("\"100%% 가능할거야!\"");
=======
#include<stdio.h>
int i,j,n;
int cnt=0,ans=0,t;
int a[100][100],ch[100][100];
void f(int x,int y,int tt)
{
    ch[x][y]=t;
    if(a[x][y]>tt)
    {
        if((x+1)!=n && ch[x+1][y]!=t)
        {
            f(x+1,y,tt);
        }
        if((x-1)!=-1 && ch[x-1][y]!=t)
        {
            f(x-1,y,tt);
        }
        if((y+1)!=n && ch[x][y+1]!=t)
        {
            f(x,y+1,tt);
        }
        if((y-1)!=-1 && ch[x][y-1]!=t)
        {
            f(x,y-1,tt);
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(t=1;t<100;t++)
    {
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]>t && ch[i][j]!=t)
                {
                    f(i,j,t);
                    cnt++;
                }
            }
        }
        //printf("qwertygood");
        if(cnt>ans)
        {
            ans=cnt;
        }
        if(cnt==0)
        {
            break;
        }
    }
    printf("%d",ans);
>>>>>>> c8c9ace7c8914aaaa50347e3a861b3be62fd916b
}
