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

class link_cut {
  struct node {
    int p = 0, pp = 0, val = 0, dp = 0, flip = 0;
    vector <int> c = {0, 0};
  };
  vector <node> T;
  public:
    link_cut(int n) {
      T.resize(n + 1);
    }
    
    int dir(int x, int y) {
      return T[x].c[1] == y;
    }
    
    void set(int x, int d, int y) {
      if (x) {
        T[x].c[d] = y;
        pull(x);
      }
      if (y) {
        T[y].p = x;
      }
    }
    
    void pull(int x) {
      if (x) {
        T[x].dp = max({T[x].val, T[T[x].c[0]].dp, T[T[x].c[1]].dp});
      }
    }
    
    void push(int x) {
      if (x && T[x].flip) {
        int &l = T[x].c[0], &r = T[x].c[1];
        swap(l, r);
        T[l].flip ^= 1;
        T[r].flip ^= 1;
        T[x].flip = 0;
      }
    }
    
    void rotate(int x, int d) {
      int y = T[x].p, z = T[y].p, w = T[x].c[d];
      swap(T[x].pp, T[y].pp);
      set(y, !d, w);
      set(x, d, y);
      set(z, dir(z, y), x);
    }
    
    void splay(int x) {
      for (push(x); T[x].p;) {
        int y = T[x].p, z = T[y].p;
        push(z); push(y); push(x);
        int dx = dir(y, x), dy = dir(z, y);
        if (!z) {
          rotate(x, !dx); 
        } else if (dx == dy) {
          rotate(y, !dx), rotate(x, !dx); 
        } else {
          rotate(x, dy), rotate(x, dx);
        }
      }
    }
    
    void make_root(int u) {
      access(u);
      int l = T[u].c[0];
      T[l].flip ^= 1;
      swap(T[l].p, T[l].pp);
      set(u, 0, 0);
    }
   
    void access(int _u) {
      for (int v = 0, u = _u; u; u = T[v = u].pp) {
        splay(u); splay(v);
        int r = T[u].c[1];
        T[v].pp = 0;
        swap(T[r].p, T[r].pp);
        set(u, 1, v);
      }
      splay(_u);
    }

    void link(int u, int v) {
      assert(!connected(u, v));
      make_root(v);
      T[v].pp = u;
    }

    void cut(int u, int v) {
      make_root(u); access(u); splay(v);
      assert(T[v].pp == u);
      T[v].pp = 0;
    }

    bool connected(int u, int v) {
      if (u == v) return true;
      make_root(u); access(v); splay(u);
      return T[v].p == u || T[T[v].p].p == u;
    }

    int get_path(int u, int v) {
      make_root(u);
      access(v);
      return v;
    }
    
    int find_root(int u) {
      access(u);
      for (; T[u].c[0]; u = T[u].c[0]);
      access(u);
      return u;
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
