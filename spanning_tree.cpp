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
  public :
    dsu(int _n) : n(_n) {
      root.resize(n);
      sz.resize(n);
      for (int i = 0; i < n; i++) {
        root[i] = i;
        sz[i] = 1;
      }
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
      if (sz[v] > sz[v])
        swap(u, v);
      root[v] = u;
      sz[u] += sz[v];
    }
    
    int total_comp() {
      vector <int> mark(n, 0);
      int tot_component = 0;
      for (int i = 0; i < n; i++) {
        int u = get_root(i);
        if (!mark[u])
          tot_component++;
        mark[u] = 1;
      }
      return tot_component;
    }
    
    int comp_size(int u) {
      u = get_root(u);
      return sz[u];
    }
    
    int max_size_comp() {
      int max_sz = 0;
      for (int i = 0; i < n; i++)
        max_sz = max(max_sz, sz[get_root(i)]);
      return max_sz;
    }

};


/*
   you need to add dsu also
*/

class graph_mst {
  int n;
  vector <tuple<int, int, int>> edges;
  vector <vector<pair<int, int>>> node;
  public :
    graph_mst(int _n) : n(_n) {
      node.resize(n);
    }
    
    void add(int u, int v, int cost) {
      edges.push_back({cost, u, v});
      node[u].push_back({v, cost});
      node[v].push_back({u, cost});
    }
    
    int max_st() {
      sort(edges.begin(), edges.end(), [&](auto ex, auto ey) {
        auto [costx, ux, vx] = ex;
        auto [costy, uy, vy] = ey;
        return costx > costy;
      });
      
      //used dsu class
      dsu d(n);
      
      int tot_cost = 0;
      for (auto [cost, u, v] : edges) {
        if (!d.connected(u, v)) {
          d.merge(u, v);
          tot_cost += cost;
        }
      }
      return tot_cost;
    }
    
    int min_st() {
      sort(edges.begin(), edges.end());
      
      //used dsu class
      dsu d(n);
      
      int tot_cost = 0;
      for (auto [cost, u, v] : edges) {
        if (!d.connected(u, v)) {
          d.merge(u, v);
          tot_cost += cost;
        }
      }
      return tot_cost;
    }
};


void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
