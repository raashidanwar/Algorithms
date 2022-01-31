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


class heap {
  vector <int> a;
  public:
    heap() {
      a.clear();
    }
    
    push(int x) {
      a.push_back(x);
      int i = (int)a.size() - 1;
      while (i != 0 && a[(i - 1) >> 1] > a[i]) {
        swap(a[(i - 1) >> 1], a[i]);
        i = (i - 1) >> 1;
      }
    }
    
    void heapify(int i) {
      int min_index = i;
      if (i + i + 1 < (int)a.size() && a[i + i + 1] < a[min_index])
        min_index = i + i + 1;
      if (i + i + 2 < (int)a.size() && a[i + i + 2] < a[min_index])
        min_index = i + i + 2;
      if (min_index != i) {
        swap(a[i], a[min_index]);
        heapify(min_index);
      }
    }
    
    int top() {
      assert(!a.empty());
      return a[0];
    }
    
    pop() {
      assert(!a.empty());
      if ((int)a.size() == 1) {
        a.pop_back();
      } else {
        a[0] = a.back();
        a.pop_back();
        heapify(0);
      }
    }
    
    bool empty() {
      return a.empty();
    }
    
    int size() {
      return (int)a.size();
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}




















































