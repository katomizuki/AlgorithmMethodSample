#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    vector<int> A(4);
    for (int i = 0; i < 4; i++) cin >> A[i];
    const vector<int> coins = {50, 10, 5, 1};

    int count = 0;
    for (int i = 0; i < 4; ++i) {
        // 最大で何枚使用できるかを調査
        int add = X / coins[i];

// 使えるまでつかえるようになりたいのでMinでどちらかを選択
        add = min(add, A[i]);
        // コインの枚数が決定したので加算
        count += add;

        // 実際に減算
        X -= coins[i] * add;
    }

    cout << count << endl;

    return 0;
}