#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N - 1);
    for (int i = 0; i < N-1; i++) {
        cin >> A[i];
    }

    vector<vector<bool>> dp(N, vector<bool>(M, false));
    dp[0][0] = true;

    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j < M; ++j) {
            // マス (i, j) にコマが行く可能性がない場合はスキップ
            if (!dp[i][j]) {
                continue;
            }

// 下に移動するマスをTrueにする
            dp[i+1][j] = true;

            if (j+A[i] < M) {
                // A[i]分のマスに移動する。
                dp[i+1][j+A[i]] = true;
            }
        }
    }

    int res = 0;
    for (int j = 0; j < M; ++j) {
        // 最下層に行く通りを数える。
        if (dp[N-1][j]) ++res;
    }
    cout << res << endl;

    return 0;
}