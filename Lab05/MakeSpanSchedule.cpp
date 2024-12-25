#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

struct Arc{
	int v;
	int w;
	Arc(int _v, int _w):v(_v), w(_w){}
};

int n,m;
int d[N];
vector<Arc> A[N];
int deg[N];
vector<int> L;
int F[N];
int ans;

void input(){
	memset(deg,0,sizeof deg);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> d[i];
	}
	for(int k = 1; k <= m; k++){
		int u,v;
		cin >> u >> v;
		A[u].push_back(Arc(v,d[u]));
		deg[v]++;
	}
}

void topoSort(){
	queue<int> Q;
	for(int v = 1; v <= n; v++){
		if(deg[v] == 0){
			Q.push(v);
		}
	}	
	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		L.push_back(x);
		for(int i = 0; i < A[x].size(); i++){
			int y = A[x][i].v;
			deg[y] -= 1;
			if(deg[y] == 0) Q.push(y);
		}
	}
}

void solve(){
	memset(F, 0, sizeof F);
	ans = 0;
	for(int i = 0; i < L.size(); i++){
		int u = L[i];
		ans = max(ans, F[u] + d[u]);
		for(int j = 0; j < A[u].size(); j++){
			int v = A[u][j].v;
			int w = A[u][j].w;
			F[v] = max(F[v], F[u] + w);
			 
		}
	}
	cout << ans << endl;
}

int main(){
	input();
	topoSort();
	solve();
	return 0;
}
