/* 
		In the name of ALLAH
		Author : Raashid Anwar
*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int ix,N;

int mp[100001];
int pi[100001];
int seg[400004];
int wi[100001];
int hi[100001];
int A[100001];
int B[100001];
int dp[100001][21];

vector <int> adj[100001];

void upd(int n,int s,int e,int i,int x) {
	if(s==e)
		seg[n]=x;
	else {
		int m=(s+e)>>1;
		if(s<=i&&i<=m)
			upd(2*n,s,m,i,x);
		else
			upd(2*n+1,m+1,e,i,x);
		seg[n]=seg[2*n]+seg[2*n+1];
	}
}

int get(int n,int s,int e,int l,int r) {
	if(s>e||s>r||e<l)
		return 0;
	if(l<=s&&e<=r)
		return seg[n];
	int m=(s+e)>>1;
	return get(2*n,s,m,l,r)+get(2*n+1,m+1,e,l,r);
}

int dfs(int u) {
	wi[u]=1;
	for(int v : adj[u]) {
		if(v!=dp[u][0]) {
			dp[v][0]=u;
			hi[v]=hi[u]+1;
			wi[u]+=dfs(v);
		}
	}
	return wi[u];
}

void hld(int u,int r) {
	pi[u]=r;
	A[ix++]=u;
	mp[u]=ix-1;
	int x=-1;
	for(int v : adj[u]) {
		if(v!=dp[u][0]) {
			if(wi[v]>x)
				x=v;
		}
	}
	if(x!=-1)
		hld(x,r);
	for(int v : adj[u]) {
		if(v!=dp[u][0]&&v!=x)
			hld(v,v);
	}
}

int seg_up(int u,int v) {
	if(pi[u]==pi[v])
		return get(1,1,N,mp[v],mp[u]);
	return seg_up(dp[pi[u]][0],v)+get(1,1,N,mp[pi[u]],mp[u]);
}

int lca(int u,int v) {
	if(hi[v]>hi[u])
		swap(u,v);
	int lg=log2(hi[u]);
	for(int i=lg;i>=0;i--)
		if(hi[u]-(1<<i)>=hi[v])
			u=dp[u][i];
	if(u==v)
		return u;
	for(int i=lg;i>=0;i--)
		if(dp[u][i]!=0&&dp[u][i]!=dp[v][i]) {
			u=dp[u][i];
			v=dp[v][i];
		}
	return dp[u][0];
}


int query(int u,int v) {
	int x=lca(u,v);
	return seg_up(u,x)+seg_up(v,x)-B[x];
}


int32_t main() {
	int t,u,v,Q;
	cin>>N;
	memset(seg,0,sizeof(0));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=N;i++)
		adj[i].clear();
	for(int i=1;i<=N;i++)
		cin>>B[i];
	for(int i=2;i<=N;i++) {
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dp[1][0]=0;
	hi[1]=1;
	dfs(1);
	ix=1;
	hld(1,1);
	for(int i=1;i<=20;i++)
		for(int u=1;u<=N;u++)
			dp[u][i]=dp[dp[u][i-1]][i-1];
	for(int i=1;i<=N;i++)
		upd(1,1,N,i,B[A[i]]);
	cin>>Q;
	while(Q--) {
		cin>>t>>u>>v;
		if(t==1) {
			upd(1,1,N,mp[u],v);
			B[u]=v;
		}
		else
			cout<<query(u,v)<<"\n";
	}
}
