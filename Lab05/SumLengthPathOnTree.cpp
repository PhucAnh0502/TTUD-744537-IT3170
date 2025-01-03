#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

struct Edge{
	int node, w;
	Edge(int _node, int _w):node(_node), w(_w){}
};

int n;
vector<Edge> A[N];
int root;
int d[N];
int num[N];
int f[N];
int p[N];

void input(){
	cin >> n;
	for(int k = 1; k <= n - 1; k++){
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back(Edge(v,w));
		A[v].push_back(Edge(u,w));
	}
}

void dfs1(int u){
	for(int i = 0; i < A[u].size(); i++){
		Edge e = A[u][i];
		int v = e.node;
		int w = e.w;
		if(p[v] == 0){
			p[v] = u;
			dfs1(v);
			d[u] = d[u] + d[v] + num[v] * w;
			num[u] += num[v];
		}
	}
}

void solvePhase1(){
	for(int v = 1; v <= n; v++){
		p[v] = 0;
		d[v] = 0;
		num[v] = 1;
		f[v] = 0;
	}
	
	root = 1;
	p[root] = root;
	dfs1(root);
}

void dfs2(int u){
	for(int i = 0; i < A[u].size(); i++){
		Edge e = A[u][i];
		int v = e.node;
		int w = e.w;
		if(p[v] == 0){
			int F = f[u] - (d[v] + w*num[v]);
			f[v] = F + d[v] + w*(n-num[v]);
			p[v] = u;
			dfs2(v);
		}
	}
}

void solvePhase2(){
	for(int v = 1; v <= n; v++){
		p[v] = 0;
	}
	
	root = 1;
	f[root] = d[root];
	p[root] = root;
	dfs2(root);
	int ans = 0;
	for(int v = 1; v <= n; v++){
		ans = max(ans, f[v]);
	}
	cout << ans;
}

int main(){
	input();
	solvePhase1();
	solvePhase2();
	return 0;
}
