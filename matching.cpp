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

class matching {
  vector <vector <int>> node;
  vector <int> left, right, vis;
  int n, m;
  public :
    matching(int _n, int _m) : n(_n), m(_m) {
      node.resize(n);
      left.resize(n, -1);
      right.resize(m, -1);
      vis.resize(n);
    }
    
    void add(int u, int v) {
      node[u].push_back(v);
    }
    
    bool match(int u) {
      if (vis[u])
        return false;
      vis[u] = 1;
      for (int v : node[u])
        if (right[v] == -1) {
          left[u] = v;
          right[v] = u;
          return true;
        }
      for (int v : node[u])
        if(match(right[v])) {
          left[u] = v;
          right[v] = u;
          return true;
        }
      return false;
    }
    
    void find_match() {
      int ok = 1;
      while (ok--) {
        for (int i = 0; i < n; i++)
          vis[i] = 0;
        for (int i = 0; i < n; i++)
          if (left[i] == -1)
            ok |= match(i);
      }
    }
    
    int max_match() {
      int tot_match = 0;
      for (int i = 0; i < n; i++)
        tot_match += (left[i] != -1);
      return tot_match;
    }
    
    bool is_perfect() {
      for (int i = 0; i < n; i++)
        if (left[i] == -1)
          return false;
      return true;
    }
    
    int find_left_match(int u) {
      return right[u];
    }
    
    int find_right_match(int u) {
      return left[u];
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
