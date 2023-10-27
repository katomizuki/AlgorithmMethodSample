#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;

    vector<int> right(N, -1), left(N, -1);
    // right, left の初期化
    for(int i = 0; i < N; ++i) {
        if(i != 0) {left[i] = i - 1;}
        if(i != N-1) {right[i] = i + 1;}
    }

    // 次に進むべき方向と今見ているマス
    int direct = 1, v = K;
    // 答えを表す変数 (int 型には収まらないことに注意)
    long long ans = 0;

    while(1) {
        // v の情報を削除
        right[left[v]] = right[v];
        left[right[v]] = left[v];

        // S[v] で次の方向が決まる (空きマスなら、方向は今のまま)
        if(S[v] == '>') {direct = 1;}
        if(S[v] == '<') {direct = -1;}

        // 次に踏む未踏のマス
        int nv;
        if(direct == 1) {
            nv = right[v];
        }
        else if(direct == -1) {
            nv = left[v];
        }
        // 距離を足し合わせて、v を更新する
        ans += abs(v - nv);
        v = nv;

        // 終了条件
        if(v == 0 || v == N - 1) {break;}
    }

    cout << ans << endl;

    return 0;
}