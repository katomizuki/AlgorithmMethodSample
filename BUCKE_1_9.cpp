#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];


    const int vmax = 1000000;
    // 最大で2000001
    vector<int> isSumSquare(2 * vmax + 1, 0);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            isSumSquare[A[i] * A[i] + A[j] * A[j]] = 1;

    string ans = "No";  // 答えを表す変数
    for(int v = 0; v < 2 * vmax + 1; v++) {
        if (v > M) continue;

// どちらも1で存在していれば
        if (isSumSquare[v] == 1 && isSumSquare[M-v] == 1) ans = "Yes";
    }
    cout << ans << endl;


    return 0;
}