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

class graph {
  vector <vector <int>> node;
  vector <pair<int, int>> bridges;
  vector <int> in, out, low, vis;
  int n, time_stamp;
  public :
    graph(int _n) : n(_n) {
      node.resize(n);
      in.resize(n);
      out.resize(n);
      low.resize(n);
      vis.resize(n);
      time_stamp = 0;
    }
    
    void add(int u, int v) {
      node[u].push_back(v);
      node[v].push_back(u);
    }
    
    void find_bridges(int u, int p) {
      in[u] = low[u] = ++time_stamp;
      vis[u] = 1;
      for (int v : node[u]) {
        if (!vis[v]) {
          find_bridges(v, u);
          low[u] = min(low[u], low[v]);
          if (low[v] > in[u])
            bridges.push_back({u, v});  
        }
        if (p != v)
          low[u] = min(low[u], in[v]);
      }
      out[u] = ++time_stamp;
    }
    
    bool check_cycle(int u, int p) {
      if (vis[u])
        return true;
      vis[u] = true;
      for (int v : node[u])
        if (v != p)
          if (check_cycle(v, u))
            return true;
      return false;
    }
    
    bool is_cycle() {
      fill(vis.begin(), vis.end(), 0);
      for (int u = 0; u < n; u++) {
        if (vis[u] == 0 && check_cycle(u, -1))
          return true;
      }
      return false;
    }
    
    vector <pair<int, int>> get_bridges() {
      bridges.clear();
      find_bridges(0, -1);
      return bridges;
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
