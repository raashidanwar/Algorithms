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

class dsu_rollback {
  int n;
  vector <int> root, rnk;
  stack <tuple <int, int, int, int>> ops;
  int comp;
  public :
    dsu_rollback(int _n) : n(_n) {
      root.resize(n);
      rnk.resize(n);
      iota(root.begin(), root.end(), (int)0);
      comp = n;
    }
    
    int get_root(int u) {
      return (u == root[u]? u: (root[u] = get_root(root[u])));
    }
    
    bool connected(int u, int v) {
      if (get_root(u) == get_root(v))
        return true;
      return false;
    }
    
    void merge(int u, int v) {
      if (connected(u, v))
        return ;
      u = get_root(u);
      v = get_root(v);
      comp--;
      ops.push({u, rnk[u], v, rnk[v]});
      if (rnk[v] > rnk[u])
        swap(u, v);
      root[v] = u;
      rnk[u] += (rnk[u] == rnk[v]);
    }
    
    void rollback() {
      if (!ops.empty()) {
        int u, rnk_u, v, rnk_v;
        tie(u, rnk_u, v, rnk_v) = ops.top();
        ops.pop();
        rnk[u] = rnk_u;
        root[u] = u;
        rnk[v] = rnk_v;
        root[v] = v;
      }
    }
    
    int components() {
      return comp;
    }
};


void solve() {
  
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
