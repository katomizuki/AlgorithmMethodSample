#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* nex;
    string value;
    Node(const string& value = "") : nex(NULL), value(value) { }
};

Node* nil;

void init() {
    nil = new Node();
    nil->nex = nil;
}

void insert(Node* v) {
    // 先頭にInsertする
    v->nex = nil->nex;
    nil->nex = v;
}

string erase() {
    Node *front = nil->nex;
    if (front == nil) return "Error";
    else {
        string ret = front->value;
        nil->nex = front->nex;
        delete front;
        return ret;
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
            insert(node);
        } else {
            cout << erase() << endl;
        }
    }
    return 0;
}