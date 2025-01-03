#include<iostream>

using namespace std;

int T, m, n, a[1001], b[1001];

int check(int a[], int b[], int m, int n){
    if(n != m) return 0;
    for(int i = 0; i < m; i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}

void solve(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        cout << check(a,b,m,n) << endl;
    }
}

int main(){
    solve();
    return 0;
}
