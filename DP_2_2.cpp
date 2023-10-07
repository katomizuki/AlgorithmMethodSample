#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> t(N, 0);
    vector<vector<int>> T(N, t);
    for (int i = 0; i < N; i++) {
        cin >> T[0][i];
    }

    for(int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            T[i][j] += T[i-1][j];
            if(j > 0) { T[i][j] += T[i-1][j-1]; }
            if(j < N - 1) { T[i][j] += T[i-1][j+1]; }
            T[i][j] = T[i][j] % 100;
        }
    }
    cout << T[N-1][N-1] << endl;
    return 0;
}