#include <bits/stdc++.h>
using namespace std;

struct Node {
    int number;
    Node* forward;
    Node* backward;
    Node(int number, Node* forward=NULL): number(number), forward(forward){
        if(forward) forward->backward = this;
    }
};

int Overtake(Node* node){
    Node* fNode = node->forward;
    if (!fNode) return -1;

    Node* ffNode = fNode->forward;
    Node* bNode = node->backward;

    if (bNode) bNode->forward = fNode;
    fNode->backward = bNode;
    node->backward = fNode;
    fNode->forward = node;
    if (ffNode) ffNode->backward = node;
    node->forward = ffNode;
    return fNode->number;
}

void Dropout(Node* node){
    Node* fNode = node->forward;
    Node* bNode = node->backward;
    if (fNode) fNode->backward = bNode;
    if (bNode) bNode->forward = fNode;
    node->forward = NULL;
    node->backward = NULL;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<Node*> nodes(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
        if (i) nodes[A[i]] = new Node(A[i], nodes[A[i-1]]);
        else nodes[A[i]] = new Node(A[i]);
    }

    int Q;
    cin >> Q;
    while(Q--){
        int query;
        cin >> query;
        if (query == 0) {
            int v;
            cin >> v;
            int answer = Overtake(nodes[v]);
            if (answer < 0) cout << "Error" << endl;
            else cout << answer << endl;
        } else if (query == 1) {
            int v;
            cin >> v;
            Dropout(nodes[v]);
        }
    }
    return 0;
}