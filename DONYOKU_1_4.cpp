#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int j = 0; j < M; ++j) cin >> B[j];

    int res = 0;

    vector<bool> used(N, false);

// 箱は小さい順に入ってる。
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            if (used[i]) continue;
// 入れられる
            if (A[i] <= B[j]) {
                ++res;
                used[i] = true;
                break;
            }
        }
    }
    cout << res << endl;
}