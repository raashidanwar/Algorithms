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

class math {
  public :
    int to_int(const string &s) {
      int sign = 1, i = 0, ans = 0;
      if (!(s[0] >= '0' && s[0] <= '9')) {
        sign = (s[0] == '-'? -1: 1);
        i = 1;
      }
      
      while (i < (int)s.size())
        ans = (ans * 10 + s[i++] - '0');

      ans *= sign;
      return ans;
    }
    
    int get_val(const string& s) {
      int n = s.size();
      for (int i = 0; i < n; i++)
        if (s[i] == '-' && i && s[i - 1] >= '0' && s[i - 1] <= '9')
          return get_val(s.substr(0, i)) - get_val(s.substr(i + 1, n - i - 1)); 
      
      for (int i = 0; i < n; i++)
        if (s[i] == '+')
          return get_val(s.substr(0, i)) + get_val(s.substr(i + 1, n - i - 1)); 
      
      for (int i = 0; i < n; i++)
        if (s[i] == '*')
          return get_val(s.substr(0, i)) * get_val(s.substr(i + 1, n - i - 1));
      
      for (int i = 0; i < n; i++)
        if (s[i] == '/')
          return get_val(s.substr(0, i)) / get_val(s.substr(i + 1, n - i - 1)); 

      return to_int(s);
    }
    
    string evaluate(const string& s) {
      int n = s.size();
      for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == ')')
          return s.substr(0, j) + to_string(get_val(s.substr(j + 1, i - j - 1))) + s.substr(i + 1, n - i - 1);
        if (s[i] == '(')
          j = i;
      }
      return to_string(get_val(s));
    }
};

void solve() {
  math a;
  string s;
  cin >> s;
  cout << a.evaluate(s) << "\n";
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
