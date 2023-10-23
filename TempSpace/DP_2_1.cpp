#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int A0, A1, A2, A3;
    cin >> A0 >> A1 >> A2 >> A3;
    int size = 4;

    vector<vector<int>> T(size, vector<int>(size, 0));
    T[0] = { A0, A1, A2, A3 };

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size; j++) {
            T[i][j] += T[i-1][j];
            if(j > 0) T[i][j] += T[i-1][j-1];
            if(j < (size-1)) T[i][j] += T[i-1][j+1];
        }
    }
    cout << T[size-1][size-1] << endl;
    return 0;
}