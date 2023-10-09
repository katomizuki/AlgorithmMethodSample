#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int N, M;
    cin >> N >> M;
    vector<int> W(N);
    for (int i = 0; i < N; ++i) cin >> W[i];

    // (N+1) × (M+1) のマスを用意する
    vector<vector<bool>> dp(N+1, vector<bool>(M+1, false));

    // 初期状態 (左上のマスにコマがありうる)
    dp[0][0] = true;

    // 各マス (i, j) から「真下」「右下」へコマを渡していく
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= M; ++j) {
            // マス (i, j) にコマが行く可能性がない場合はスキップ
            if (!dp[i][j]) continue;

            // 真下マスへコマを渡す
            dp[i+1][j] = true;

            // 右下マス (あるならば) へコマを渡す
            if (j+W[i] <= M) dp[i+1][j+W[i]] = true;
        }
    }

    // 答え
    if (dp[N][M]) cout << "Yes" << endl;
    else cout << "No" << endl;
}