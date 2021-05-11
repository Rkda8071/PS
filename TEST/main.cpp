#include <stdio.h>
#include <algorithm>
using namespace std;
int ba[100100];
int main()
{
    int a,b,c,d,e,f,m,n;
    scanf("%d",&a);
    for(m=0;m<a;m++)
    {
        scanf("%d.%d.%d",&b,&c,&d);
        ba[m]=b*1000+c*100+d;
    }
    sort(ba,ba+a);
    for(m=0;m<a;m++)
    {
        b=ba[m]-ba[m]/1000*1000;
        printf("%d.%02d.%02d\n",ba[m]/1000,b/100,ba[m]%100);
    }
}
