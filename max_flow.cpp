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

struct flow_edge {
  int u, v, cap, flow = 0;
  flow_edge(int _u, int _v, int _cap) : u(_u), v(_v), cap(_cap) {}
};

class dinic {
  vector <vector <int>> node;
  vector <flow_edge> edges;
  vector <int> level, ptr;
  int n, s, t;
  const int inf_flow = 1e18;
  public :
    dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
      node.resize(n);
      level.resize(n);
      ptr.resize(n);
    }
    
    void add(int u, int v, int cap) {
      node[u].push_back((int)edges.size());
      edges.push_back({u, v, cap});
      node[v].push_back((int)edges.size());
      edges.push_back({v, u, 0});
    }
    
    bool bfs() {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      queue <int> q;
      q.push(s);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : node[u]) {
          if (edges[i].cap <= edges[i].flow || level[edges[i].v] != -1)
            continue;
          level[edges[i].v] = level[u] + 1;
          q.push(edges[i].v);
        }
      }
      return level[t] != -1;
    }
    
    int dfs(int u, int tot_flow) {
      if (!tot_flow || u == t)
        return tot_flow;
      for(; ptr[u] < (int)node[u].size(); ptr[u]++) {
        int i = node[u][ptr[u]];
        int v = edges[i].v;
        if (level[u] + 1 != level[v] || edges[i].cap <= edges[i].flow)
          continue;
        int flow = dfs(v, min(tot_flow, edges[i].cap - edges[i].flow));
        if (!flow)
          continue;
        edges[i].flow += flow;
        edges[i ^ 1].flow -= flow;
        return flow;
      }
      return 0;
    }
    
    int max_flow() {
      int tot_flow = 0;
      while (bfs()) {
        fill(ptr.begin(), ptr.end(), 0);
        int flow;
        while (flow = dfs(s, inf_flow))
          tot_flow += flow;
      }
      return tot_flow;
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
