#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    vector<vector<int>> dp(N, vector<int>(N));
    dp[0][0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (T[i][j] == '#') continue;
            if (i - 1 >= 0) dp[i][j] += dp[i-1][j];
            if (j - 1 >= 0) dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[N-1][N-1] << endl;
    return 0;
}