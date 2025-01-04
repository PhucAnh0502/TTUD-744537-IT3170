#include<bits/stdc++.h>

using namespace std;

set<string> db;

int findKey(string s){
    if(db.find(s)!=db.end()) return 1;
    return 0;
}

int insertKey(string s){
    if(findKey(s)==1) return 0;
    else {
        db.insert(s);
        return 1;
    }
}

int main(){
    string key, cmd;
    while(cin >> key){
        if(key == "*") break;
        else {
            db.insert(key);
        }
    }
    while(cin >> cmd) {
        if(cmd == "***") break;
        else if (cmd == "insert"){
            string tmp; cin >> tmp;
            cout << insertKey(tmp) << endl;
        } else if (cmd == "find") {
            string tmp; cin >> tmp;
            cout << findKey(tmp) << endl;
        }
    }
}
