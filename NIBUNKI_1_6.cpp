#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; i++) cin >> W[i];

    vector<int> A = W;

    sort(W.begin(), W.end());

    for (int k = 0; k < N; k++) {
        int left = 0;
        int right = N;

        while (left != right) {
            int middle = (left + right) / 2;
            if (W[middle] >= A[k]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        cout << left << endl;
    }

    return 0;
}