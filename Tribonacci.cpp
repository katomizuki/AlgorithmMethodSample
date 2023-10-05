#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> T(N + 1, 0);
    T[0] = 1;


    for (int i = 1; i <= N; ++i) {
        if (i-1 >= 0) T[i] += T[i-1];
        if (i-2 >= 0) T[i] += T[i-2];
        if (i-3 >= 0) T[i] += T[i-3];
    }
    cout << T[N] << endl;
    return 0;
}