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

class rmq {
  vector <vector <int>> dp;
  vector <int> lg, p;
  int n, l;
  public :
    rmq(int _n) : n(_n) {
      int l = 0;
      while ((int(1) << (l + 1)) <= n)
        l++;
      dp.resize(n, vector <int> (l + 1, 0));
      lg.resize(n + 1, 0);
      p.resize(l + 1, 0);
      p[0] = 1;
      for (int i = 1; i <= l; i++)
        p[i] = p[i - 1] * 2;
      for (int i = 1; i <= n; i++) {
        lg[i] = lg[i - 1];
        while ((int(1) << (lg[i] + 1)) <= i)
          lg[i]++;
      }
    }
    
    void build_max(vector <int>& a) {
      for (int i = 0; i < n; i++)
        dp[i][0] = a[i];
      for (int x = 1; (int(1) << x) <= n; x++)
        for (int i = 0; i + (1 << x) <= n; i++)
          dp[i][x] = max(dp[i][x - 1], dp[i + (int(1) << (x - 1))][x - 1]);
    }
    
    void build_min(vector <int>& a) {
      for (int i = 0; i < n; i++)
        dp[i][0] = a[i];
      for (int x = 1; (1 << x) <= n; x++)
        for (int i = 0; i + (int(1) << x) <= n; i++)
          dp[i][x] = min(dp[i][x - 1], dp[i + (int(1) << (x - 1))][x - 1]);
    }
    
    int get_max(int l, int r) {
      assert(l <= r && l >= 0 && r < n);
      return max(dp[l][lg[r - l + 1]], dp[r - p[lg[r - l + 1]] + 1][lg[r - l + 1]]);
    }
    
    int get_min(int l, int r) {
      assert(l <= r && l >= 0 && r < n);
      return min(dp[l][lg[r - l + 1]], dp[r - p[lg[r - l + 1]] + 1][lg[r - l + 1]]);
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
