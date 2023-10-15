#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N+1);
    A[0] = 1;
    A[1] = 1;
    for (int i = 2; i <= N; i++) {
        A[i] = A[i-1] + A[i-2];
    }

    cout << A[N] << endl;
    return 0;
}