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
  

class seg_tree {
  int n;
  vector <int> tree, lazy;
  public :
    seg_tree(int _n) : n(_n) {
      tree.resize(n * 4 + 11, 0);
      lazy.resize(n * 4 + 11, 0);
    }
    
    void upd(int n, int s, int e, int i, int x) {
      if (s == e) {
        tree[n] = x;
      } else {
        int m = (s + e) >> 1;
        if (i <= m) {
          upd(n << 1, s, m, i, x);
        } else {
          upd(n << 1 | 1, m + 1, e, i, x);
        }
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
      }
    }
    
    void upd(int i, int x) {
      upd(1, 1, n, i, x);
    }
    
    int get_sum(int n, int s, int e, int l, int r) {
      if (s > e || s > r || e < l)
        return 0;
      if (lazy[n])
        shift(n, s, e);
      if (l <= s && e <= r)
        return tree[n];
      int m = (s + e) >> 1;
      return get_sum(n << 1, s, m, l, r) + get_sum(n << 1 | 1, m + 1, e, l, r);
    }
    
    int get_sum(int l, int r) {
      assert(l <= r && l >= 1 && r <= n);
      return get_sum(1, 1, n, l, r);
    }
    
    void shift(int n, int s, int e) {
      tree[n] += (e - s + 1) * lazy[n];
      if (s != e) {
        lazy[n << 1] += lazy[n];
        lazy[n << 1 | 1] += lazy[n];
      }
      lazy[n] = 0;
    }
    
    void lazy_upd(int n, int s, int e, int l, int r, int x) {
      if (lazy[n])
        shift(n, s, e);
      if (s > e || s > r || e < l)
        return ;
      if (l <= s && e <= r) {
        lazy[n] = x;
        shift(n, s, e);
        return ;
      }
      int m = (s + e) >> 1;
      lazy_upd(n << 1, s, m, l, r, x);
      lazy_upd(n << 1 | 1, m + 1, e, l, r, x);
      tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
    
    void lazy_upd(int l, int r, int x) {
      assert(l <= r && l >= 1 && r <= n);
      lazy_upd(1, 1, n, l, r, x);
    }
};


void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
