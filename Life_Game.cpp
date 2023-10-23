#include <bits/stdc++.h>
using namespace std;

int get_next_state(int now_state, int x) {
    int next_state = now_state;

    if (now_state == 0 && x == 3) next_state = 1;
    if (now_state == 1) {
        if (x <= 1 || x >= 4) next_state = 0;
        else next_state = 1;
    }
    return next_state;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<vector<int>> T(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        vector<int> temp(N);
        for (int j = 0; j < N; j++) {
            if (S[j] == '.') temp[j] = 0;
            else temp[j] = 1;
        }
        T[i] = temp;
    }

// 更新をX回くりかえす　
    for (int k = 0; k < X; k++) {
        vector<vector<int>> next_table(N, vector<int>(N, 0));
// // 全マス更新
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // マスの方位8マスを確認しに行く。
                // 周りの8マスの生きているマスの合計数
                int sum = 0;
                for(int l = i-1; l <= i + 1; l++) {
                    for(int m = j-1; m <= j + 1; m++) {
                        if (l == i && m == j) continue;
                        if (0 <= l && l < N && 0 <= m && m < N) sum += T[l][m];
                    }
                }
                next_table[i][j] = get_next_state(T[i][j], sum);
            }
        }
        T = next_table;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (T[i][j] == 0) cout << '.';
            else if (T[i][j] == 1) cout << '#';
        }
        cout << endl;
    }
    return 0;
}