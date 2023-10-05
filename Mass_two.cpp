#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> T(N, 100000);

    T[0] = 0;

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (i-j >= 0) {
                T[i] = min(T[i], T[i-j] + A[i] * j);
            }
        }
    }
    cout << T[N - 1] << endl;

    return 0;
}