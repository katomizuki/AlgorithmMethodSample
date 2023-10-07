#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int A0, A1, A2, A3;
    cin >> A0 >> A1 >> A2 >> A3;

    vector<int> t(4, 0);
    vector<vector<int>> T(4, t);
    T[0] = { A0, A1, A2, A3 };
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            T[i][j] += T[i-1][j];

            if(j > 0) {
                T[i][j] += T[i-1][j-1];
            }

            if(j < 3) {
                T[i][j] += T[i-1][j+1];
            }
        }
    }
    cout << T[3][3] << endl;
    return 0;
}