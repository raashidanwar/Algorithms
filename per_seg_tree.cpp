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

struct node {
  int x;
  struct node *left, *right;
  node(int _x) : x(_x) {
    this->left = this->right = NULL;
  }
};

class per_seg_tree {
  int n;
  public :
    per_seg_tree(int _n) : n(_n) {}
    
    struct node* make_node(int x = 0, struct node* li = NULL, struct node* ri = NULL) {
      struct node* new_node = new node(x);
      new_node->left = li;
      new_node->right = ri;
      if (li != NULL)
        new_node->x += li->x;
      if (ri != NULL)
        new_node->x += ri->x;
      return new_node;
    }
    
    struct node* build(int s, int e) {
      if (s == e) {
        return make_node(0);
      } else {
        int m = (s + e) >> 1;
        return make_node(0, build(s, m), build(m + 1, e));
      }
    }
    
    struct node* upd(struct node* ni, int s, int e, int i, int x) {
      if (s == e) {
        return make_node(x);
      } else {
        int m = (s + e) >> 1;
        struct node* new_node = new node(0);
        if (i <= m) {
          return make_node(0, upd(ni->left, s, m, i, x), ni->right);
        } else {
          return make_node(0, ni->left, upd(ni->right, m + 1, e, i, x));
        }
      }
    }
    
    struct node* upd(struct node* ni, int i, int x) {
      return upd(ni, 0, n - 1, i, x);
    }
    
    int get(struct node* ni, int s, int e, int l, int r) {
      if (s > e || s > r || e < l)
        return 0;
      if (l <= s && e <= r)
        return ni->x;
      int m = (s + e) >> 1;
      return get(ni->left, s, m, l, r) + get(ni->right, m + 1, e, l, r);
    }
    
    int get(struct node* ni, int l, int r) {
      assert(l >= 0 && r < n && l <= r);
      return get(ni, 0, n - 1, l, r);
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
