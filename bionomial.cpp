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

int mpow(int a, int b, int M) {
  int r = 1;
  while (b) {
    if (b & 1)
      r = (r * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return r;
}

class bionomial {
  int n, MOD;
  vector <int> fact, inv;
  public :
    bionomial(int _n, int _MOD) : n(_n), MOD(_MOD) {
      fact.resize(n + 1, 1);
      inv.resize(n + 1, 1);
      
      for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
        
      inv[n] = mpow(fact[n], MOD - 2, MOD);
      for (int i = n - 1; ~i; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }
    
    int nCr(int _n, int _m) {
      if (_n < 0 || _n > n || _m < 0 || _m > _n) {
        return 0;
      } else {
        return (((fact[_n] * inv[_m]) % MOD) * inv[_n - _m]) % MOD;
      }
    }
    
    int nPr(int _n, int _m) {
      if (_n < 0 || _n > n || _m < 0 || _m > _n) {
        return 0;
      } else {
        return (fact[_n] * inv[_n - _m]) % MOD;
      }
    }
    
    int get_fact(int _n) {
      if (_n < 0 || _n > n) {
        return 0;
      } else {
        return fact[_n];
      }
    }
    
    int get_inv(int _n) {
      if (_n < 0 || _n > n) {
        return 0;
      } else {
        return inv[_n];
      }
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
