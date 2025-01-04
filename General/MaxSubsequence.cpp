#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int arr[MAX];
int n;

int solve(int arr[], int n){
    int maxEnd = 0;
    int ans = INT_MIN;

    for(int i = 0; i < n; i++){
        maxEnd += arr[i];
        if(maxEnd > ans){
            ans = maxEnd;
        }
        if(maxEnd < 0){
            maxEnd = 0;
        }
    }

    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << solve(arr, n);
    return 0;
}
