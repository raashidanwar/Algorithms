#include <bits/stdc++.h>
using namespace std;

int root[100001];
int size[100001];

void swap(int *a,int *b) {
	int temp=*a;*a=*b;*b=temp;
}

int find(int i) {
	while(i!=root[i]) {
		root[i]=root[root[i]];
		i=root[i];
	}
	return i;
}

void weight_union(int x,int y) {
	size[x]+=size[y];
	root[y]=root[x];
}

int main() {
	int N,x,y;
	cin>>N;
	for(int i=1;i<=N;i++ ) {
		root[i]=i;
		size[i]=1;
	}
	for(int i=1;i<=N;i++ ) {
		cin>>x>>y;
		x=find(x);y=find(y);
		if(x!=y) {
			if(size[x]<size[y])
				swap(&x,&y);
			weight_union(x,y);
		}
	}
}
