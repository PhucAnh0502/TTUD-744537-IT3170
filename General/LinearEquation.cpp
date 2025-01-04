#include<bits/stdc++.h>
#define MAX 21

using namespace std;

int n, M;
int f;
int cnt;
int a[MAX], X[MAX], t[MAX];

void initT(){
    t[1] = a[1];
    for(int i = 2; i <= n; i++) t[i] = t[i-1] + a[i];
}

void solution(){
    if(f == M) cnt++;
}

void Try(int k){
    int v;
    for(v = 1; v <= (M-f-(t[n] - t[k]))/a[k]; v++){
        X[k] = v;
        f += a[k] * X[k];
        if(k == n){
            solution();
        } else {
            Try(k+1);
        }
        f -= a[k] * X[k];
    }
}

void input(){
    cin >> n >> M;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    f = 0;
    initT();
    cnt = 0;
    Try(1);
    cout << cnt;
}

int main(){
    input();
    solve();
    return 0;
}
