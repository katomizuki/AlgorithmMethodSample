#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> A;

bool func(int i, int j) {
    if (i == 0) return j == 0;

    bool flag = false;

    if (j >= A[i-1] && func(i-1,j-A[i-1])) flag = true;
    if (func(i-1,j)) flag = true;
    return flag;
}

int main() {
    int N, X;
    cin >> N >> X;
    A.resize(N);

    for (int i = 0; i < N; i++) cin >> A[i];

    if (func(N, X)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}