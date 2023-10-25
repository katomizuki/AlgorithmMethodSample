#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* nex;
    Node* pre;
    int value;

    Node(const int& value): nex(NULL), pre(NULL), value(value) { }
};

vector<Node*> nodes;

void init (int i) {
    Node* v = new Node(i);
    nodes[i] = v;
    // 初期は連結していないのでNULLをいれる
    v->pre = NULL;
    v->nex = NULL;
}

void Connect(Node* pNode, Node* qNode) {
    // pNodeの前方にQnodeをいれる
    pNode->nex = qNode;
    // qNodeのPreにPNodeをいれる。
    qNode->pre = pNode;
}

void Contract(Node* rNode) {
    // 前方NodeをRnodeと連結を解除するので更新
    if (nodes[rNode->value]->nex)
        nodes[rNode->value]->nex->pre = nodes[rNode->value]->pre;
    // 後方NodeをRnodeと連結を解除するので更新
    if (nodes[rNode->value]->pre)
        nodes[rNode->value]->pre->nex = nodes[rNode->value]->nex;

    // Rnodeは前後ともに連結が会場されるのでNULLをいれる
    nodes[rNode->value]->pre = NULL;
    nodes[rNode->value]->nex = NULL;
}

int count_nodes(Node* firstNode) {
    int count = 1;
    Node* v = firstNode;
    // 先頭NodeのNexがNullでないかぎり
    while (v->nex != NULL) {
        count++;
        v = v->nex;
    }
    v = firstNode;
    while (v->pre != NULL) {
        count++;
        v = v->pre;
    }

    return count;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    nodes.resize(N);

    for (int i = 0; i < N; i++) init(i);

    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        if (query == 0) {
            int p, q;
            cin >> p >> q;
            // p,qそれぞれの位置にあるNodeを取得
            Node* pNode;
            pNode = nodes[p];
            Node* qNode;
            qNode = nodes[q];
            // queryを実行
            Connect(pNode, qNode);
        } else if (query == 1) {
            int r;
            cin >> r;
            // rの位置のNodeを取得
            Node* rNode;
            rNode = nodes[r];
            // queryを実行
            Contract(rNode);
        }
    }

    cout << count_nodes(nodes[0]) << endl;

    return 0;
}