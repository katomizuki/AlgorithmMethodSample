#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

void output(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i != A.size()-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
// 1
    int X = N + 1;
    vector<int> num(X, 0);

// 2
    for (int i = 0; i < N; i++) {
        num[A[i]] += 1;
    }

// 3
    vector<int> acc(X);
    for (int i = 0; i < X; i++) {
        if (i == 0) {
            acc[i] = num[i];
        } else {
            acc[i] = acc[i-1] + num[i];
        }
    }

// 4
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        acc[A[i]]--;
        B[acc[A[i]]] = A[i];
    }

    output(B);
    return 0;
}