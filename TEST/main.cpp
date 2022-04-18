#include<iostream>

using namespace std;

string in[26];
int ans[30], chk[30], dp[30], num, n;

int check(int m) {
   int ans1 = 0;
   for (int i = 0; i < m; i++) {
      if (dp[ans[i]]) ans1 = ans1 | dp[ans[i]];
      else {
         int ans2 = 0,nn = in[ans[i] - 1].length();
         for (int j = 0; j < nn; j++)
            ans2 = ans2 | (1 << (in[ans[i] - 1][j] - 'a'));
         dp[ans[i]] = ans2;
         ans1 |= ans2;
      }
   }
   if (ans1 == (1<<26)-1) return 1;
   else return 0;
}

void f(int ind, int st) {
   num += check(ind);
   for (int i = st; i <= n; i++) {
      if (chk[i]) continue;
      chk[i]++;
      ans[ind] = i;
      f(ind + 1, i + 1);
      ans[ind] = 0;
      chk[i]--;
   }
}

int main() {
   cin >> n;
   for (int i = 0; i < n; i++) cin >> in[i];
   
   f(0, 1);
   
   cout << num;
}