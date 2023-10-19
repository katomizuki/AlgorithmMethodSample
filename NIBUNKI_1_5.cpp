#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    long long count = 0;

    for (int i = 0; i < N; i++) {
        int left = 0;
        int right = N;

        while (left != right) {
            int middle = (left + right) / 2;

            if (A[middle] + A[i] >= K) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        count += N - left;
    }

    cout << count << endl;
    return 0;
}