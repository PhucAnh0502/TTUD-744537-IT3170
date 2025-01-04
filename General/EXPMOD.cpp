#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

long long power(unsigned long long a, unsigned long long b) {
    if (b == 0) return 1;
    unsigned long long half = power(a, b / 2);
    half = (half * half) % MOD;

    if (b % 2 == 1) {
        return (half * a) % MOD;
    }
    return half;
}

int main() {
    unsigned long long a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
    return 0;
}
