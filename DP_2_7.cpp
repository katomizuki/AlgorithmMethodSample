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

    vector<vector<int>> dp(N, vector<int>(N,0));
    dp[0][N-1] = T[0][N-1];
    for (int i = N-2; i >= 0; i--) {
        dp[0][i] = dp[0][i+1] + T[0][i];
        // cout << dp[0][i] << endl;
    }

    for(int i = 1; i < N; i++) {
        dp[i][N-1] = dp[i-1][N-1] + T[i][N-1];
        // cout << dp[i][N-1] << endl;
    }

    for (int i = 1; i < N; i++) {
        for (int j = N-2; j >= 0; j--) {
            dp[i][j] = min(dp[i-1][j], dp[i][j+1]) + T[i][j];
        }
    }

    cout << dp[N-1][0] << endl;
    return 0;
}