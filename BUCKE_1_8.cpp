#include <bits/stdc++.h>
using namespace std;

int main() {

    const int pmax = 10000;
    vector<int> counter(2 * pmax + 1, 0); // counter[v] : x^2 + y^2 = v を満たす整数組 (x, y) の個数

    for(int x = -100; x <= 100; ++x) {
        for(int y = -100; y <= 100; ++y) {
            int v = x * x + y * y;
            counter[v]++;
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; ++i) {
        int P;
        cin >> P;
        cout << counter[P] << endl;
    }

    return 0;
}