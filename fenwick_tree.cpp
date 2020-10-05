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

class fenwick_tree {
  vector <int> tree;
  int n;
  public :
    fenwick_tree(int _n) : n(_n) {
      tree.resize(n + 1, 0);
    }
    
    void upd(int i, int x) {
      for (; i <= n; i += (i & -i))
        tree[i] += x;
    }
    
    int get(int i) {
      int sum = 0;
      for (; i; i -= (i & -i))
        sum += tree[i];
      return sum;
    }
    
    void clear() {
      tree.resize(n + 1, 0);
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
