#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> T(N, vector<int>(N));
    T[0][0] = 0;
    for (int i = 1; i < N; ++i) {
        T[0][i] = 1;
    }
    for (int i = 1; i < N; ++i) {
        T[i][0] = 1;
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            T[i][j] = T[i-1][j] + T[i][j-1];
        }
    }
    cout << T[N-1][N-1] << endl;
    return 0;
}