#include<iostream>
#include<cmath>

using namespace std;

const int MAXN = 1000001;
int n, q, a[MAXN], t[4 * MAXN];

void build(int v, int l, int r){
	if(l == r) {
		t[v] = a[l];
	} else {
		int m = (l + r)/2;
		build(2 * v, l, m);
		build(2 * v + 1, m + 1, r);
		t[v] = min(t[2 * v], t[2 * v + 1]);
	}
}

int query(int v, int tl, int tr, int l, int r){
	if(l > r) return MAXN;
	if(tl == l && tr == r){
		return t[v];
	} else {
		int tm = (tl + tr)/2;
		int s1 = query(2 * v, tl, tm, l, min(r,tm));
		int s2 = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
		return min(s1, s2);
	}
}

int main(){
	int sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n - 1);
	cin >> q;
	for(int i = 0; i < q; i++){
		int l; cin >> l;
		int r; cin >> r;
		sum += query(1, 0, n - 1, l, r);
	}
	cout << sum;
}
