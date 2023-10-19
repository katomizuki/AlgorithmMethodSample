#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    for (int i = 0; i < M; i++) {
        int left = 0;
        int right = N - 1;

        while (left != right) {
            // 中点
            int middle = (left + right) / 2;

            // 求めたいKは中点より前のインデックス
            if (A[middle] >= B[i]) {
                right = middle;
                // 求めたいKは中点より後のインデックス
            } else {
                left = middle + 1;
            }
        }
        cout << left << endl;
    }
    return 0;
}