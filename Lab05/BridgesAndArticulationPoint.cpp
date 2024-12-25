#include<bits/stdc++.h>
#define N 100001

using namespace std;

int n, m;
int Num[N], Low[N], T = 0;
bool artPoint[N];
int p[N];
vector<int> V[N];

int bridges = 0;
int artPoints = 0;

void dfs(int u){
	T++;
	Num[u] = T; Low[u] = T;
	int numChild = 0;
	for(int v : V[u]){
		if(p[u] == v) continue;
		if(Num[v]){
			Low[u] = min(Low[u], Num[v]);
		} else {
			p[v] = u;
			dfs(v);
			Low[u] = min(Low[u], Low[v]);
			numChild++;
			if(Low[v] >= Num[v]) bridges++;
			if(u == p[u]){
				if(numChild >= 2){
					artPoint[u] = true;
				}
			} else {
				if(Low[v] >= Num[u]) artPoint[u] = true;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u,v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		p[i] = i;
		Num[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		if(!Num[i]) dfs(i);
	}
	for(int i = 1; i <= n; i++){
		artPoints += artPoint[i];
	}
	cout << artPoints << " " << bridges;
	return 0;
}
