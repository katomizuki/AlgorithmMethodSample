#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
    int N; cin >> N;
    map<string, int> hashMap;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        A[i] = S;
        hashMap[S] = 0;
    }

    for (int i = 0; i < A.size(); i++) hashMap[A[i]]++;

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        string T; cin >> T;
        cout << hashMap[T] << endl;
    }
    return 0;
}