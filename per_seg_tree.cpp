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
    
    struct node* build(int s, int e, vector <int> &a) {
      if (s == e) {
        struct node* new_node = new node(a[s - 1]);
        return new_node;
      } else {
        int m = (s + e) >> 1;
        struct node* new_node = new node(1);
        new_node->left = build(s, m, a);
        new_node->right = build(m + 1, e, a);
        new_node->x = (new_node->left->x * new_node->right->x) % M2;
        return new_node;
      }
    }
    
    struct node* upd(struct node* ni, int s, int e, int i, int x) {
      if (s == e) {
        struct node* new_node = new node(x);
        return new_node;
      } else {
        int m = (s + e) >> 1;
        struct node* new_node = new node(1);
        if (i <= m) {
          new_node->left = upd(ni->left, s, m, i, x);
          new_node->right = ni->right;
        } else {
          new_node->right = upd(ni->right, m + 1, e, i, x);
          new_node->left = ni->left;
        }
        new_node->x = (new_node->left->x * new_node->right->x) % M2;
        return new_node;
      }
    }
    
    struct node* upd(struct node* ni, int i, int x) {
      return upd(ni, 1, n, i, x);
    }
    
    int get(struct node* ni, int s, int e, int l, int r) {
      if (s > e || s > r || e < l)
        return 1;
      if (l <= s && e <= r)
        return ni->x;
      int m = (s + e) >> 1;
      return (get(ni->left, s, m, l, r) * get(ni->right, m + 1, e, l, r)) % M2;
    }
    
    int get(struct node* ni, int l, int r) {
      if (l > r) {
        return 1;
      } else {
        return get(ni, 1, n, l, r);
      }
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
