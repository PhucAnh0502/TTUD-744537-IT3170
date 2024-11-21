#include<iostream>
#define MAX 1000006
using namespace std;

int const MOD = 1e9+7;
int n, a[MAX];
int temp[MAX];

int merge (int left,int mid, int right){
	int i = left, j = mid + 1, k = left, inv_count = 0;
	while((i<=mid) && (j <= right)){
		if(a[i]<= a[j]) temp[k++] = a[i++];
		else {
			temp[k++] = a[j++];
			inv_count = (inv_count + (mid - i + 1)) % MOD;
		}
	}
	while(i<=mid) temp[k++] = a[i++];
	while(j<= right) temp[k++] = a[j++];
	for(i = left; i <= right; i++){
		a[i] = temp[i];
	}
	return inv_count;
}

int mergeSort(int left, int right){
	int mid, inv_count=0;
	if(right > left){
		mid = (right + left) / 2;
		inv_count = (inv_count + mergeSort(left, mid)) % MOD;
		inv_count = (inv_count + mergeSort(mid + 1, right)) % MOD;
		inv_count = (inv_count + merge(left, mid, right)) % MOD;

	}
	return inv_count;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << mergeSort(0,n-1);
	return 0;
}
