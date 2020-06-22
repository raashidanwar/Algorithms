/*
  In the name of ALLAH
  authon : Raashid Anwar
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;
const int N = 1000005;
 
class Manachers {
  int start, end;
  vector <int> table;
  public :
    string LongestPlaindrome(string s) {
      int n = s.size();
      n += n + 1;
      this->table.resize(n);
      table[1] = 1;
      int R = 2, C = 1, index = 0;
      for(int i = 2; i < n; i++) {
        if(R - i > 0)
          this->table[i] = min(this->table[2 * C - i], R - i);
        while(((i + this->table[i]) < n) && ((i - this->table[i]) > 0)) { 
          if(!((i + this->table[i] + 1) & 1) || (s[(i + this->table[i] + 1)/2] == s[(i - this->table[i] - 1)/2]))
            this->table[i]++;
          else
            break;
        }
        if(this->table[i] > this->table[index])
          index = i;
        if(i + this->table[i] > R) {
          C = i;
          R = i + this->table[i];
        }
      }
      this->start = (index - table[index]) / 2;
      this->end = start + table[index] - 1;
      return s.substr(start, end - start + 1);
    };
    pair <int, int> getindex() {
      return {this->start, this->end};
    };
    vector <int> gettable() {
      return this->table;
    }
};
 
void solve() {
  string s;
  cin >> s;
  Manachers* M = new Manachers();
  cout << M->LongestPlaindrome(s) << "\n";
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
