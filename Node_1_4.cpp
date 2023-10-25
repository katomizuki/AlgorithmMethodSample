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

void PushTrail(Node* v) {
    v->nex = nil;   // v の次を nil に
    v->pre = nil->pre;  // v の前を、元の末尾ノードにいれる
    nil->pre = v;   // nil の前を v にしてｖを末尾ノードにする
    (v->pre)->nex = v;  // 元の末尾ノードの次を v に置き換える。　
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

string PopHead() {
    Node *head = nil->nex;
    if (head == nil) {
        return "Error";
    } else {
        string res = head->value;
        nil->nex = head->nex;
        (nil->nex)->pre = nil;
        delete head;
        return res;
    }
}

int main() {
    init();
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        if (query == 0) {
            string S;
            cin >> S;
            Node *node = new Node(S);
            PushHead(node);
        } else if (query == 1) {
            string S;
            cin >> S;
            Node *node = new Node(S);
            PushTrail(node);
        } else if (query == 2) {
            cout << PopHead() << endl;
        } else if (query == 3) {
            cout << PopTrail() << endl;
        }
    }
    return 0;
}