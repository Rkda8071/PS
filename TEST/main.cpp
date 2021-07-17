#include <stdio.h.>
#include <stdlib.h>
int a,b,c,d,e,f,g,m,n;
int ch[1000];

int ja(int x)
{
    if(x==b)
    {
        printf("\n");
        for(n=0;n<a;n++)
            ch[n]=0;
        return 0;
    }
    for(m=0;m<a;m++)
    {
        if(ch[m]!=1)
        {
            ch[m]=1;
            printf("%c",'a'+m);
            ja(x+1);
        }
    }
}
int main()
{
    scanf("%d %d",&a,&b);
    ja(0);
    return 0;
}
