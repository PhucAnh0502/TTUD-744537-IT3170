#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle {
    int height, width;
};

bool canPlace(vector<vector<bool>>& grid, int H, int W, Rectangle rect, int x, int y) {
    if (x + rect.height > H || y + rect.width > W) return false;
    
    for (int i = x; i < x + rect.height; ++i) {
        for (int j = y; j < y + rect.width; ++j) {
            if (grid[i][j]) return false; // N?u ô dã du?c s? d?ng
        }
    }
    
    // Ðánh d?u ô dã s? d?ng
    for (int i = x; i < x + rect.height; ++i) {
        for (int j = y; j < y + rect.width; ++j) {
            grid[i][j] = true;
        }
    }
    
    return true;
}

void unplace(vector<vector<bool>>& grid, Rectangle rect, int x, int y) {
    // Khôi ph?c tr?ng thái ô
    for (int i = x; i < x + rect.height; ++i) {
        for (int j = y; j < y + rect.width; ++j) {
            grid[i][j] = false;
        }
    }
}

bool backtrack(vector<vector<bool>>& grid, int H, int W, vector<Rectangle>& rectangles, int index) {
    if (index == rectangles.size()) return true; // Ðã d?t t?t c? hình ch? nh?t

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            // Ki?m tra d?t hình ch? nh?t theo chi?u g?c
            if (canPlace(grid, H, W, rectangles[index], i, j)) {
                if (backtrack(grid, H, W, rectangles, index + 1)) return true;
                unplace(grid, rectangles[index], i, j); // Quay lui
            }
            // Ki?m tra d?t hình ch? nh?t theo chi?u xoay
            swap(rectangles[index].height, rectangles[index].width); // Hoán d?i chi?u cao và chi?u r?ng
            if (canPlace(grid, H, W, rectangles[index], i, j)) {
                if (backtrack(grid, H, W, rectangles, index + 1)) return true;
                unplace(grid, rectangles[index], i, j); // Quay lui
            }
            swap(rectangles[index].height, rectangles[index].width); // Khôi ph?c chi?u ban d?u
        }
    }
    
    return false; // Không th? d?t hình ch? nh?t
}

int main() {
    int H, W;
    cin >> H >> W;
    int n;
    cin >> n;

    vector<Rectangle> rectangles(n);
    for (int i = 0; i < n; ++i) {
        cin >> rectangles[i].height >> rectangles[i].width;
    }

    vector<vector<bool>> grid(H, vector<bool>(W, false)); // Lu?i d? theo dõi ô dã s? d?ng

    cout << (backtrack(grid, H, W, rectangles, 0) ? 1 : 0) << endl;

    return 0;
}

