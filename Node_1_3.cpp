#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* nex;
    Node* pre;
    string value;
    Node(const string& value = "") : nex(NULL), value(value) { }
};

Node* nil;

void init() {
    nil = new Node();
    nil->nex = nil;
    nil->pre = nil;
}

void PushHead(Node* v) {
    // 先頭のNodeをV.nextにいれる。
    v->nex = nil->nex;
    // v.preにnilをいれる
    v->pre = nil;
    // 先頭を引数のＶに更新
    nil->nex = v;
    // もともと先頭だったNodeのPreを引数のＶに更新
    (v->nex)->pre = v;
    return;
}

string PopTrail() {
    // nilのPreは末尾になるので取得する。これが自身を指していれば中身がないのでErrorにする
    Node *tail = nil->pre;
    if (tail == nil) {
        return "Error";
    } else {
        // 末尾の文字列を取得
        string res = tail->value;
        // nilのまえをTailのまえにする（Tailが連結リストから消える）
        nil->pre = tail->pre;
        // もともとTail.preにあったNodeのNextをNilにおきかえてあげる。
        (nil->pre)->nex = nil;
        // 末尾のメモリを解放
        delete tail;

        return res;
    }
}

int main() {
    int Q;
    cin >> Q;
    init();
    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        if (query == 0) {
            string S;
            cin >> S;
            Node *v = new Node(S);
            PushHead(v);
        } else {
            cout << PopTrail() << endl;
        }
    }
    return 0;
}