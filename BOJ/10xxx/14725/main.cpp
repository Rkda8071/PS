#include<bits/stdc++.h>
using namespace std;

struct Tree{
	map<string, Tree*> next;
};

Tree *root = new Tree;

void dfs(Tree *cur, int lev = 0){
	for(auto &p: cur->next){ //for(auto p = cur->next.begin(); p!=cur->next.end(); p++){
		cout << string(lev*2, '-') << p.first << endl;
		dfs(p.second, lev+1);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int k;
		cin >> k;
		Tree *cur = root; // Ʈ�� ���� ����, ��Ʈ�� �ʱ�ȭ
		for(int j=0; j<k; j++){ // �Է� �����鼭 ��Ʈ�������� ���� ������
			string str;
			cin >> str;
			auto it = cur->next.find(str);
			if(it == cur->next.end()) cur = cur->next[str] = new Tree; // �������� ������ ���� ����
			else cur = it->second; // �̹� �����ϸ� �� ������ ����
		}
	}
	dfs(root);
}

// ���� �ڵ�
/*int n,k,t;
string a[1010][20];
string chk;
void my_sort(int l,int r,int lev){
    for(int i=l;i<r;i++){
        for(int j=i+1;j<=r;j++){
            int res = a[i][lev].compare(a[j][lev]);
            if(a[i][lev].size() == 0) res = 1;
            else if(a[j][lev].size() == 0) res = 0;
            if(res == 1) swap(a[i],a[j]); // i��°�� ������ ��
            //for(int i=1;i<=n;i++) cout << "[" << a[i][lev] << a[i][lev].size() << "]";
            //puts("");
        }
    }
    return;
}

void f(int lev){ for(int i=1;i<lev;i++) cout << "--"; }

void solve(int l,int r,int lev){
    if(l>r || lev>16) return;
    my_sort(l,r,lev);
    chk = "";
    for(int i=l;i<=r;i++){
        if(chk.compare(a[i][lev])){
            solve(l,i-1,lev+1); l = i;
            chk = a[i][lev];
            if(chk.size()==0) return;
            f(lev); cout << chk << "\n";
        }
    }
    if(chk.size()) solve(l,r,lev+1);
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> k;
        for(int j=1;j<=k;j++) cin >> a[i][j];
    }
    solve(1,n,1);
    return 0;
}
*/
