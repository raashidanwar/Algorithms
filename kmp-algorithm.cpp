#include <bits/stdc++.h>
using namespace std;

void lsp_calculation(string patt,vector<int> &lsp) {
	int i=1,l=0;
	int M=patt.length();
	lsp[0]=0;
	for(;i<M;i++ ) {
		if(patt[i]==patt[l])
			lsp[i++]=++l;
		else {	
			if(l!=0)
				l=lsp[l-1];
			else
				lsp[i]=0,i++;
		}
	}
}

void search_pattern(string str,string patt,vector <int> lsp) {
	int i=0,j=0;
	int N=str.length();
	int M=patt.length();
	while(i<N) {
		if(patt[j]==str[i])
			i++,j++;
		if(j==M) {
			cout<<"pattern found at : "<<i-M<<endl;
			j=lsp[j-1];
		}
		else if(i<N&&patt[j]!=str[i]) {
			if(j!=0)
				j=lsp[j-1];
			else
				i++;
		}
	}
}

int main() {
	string str,patt;
	cin>>str>>patt;
	vector <int> lsp(patt.length());
	lsp_calculation(patt,lsp);
	search_pattern(str,patt,lsp);
}
