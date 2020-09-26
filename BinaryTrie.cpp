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

class BTrie {

  vector <vector<int>> trie;
  vector <int> cnt;
  int counter;
  
  public :
    
    BTrie() {
      trie.resize(1000001, vector<int> (2, 0));
      cnt.resize(1000001, 0);
      counter = 1;
    }
    
    void Insert(int x) {
      int u = 0;
      for (int i = 30; ~i; --i) {
        int bit = (x >> i) & 1;
        if (!trie[u][bit])
          trie[u][bit] = counter++;
        u = trie[u][bit];
        cnt[u]++;
      }
    }
    
    bool Find(int x) {
      int u = 0;
      for (int i = 30; ~i; --i) {
        int bit = (x >> i) & 1;
        u = trie[u][bit];
        if (!cnt[u])
          return false;
      }
      return true;
    }
    
    void Remove(int x) {
      if (!Find(x))
        return ;
      int u = 0;
      for (int i = 30; ~i; --i) {
        int bit = (x >> i) & 1;
        u = trie[u][bit];
        cnt[u]--;
      }
    }
    
    int GetMin(int x) {
      int u = 0, ans = 0;
      for (int i = 30; ~i; --i) {
        int bit = (x >> i) & 1;
        if (cnt[trie[u][bit]]) {
          u = trie[u][bit];
        } else {
          ans += (1 << i);
          u = trie[u][bit ^ 1];
        }
      }
      return ans;
    }
    
    int GetMinCount(int x) {
      int u = 0;
      for (int i = 30; ~i; --i) {
        int bit = (x >> i) & 1;
        if (cnt[trie[u][bit]]) {
          u = trie[u][bit];
        } else {
          u = trie[u][bit ^ 1];
        }
      }
      return cnt[u];
    }
    
    int GetMax(int x) {
      int u = 0, ans = 0;
      for (int i = 30; ~i; --i) {
        int bit = (x >> i) & 1;
        if (cnt[trie[u][bit ^ 1]]) {
          ans += (1 << i);
          u = trie[u][bit];
        } else {
          u = trie[u][bit];
        }
      }
      return ans;
    }
    
    int GetMaxCount(int x) {
      int u = 0;
      for (int i = 30; ~i; --i) {
        int bit = (x >> i) & 1;
        if (cnt[trie[u][bit ^ 1]]) {
          u = trie[u][bit];
        } else {
          u = trie[u][bit];
        }
      }
      return cnt[u];
    }

};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
