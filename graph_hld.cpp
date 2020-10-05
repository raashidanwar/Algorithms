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

class graph_hld {
  vector <vector <int>> node, pi;
  vector <int> l, sz, root, pos, tree, lazy, value;
  int n, time_stamp = 0;
  public :
    graph_hld(int _n) : n(_n) {
      node.resize(n);
      l.resize(n);
      root.resize(n);
      pos.resize(n);
      value.resize(n);
      sz.resize(n, 1);
      tree.resize(4 * n + 11, 0);
      lazy.resize(4 * n + 11, 0);
      pi.resize(n, vector <int> (21, 0));
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
          sz[u] += sz[v];
        }
    }
    
    void dfs() {
      dfs(0);
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
    
    void hld(int u, int r) {
      int ui = -1, max_sz = 0;
      root[u] = r;
      pos[u] = time_stamp++;
      for (int v : node[u])
        if (v != pi[u][0])
          if (sz[v] > max_sz) {
            ui = v;
            max_sz = sz[v];
          }
      if (ui != -1)
        hld(ui, r);
      for (int v : node[u])
        if (v != pi[u][0] && v != ui)
          hld(v, v);
    }
    
    void hld_upd(int u, int x) {
      value[u] = x;
      upd(pos[u], x);
    }
    
    void hld_lazy_upd(int u, int v, int x) {
      if (l[root[u]] > l[root[v]])
        swap(u, v);
      if (root[u] == root[v]) {
        lazy_upd(min(pos[u], pos[v]), max(pos[u], pos[v]), x);
      } else {
        lazy_upd(pos[root[v]], pos[v], x);
        hld_lazy_upd(u, pi[root[v]][0], x);
      }
    }
    
    int seg_qry(int u, int v) {
      if (l[root[u]] > l[root[v]])
        swap(u, v);
      if (root[u] == root[v]) {
        return get_sum(min(pos[u], pos[v]), max(pos[u], pos[v]));
      } else {
        return get_sum(pos[root[v]], pos[v]) + seg_qry(u, pi[root[v]][0]);
      }
    }
    
    int query(int u, int v) {
      int lca = get_lca(u, v);
      return seg_qry(u, lca) + seg_qry(v, lca) - value[lca];
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
      if (l > r) {
        return 0;
      } else {
        return get_sum(1, 1, n, l, r);
      }
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
