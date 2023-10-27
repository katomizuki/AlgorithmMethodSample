#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> counter(100001, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        counter[A[i]]++;
    }

    long long all_pattern = (long long) N * (N - 1) / 2;    // 全パターン数
    long long same_pattern = 0;

    for(int i = 0; i <= 100000; i++) {
        long long val = counter[i];
        same_pattern += val * (val - 1) / 2;
    }

    long double ans = (long double) same_pattern / all_pattern;
    cout << fixed << setprecision(10);
    cout << ans << endl;

    return 0;
}