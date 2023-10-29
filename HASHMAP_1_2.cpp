#include <bits/stdc++.h>
using namespace std;

const long long B = 30, M = 1000003;    // 問題文で指定された B(基数) と M(除数)
long long p30[10];  // p30[i] : 30 の i 乗

void init() {
    for(int i = 0; i < 10; ++i) {
        if(i == 0) {p30[i] = 1;}
        else {p30[i] = p30[i-1] * 30 % M;}
    }
    return;
}

int hash30(string &S) {
    int len = S.length();
    long long ret = 0;  // 変換後の数値を入れる変数
    for(int i = 0; i < len; ++i) {
        char c = S[len-1-i];    // S の後ろから i 番目の文字 (0-index で)
        int n = c - 'a' + 1;    // 'a' を 1 にするため、+1 が必要
        ret += n * p30[i];
        ret %= M;   // ハッシュ値は M で割った余り
    }
    return ret;
}

int main() {
    init(); // p30 の初期化
    int N; cin >> N;
    vector<string> S(N);
    vector<int> counter(M, 0);  // counter[v] : hash 値が整数 v である要素の数
    for(int i = 0; i < N; ++i) {
        cin >> S[i];
        int num = hash30(S[i]);   // 文字列 S_i をハッシュ値 num に変換
        counter[num]++;
    }

    // counter 内の最大値を出力する
    int ans = *max_element(counter.begin(), counter.end());
    cout << ans << endl;

    return 0;
}