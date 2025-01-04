#include<bits/stdc++.h>

using namespace std;

int n, M;
int arr[1000001];
map<int, int> mp;
int cnt;

void input(){
    cin >> n >> M;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
}

void solve(){
    cnt = 0;
    for(int i = 0; i < n; i++){
        mp[arr[i]]--;
        if(mp[M - arr[i]]!=0){
            cnt+=mp[M - arr[i]];
        }
    }
}

int main(){
    input();
    solve();
    cout << cnt;
    return 0;
}
