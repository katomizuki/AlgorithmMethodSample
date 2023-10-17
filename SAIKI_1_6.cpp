#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> A;
vector<vector<int>> memo;

int func(int i, int j) {
    if (memo[i][j]!=-1) {
        return memo[i][j];
    }

    if (i==0) {
        memo[i][j] = j==0;
        return memo[i][j];
    }

    int flag = 0;
    memo[i][j] = 0;

    if (j>=A[i-1] && func(i-1, j-A[i-1])==1) flag = 1;
    if (func(i-1, j)==1) flag = 1;

    return flag;
}

int main() {
    int N, X;
    cin >> N >> X;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    memo.resize(N+1, vector<int>(X+1, -1));
    string ans = func(N,X)==1 ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}