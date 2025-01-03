#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;
int N;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int> &arr,int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void print(vector<int> &arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    quickSort(arr, 0, N-1);
    print(arr);
    return 0;
}
