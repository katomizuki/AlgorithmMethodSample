#include <bits/stdc++.h>
#include <vector>
using namespace std;

// 配列の中身を表示する関数
void output(vector<int> A) {
    for (int i=0; i<A.size(); i++) {
        cout << A[i];
        if (i!=A.size()-1) cout << " ";
        else cout << endl;
    }
}

void quick_sort(vector<int> &v) {
    if (v.size() == 0) return;

    vector<int> L, R;

// 1
    int X = v.size() / 2;

    for (int i = 0; i < v.size(); i++) {
        if (i == X) continue;
        else if (v[i] < v[X]) L.push_back(v[i]);
        else R.push_back(v[i]);
    }

// 2
    quick_sort(L);
    quick_sort(R);
// 3
    L.push_back(v[X]);
    L.insert(L.end(), R.begin(), R.end());
    v = L;
}


int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    quick_sort(A);

    output(A);
    return 0;
}