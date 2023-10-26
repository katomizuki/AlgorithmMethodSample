#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node* nex;
    Node* pre;
    int value;

    Node(const int& value): nex(NULL), pre(NULL), value(value) { }
};

Node* nil;

void init() {
    nil = new Node(0);
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

int PopTrail() {
    // nilのPreは末尾になるので取得する。これが自身を指していれば中身がないのでErrorにする
    Node *tail = nil->pre;
    if (tail == nil) {
        return 0;
    } else {
        // nilのまえをTailのまえにする（Tailが連結リストから消える）
        nil->pre = tail->pre;
        // もともとTail.preにあったNodeのNextをNilにおきかえてあげる。
        (nil->pre)->nex = nil;
        // 末尾のメモリを解放
        delete tail;
        return tail->value;
    }
}

int main() {
    int N;
    cin >> N;
    init();
    for (int i = 1; i < N+1; i++) PushHead(new Node(i));

    int answer = 0;
    bool flag = true;
    while (flag) {
        answer = PopTrail();
        // 一周したらターゲットになるのでPushHeadする。
        int nodeValue = PopTrail();
        // 中身がない場合
        if (nodeValue == 0) {
            flag = false;
            break;
        }
        Node* node = new Node(nodeValue);
        PushHead(node);
    }

    cout << answer << endl;
    return 0;
}
