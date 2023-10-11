#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    vector<int> V(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i];
    }


// N+1 -> すべて選択する場合と選択しない場合を考える必要があるので1を足す
// m+1 -> 0~Mになるので1を足す
    vector<vector<int>> dp(N+1, vector<int>(M+1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (dp[i][j] < 0) {
                continue;
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

            if (j+W[i] <= M) {
                dp[i+1][j+W[i]] = max(dp[i+1][j+W[i]], dp[i][j] + V[i]);
            }
        }
    }

    int res = -1;
    for (int j = 0; j <= M; ++j) res = max(res, dp[N][j]);
    cout << res << endl;

    return 0;
}