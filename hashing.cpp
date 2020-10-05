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

class string_hash {
  vector <int> Hash;
  vector <int> np, ip;
  int n, M;
  public :
    string_hash(string s, int _M) : M(_M) {
      n = (int)s.size();
      Hash.resize(n + 1, 0);
      np.resize(n + 1, 1);
      ip.resize(n + 1, 1);
      
      for (int i = 1; i <= n; i++) {
        np[i] = (np[i - 1] * 131) % M;
        ip[i] = mpow(np[i], M - 2);
      }
      
      for (int i = 1; i <= n; i++) {
        Hash[i] = (Hash[i - 1] + (np[i - 1] * (s[i - 1] - 'a')) % M) % M;
      }
    }
    
    int mpow(int a, int b) {
      int r = 1;
      while (b) {
        if (b & 1)
          r = (r * a) % M;
        a = (a * a) % M;
        b >>= 1;
      }
      return r;
    }
    
    int get_hash(int l, int r) {
      return (((Hash[r + 1] - Hash[l] + M) % M) * ip[l]) % M;
    }
    
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
