#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N);
    A[0] = X;
    A[1] = Y;
    for(int i=2; i<N; i++) {
        A[i] = (A[i-1] + A[i-2]) % 100;
    }

    cout << A[N-1] << endl;

    return 0;
}