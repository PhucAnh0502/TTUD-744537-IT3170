#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, K, Q;
vector<int> d;
vector<vector<int>> c;
int min_distance = INT_MAX;

void backtrack(int truck_index, int current_distance, vector<bool>& visited, vector<int>& current_route, int current_capacity) {
    if (truck_index == K) {
        if (all_of(visited.begin(), visited.end(), [](bool v) { return v; })) {
            min_distance = min(min_distance, current_distance);
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && current_capacity + d[i] <= Q) {
            visited[i] = true;
            current_route.push_back(i + 1);

            int new_distance = current_distance;
            if (current_route.size() == 1) {
                new_distance += c[0][i];  // T? kho d?n khách hàng
            } else {
                new_distance += c[current_route[current_route.size() - 2] - 1][i];  // T? khách hàng tru?c d?n khách hàng hi?n t?i
            }

            backtrack(truck_index, new_distance, visited, current_route, current_capacity + d[i]);

            visited[i] = false;
            current_route.pop_back();
        }
    }

    if (!current_route.empty()) {
        int last_client = current_route.back() - 1;
        current_distance += c[last_client][0];  // Tr? v? kho
        vector<int> empty_route;  // T?o m?t vector r?ng cho xe t?i ti?p theo
        backtrack(truck_index + 1, current_distance, visited, empty_route, 0);
    } else {
        vector<int> empty_route;  // T?o m?t vector r?ng cho xe t?i ti?p theo
        backtrack(truck_index + 1, current_distance, visited, empty_route, 0);
    }
}

int main() {
    cin >> n >> K >> Q;
    d.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    c.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> c[i][j];
        }
    }

    vector<bool> visited(n, false);
    vector<int> current_route;

    backtrack(0, 0, visited, current_route, 0);

    cout << (min_distance == INT_MAX ? 0 : min_distance) << endl;

    return 0;
}

