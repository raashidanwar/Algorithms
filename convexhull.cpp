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

struct point {
  int x, y;
  point(int _x, int _y) : x(_x), y(_y) {}
};

class convexhull {
  vector <point> hull;
  public :
    convexhull() {
      hull.clear();
    }
    
    bool is_bad(point a, point b, point c) {
      return double(b.y - c.y) / double((a.y - b.y)) <= double(c.x - b.x) / double(b.x - a. x);
    }
    
    void addline(int x, int y) {
      point p = {x, y};
      while ((int)hull.size() > 1 && is_bad(hull[(int)hull.size() - 2], hull.back(), p))
        hull.pop_back();
      hull.push_back(p);
    }
    
    int get_max(int x) {
      point p = {x, 1};
      int lo = -1, hi = (int)hull.size() - 1;
      while (hi - lo > 1) {
        int mi = (lo + hi) >> 1;
        if (x * hull[mi].x + hull[mi].y <= x * hull[mi + 1].x + hull[mi + 1].y) {
          lo = mi;
        } else {
          hi = mi;
        }
      }
      return (x * hull[hi].x + hull[hi].y);
    }
    
    void clear() {
      hull.clear();
    }
};

void solve() {
  
}

 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
