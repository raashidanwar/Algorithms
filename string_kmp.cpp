/*
  In the name of ALLAH
  Author : Raashid Anwar
*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());

class string_kmp {
  int n;
  vector <int> lsp;
  string p;
  public :
    string_kmp(int _n, const string& p): n(_n), p(p) {
      lsp.resize(n, 0);
      for (int i = 1, l = 0; i < n; i++) {
        while (l && p[i] != p[l]) {
          l = lsp[l - 1];
        }
        if (p[i] == p[l]) {
          lsp[i] = ++l;
        }
      }
    }
    
    bool is_found(const string& s) {
      int m = s.size() - 1;
      for (int i = 0, j = 0; i < m; i++) {
        while (j && s[i] != p[j]) {
          j = lsp[j - 1];
        }
        if(s[i] == p[j]) {
          if (++j == n) {
            return true;
          }
        }
      }
      return false;
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
