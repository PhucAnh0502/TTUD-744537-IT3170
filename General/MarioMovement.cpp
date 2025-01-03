#include<iostream>
#define MAX 1001
using namespace std;

int maze[MAX][MAX];
int n, m;
int r, c;

void input(){
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> maze[i][j];
        }
    }
}

void moveUp(){
    if(maze[r-1][c] == 0 && (r-1) > 0){
        r--;
    }
}

void moveDown(){
    if(maze[r+1][c] == 0 && (r+1) <= n){
        r++;
    }
}

void moveLeft(){
    if(maze[r][c-1] == 0 && (c-1) > 0){
        c--;
    }
}

void moveRight(){
    if(maze[r][c+1] == 0 && (c+1) <= m){
        c++;
    }
}

int main(){
    input();
    string cmd;
    while(cin >> cmd){
        if(cmd == "#") break;
        if(cmd == "move-up"){
            moveUp();
        } else if(cmd == "move-down"){
            moveDown();
        } else if(cmd == "move-left"){
            moveLeft();
        } else if(cmd == "move-right"){
            moveRight();
        }
    }
    cout << r << " " << c;
    return 0;
}
