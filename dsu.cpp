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

class dsu {
  int n;
  vector <int> root, sz;
  int comp;
  public :
    dsu(int _n) : n(_n) {
      root.resize(n);
      sz.resize(n, 1);
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
      if (sz[v] > sz[u])
        swap(u, v);
      root[v] = u;
      sz[u] += sz[v];
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
