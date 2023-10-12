#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        bool isSwap = false;
        for (int j = 0; j < N-1; j++) {
            if (A[j] > A[j+1]) {
                isSwap = true;
                swap(A[j], A[j+1]);
            }
        }
        if (isSwap) {
            for (int k = 0; k < A.size(); k++) {
                cout << A[k];
                if (k != A.size()-1){
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
        } else {
            continue;
        }
    }

    return 0;
}