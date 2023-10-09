#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> T(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> T[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = T[0][0];
    for (int i = 1; i < N; ++i) {
        dp[0][i] = dp[0][i-1] + T[0][i];
        dp[i][0] = dp[i-1][0] + T[i][0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + T[i][j];
        }
    }

    cout << dp[N-1][N-1] << endl;
    return 0;
}