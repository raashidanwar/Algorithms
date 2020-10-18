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

class manacher {
  int start, end;
  vector <int> table;
  string s;
  public :
    manacher(string _s) : s(_s) {
      int n = s.size();
      n += n + 1;
      table.resize(n);
      table[1] = 1;
      int R = 2, C = 1, index = 0;
      for(int i = 2; i < n; i++) {
        if(R - i > 0)
          table[i] = min(table[2 * C - i], R - i);
        while(((i + table[i]) < n) && ((i - table[i]) > 0)) { 
          if(!((i + table[i] + 1) & 1) || (s[(i + table[i] + 1)/2] == s[(i - table[i] - 1)/2]))
            table[i]++;
          else
            break;
        }
        if(table[i] > table[index])
          index = i;
        if(i + table[i] > R) {
          C = i;
          R = i + table[i];
        }
      }
      start = (index - table[index]) / 2;
      end = start + table[index] - 1;
    }
    
    string longest_palindrome() {
      return s.substr(start, end - start + 1);
    }
    
    pair <int, int> getindex() {
      return {start, end};
    }
  
    vector <int> gettable() {
      return table;
    }
};

void solve() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
