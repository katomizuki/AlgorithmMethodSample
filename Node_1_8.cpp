#include <bits/stdc++.h>
using namespace std;


#include <iostream>
#include <string>

struct Node {
    char value;
    Node* prev;
    Node* next;
};

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    //vector<Node*> nodes(N);

    Node* head = new Node { S[0], nullptr, nullptr };
    Node* current = head;
    Node* targetNode = head;
    // nodes[0] = head;
    for(int i = 1; i < N; ++i) {
        Node* newNode = new Node { S[i], current, nullptr };
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        if (i == K) {
            targetNode = newNode;
        }
        //  nodes[i] = newNode;
    }
// 現在の場所を先頭に設定してから初期値Kの場所に移動
    // current = nodes[K];
    // for(int i = 0; i < K; ++i) current = current->next;
    int time = 0;
    bool movingRight = true;

// 先頭がNullPtr（左端）末尾がNullPtr（右端）でないかぎり回し続ける。
    while(targetNode->prev != nullptr && targetNode->next != nullptr) {
        time++;
        // 現在の方向に移動。
        if(movingRight) targetNode = targetNode->next;
        else targetNode = targetNode->prev;

        // . だったら動くだけなので分岐必要なし
        // > だったらmovingRightをTrueにして現在の値を動くだけに変更する。
        // < だったらmovingRightをFalseにして現在の値を動くだけに変更する。　
        if (targetNode->value == '>') {
            movingRight = true;
            targetNode->value = '.';
        } else if (targetNode->value == '<') {
            movingRight = false;
            targetNode->value = '.';
        }
    }

    cout << time << endl;

    return 0;
}
