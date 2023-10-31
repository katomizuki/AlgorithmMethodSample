#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N, -1);

    int head = 0;
    int tail = 0;

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        if (query == 0) {
            int v; cin >> v;
            A[tail] = v;
            tail++;
            if (tail == N) tail = 0;
        } else if (query == 1) {
            A[head] = -1;
            head++;
            if (head == N) head = 0;
        }
    }

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << endl;
    }
    return 0;
}