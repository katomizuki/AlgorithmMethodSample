#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; i++) cin >> W[i];

    // どっちかにはなんも入れなくて片方にすべてを入れる場合に最大の差になる。
    int MAX = 0;
    for (int i = 0; i < N; ++i) MAX += W[i];


    vector<vector<bool>> dp(N+1, vector<bool>(MAX+1, false));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= MAX; j++) {
            if (!dp[i][j]) continue;

            // 更新
            dp[i+1][j+W[i]] = true;
            dp[i+1][abs(j-W[i])] = true;
        }
    }

    int res = 0;
    while (!dp[N][res]) ++res;
    cout << res << endl;

    return 0;
}