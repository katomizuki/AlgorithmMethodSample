#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> W(N);
    for (int i = 0; i < N; i++) cin >> W[i];

    int infinity = 100000;
    vector<vector<int>> dp(N+1, vector<int>(M+1, infinity));
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= M; ++j) {
            // inifiityはつくれない
            if (dp[i][j] >= infinity) continue;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if (j+W[i] <= M) {
                dp[i+1][j+W[i]] = min(dp[i][j]+1, dp[i+1][j+W[i]]);
            }
        }
    }

    if (infinity != dp[N][M]) {
        cout << dp[N][M] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}