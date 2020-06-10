/*
  In the name of ALLAH
  Author : Raashid Anwar
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;

int in[100001];
int lw[100001];
int vis[100001];
vector <int> adj[100001];
int ti;

void dfs(int u, int p) {
  vis[u] = 1;
  lw[u] = in[u] = ti++;
  for(int &v : adj[u]) {
    if(v ^ p) {
      if(vis[v])
        lw[u] = min(lw[u], in[v]);
      else {
        dfs(v, u);
        lw[u] = min(lw[u], lw[v]);
        if(in[u] < lw[v])
          cout << u << ", " << v << "\n";
      }
    }
  }
}
 
void solve() {
  int n, m, u, v;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    adj[i].clear();
  for(int i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  fill(vis + 1, vis + n + 1, 0);
  fill(lw + 1, lw + n + 1, -1);
  fill(in + 1, in + n + 1, -1);
  ti = 0;
  for(int i = 1; i <= n; i++)
    if(!vis[i])
      dfs(i, 0);
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--)
    solve();
}
