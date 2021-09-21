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

class tree {
  vector<vector<int>> node;
  vector<vector<int>> pi;
  vector <int> l;
  int n;
  public :
    tree(int _n) : n(_n) {
      node.resize(n);
      l.resize(n, 0);
      pi.resize(n, vector<int> (21, 0));
    }
    
    void add(int u, int v) {
      node[u].push_back(v);
      node[v].push_back(u);
    }
    
    void dfs(int u) {
      for (int v : node[u])
        if (v != pi[u][0]) {
          l[v] = l[u] + 1;
          pi[v][0] = u;
          dfs(v);
        }
    }
    
    void dfs() {
      dfs(0);
      for (int i = 1; i <= 20; i++)
        for (int u = 0; u < n; u++)
          pi[u][i] = pi[pi[u][i - 1]][i - 1];
    }
    
    void bfs() {
      queue <int> q;
      q.push(0);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : node[u])
          if (v != pi[u][0]) {
            l[v] = l[u] + 1;
            pi[v][0] = u;
            q.push(v);
          }
      }
      for (int i = 1; i <= 20; i++)
        for (int u = 0; u < n; u++)
          pi[u][i] = pi[pi[u][i - 1]][i - 1];
    }
    
    int get_lca(int u, int v) {
      if (l[v] > l[u])
        swap(u, v);
      for (int i = 20; ~i; --i)
        if (l[u] - l[v] >= (1 << i))
          u = pi[u][i];
      if (u == v)
        return u;
      for (int i = 20; ~i; --i)
        if (pi[u][i] != pi[v][i]) {
          u = pi[u][i];
          v = pi[v][i];
        }
      return pi[u][0];
    }
    
    int get_diameter(int u, int& d) {
      int x = 0;
      for (int v : node[u])
        if (v != pi[u][0]) {
          pi[v][0] = u;
          l[v] = l[u] + 1;
          int y = get_diameter(v, d);
          d = max(d, x + y + 1);
          x = max(x, y);
        }
      return x + 1;
    }
    
    int diameter() {
      int d = 0;
      get_diameter(0, d);
      return d;
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
