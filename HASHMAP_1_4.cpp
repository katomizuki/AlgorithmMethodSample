#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
    int N; cin >> N;
    map<string, int> hashMap;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        string a; cin >> a;
        hashMap[a] = 0;
        A[i] = a;
    }

    for (int i = 0; i < N; i++) hashMap[A[i]]++;
    

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        string T; cin >> T;
        if (query == 0) {
            hashMap[T]++;
        } else if (query == 1) {
            hashMap[T] = 0;
        } else if (query == 2) {
            cout << hashMap[T] << endl;
        }
    }
    return 0;
}