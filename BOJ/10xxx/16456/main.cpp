#include<bits/stdc++.h>
using namespace std;
// ������ 1
// �ϳ� �ٰ� �ϳ� 2
// �� -1

// a[1]�� 0���� �� ä��� 1�� ����
// a[2]�� 1���� �� ä��� 2�� ����

// iĭ���� i+2ĭ���� i+1ĭ���� i+3ĭ���� -> a[i]�� a[i+3]��
// a[i]�� a[i+1]��

int a[50100];
int main(){
    int n;
    scanf("%d",&n);
    a[0] = a[1] = a[2] = 1;

    for(int i=3;i<=n;i++){
        a[i] = a[i-1] + a[i-3];
        a[i] %= 1000000009;
    }
    printf("%d",a[n]);
}
