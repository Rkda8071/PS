#include<bits/stdc++.h>
using namespace std;
int n,m,t;
char a[20][20];
int d[20][1<<10];
//d[����][���� �ܰ迡���� ��Ʈ����ũ]

void init(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
            scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<m);j++)
            d[i][j] = -1;
    for(int j=0;j<(1<<m);j++)
        d[n][j] = 0;
}
bool chk(int i,int j){
    //������ �¼��� �ɾҳ�?
    //�����ؼ� �ɾҳ�?
    for(int l=0;l<m;l++){
        int x = (1<<l);
        if((j&x) == 0) continue; //l��°���� �� ����
        if((l>0 && (j&(x>>1)) || a[i][l] == 'x')) // �Ҳɰ���
            return 0;
    }
    return 1;
}

int solve(){
    int dap = 0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<(1<<m);j++){ //i��° ��, j������ �¼�
            if(!chk(i,j)) continue;
            int x = __builtin_popcount(j);
            for(int l=0;l<(1<<m);l++){// �ؿ��� ������ ��
                if(d[i+1][l] == -1) continue; //�� ����
                //������ ��ġ�� ��Ʈ�� �ֳ�?
                int ang = 0;
                for(int k=0;k<m;k++){
                    if((l&(1<<k)) &&
                       ((((1<<(k-1)) | (1<<(k+1))) & j) != 0))
                        ang = 1;
                }
                if(ang==0) d[i][j] = max(d[i][j],d[i+1][l]+x);
            }
            dap = max(dap, d[i][j]);
        }
    }
    return dap;
}

int main(){
    scanf("%d",&t);
    while(t--){
        init();
        printf("%d\n",solve());
    }
    return 0;
}
