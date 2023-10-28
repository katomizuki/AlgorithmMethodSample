#include <bits/stdc++.h>
using namespace std;

int main() {

    int N; cin >> N;
    vector<int> A(N);
    int xMax = 500001;
    vector<int> counter(xMax, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        counter[A[i]]++;
    }

    int Q; cin >> Q;
    vector<int> memo(xMax + 1, -1);
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        // 一度通ったクエリは見ない。
        if (memo[x] != -1) cout << memo[x] << endl;
        else {
            int ans = 0;
            for (int v = 0; v <= xMax; v += x) ans += counter[v];
            cout << ans << endl;
            memo[x] = ans;
        }
    }
    return 0;
}