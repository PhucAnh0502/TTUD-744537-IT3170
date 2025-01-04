#include<bits/stdc++.h>

using namespace std;

string replaceAll(string T, string &P1, string &P2){
    int index = 0;
    while ((index = T.find(P1, index)) != -1) {
        T.replace(index, P1.length(), P2);
        index += P2.length();
    }
    return T;
}
int main(){
    string T, P1, P2;
    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);

    cout << replaceAll(T, P1, P2);
    return 0;
}
