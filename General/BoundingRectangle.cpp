#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int xmin = INT_MAX;
    int ymin = INT_MAX;
    int xmax = INT_MIN;
    int ymax = INT_MIN;

    for(int i = 1; i <= n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        xmin = min(xmin, min(x1, x2));
        ymin = min(ymin, min(y1, y2));
        xmax = max(xmax, max(x1, x2));
        ymax = max(ymax, max(y1, y2));
    }

    int area = (xmax - xmin) * (ymax - ymin);
    cout << area;
}
