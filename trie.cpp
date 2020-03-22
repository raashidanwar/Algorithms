/* 
  In the name of ALLAH
  Author : Raashid Anwar
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int    int64_t
const int MOD = 1000000007;

int trie[200001][26];
int cnt[200001];
int m=1;

void insert(string s) {
  int u=0;
  for(auto d : s) {
    if(!trie[u][d-'a'])
      trie[u][d-'a']=m++;
    u=trie[u][d-'a'];
  }
  cnt[u]++;
}

bool get(string s) {
  int u=0;
  for(auto d : s) {
    if(!trie[u][d-'a'])
      return false;
    u=trie[u][d-'a'];
  }
  return (cnt[u]>0);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  string s;
  m=1;
  for(int i=1;i<=n;i++) {
    cin>>s;
    insert(s);
  }
  cin>>s;
  if(get(s))
    cout<<"yes\n";
  else
    cout<<"no\n";
}
