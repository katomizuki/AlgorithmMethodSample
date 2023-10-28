#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> counter(100001, 0);
    long long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total += A[i];
        counter[A[i]]++;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;

        if (query == 0) {
            int v;
            cin >> v;
            counter[v]++;
            total += v;
        } else if (query == 1) {
            int x, y;
            cin >> x >> y;
            total -= (long long) counter[x] * x;
            total += (long long) counter[x] * y;
            counter[y] += counter[x];
            counter[x] = 0;
        } else if (query == 2) {
            cout << total << endl;
        }
    }
    return 0;
}