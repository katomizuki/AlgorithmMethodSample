#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> D(N);
    for (int i = 0; i < M; ++i) cin >> D[i];

    vector<int> T(N + 1, false);
    T[0] = true;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i - D[j] >= 0 && T[i - D[j]]) {
                T[i] = true;
            }
        }
    }

    cout << (T[N] ? "Yes" : "No") << endl;
    return 0;
}