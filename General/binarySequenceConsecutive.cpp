#include<iostream>

using namespace std;

int N;
int a[21];

void print(){
    for(int i = 1; i <= N; i++){
        cout << a[i];
    }
    cout << endl;
}

int check(int k, int v){
    if(k==1) return 1;
    if(a[k-1] == 1){
        if(v == 1) return 0;
    }
    return 1;
}

void Try(int k){
    for(int i = 0; i <= 1; i++){
        if(check(k, i) != 1){
            continue;
        }
        a[k] = i;
        if(k==N){
            print();
        } else {
            Try(k+1);
        }
    }
}

int main(){
    cin >> N;
    Try(1);
}
