#include <bits/stdc++.h>
using namespace std;

// 連結リストの各ノード
struct Node {
    Node* nex;  // 次がどのノードを指すか
    string value;  // ノードに付随している値
    Node(const string& value = "") : nex(NULL), value(value) { }
};

struct HashMapNodes {
    Node* nil;  // 番兵を表すノード

    // 連結リストの初期化
    void init() {
        nil = new Node();
        nil->nex = nil; // 初期状態では nil が nil を指すように
    }

    // 連結リストへ先頭への要素の挿入
    void insert(Node* v) {
        v->nex = nil->nex;  // v の次を、現在の先頭に
        nil->nex = v;  // 先頭を v に書き換える
    }

    // 文字列が S である要素の削除
    void erase(string &S) {
        Node *cur = nil, *ncur = cur->nex;  // 要素 cur とその次の要素 ncur
        while(ncur != nil) {
            if(ncur->value == S) {
                // ncur の文字列が S なら、ncur を削除する
                cur->nex = ncur->nex;
                delete ncur;
                return;
            }
            else {
                // そうでないなら、cur を次に進める
                cur = ncur;
                ncur = cur->nex;
            }
        }
    }

    // 文字列が S である要素の検索
    bool search(string &S) {
        Node *cur = nil, *ncur = cur->nex;  // 要素 cur とその次の要素 ncur
        while(ncur != nil) {
            if(ncur->value == S) {
                // ncur の文字列が S なら、true を返す
                return true;
            }
            else {
                // cur を次に進める
                cur = ncur;
                ncur = cur->nex;
            }
        }
        // 全ての文字列を見たなら、false を返す
        return false;
    }

};

const long long B = 30, M = 1000003;
long long p30[10];
void init() {
    for(int i = 0; i < 10; ++i) {
        if(i == 0) {p30[i] = 1;}
        else {p30[i] = p30[i-1] * 30 % M;}
    }
    return;
}

// 文字列を 30 進数の数とみなし、そのハッシュ値を返す関数
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
    // p30 の初期化と、ハッシュテーブルの初期化
    init();
    vector<HashMapNodes> hash_table(M);
    for(int i = 0; i < M; ++i) {
        hash_table[i].init();
    }

    // 入力を受け取り、クエリに答える
    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type; cin >> type;
        string T; cin >> T;
        int num = hash30(T);    // 文字列 T をハッシュ値 num に変換する

        if(type == 0) {
            Node *v = new Node(T);
            hash_table[num].insert(v);
        }
        else if(type == 1) {
            hash_table[num].erase(T);
        }
        else if(type == 2) {
            if(hash_table[num].search(T)) {cout << "Yes" << endl;}
            else {cout << "No" << endl;}
        }
    }
    return 0;
}