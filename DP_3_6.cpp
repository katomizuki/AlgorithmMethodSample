#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    vector<vector<bool>> dp(N+1, vector<bool>(A, false));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= A; j++) {
            if (!dp[i][j]) continue;
            dp[i+1][j] = true;
            dp[i+1][(j+X[i])%A] = true;
        }
    }

    if (dp[N][B]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}