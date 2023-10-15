#include <bits/stdc++.h>
#include <vector>
using namespace std;

void output(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i!=A.size()-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

void merge_sort(vector<int> &v) {
    if (v.size() == 0) {
        return;
    }

// 1,2
    int X = v.size() / 2;
    vector<int> L, R;
    copy(v.begin(), v.begin()+X, back_inserter(L));
    copy(v.begin()+X, v.end(), back_inserter(R));


// 3
    if (L.size() >= 2) {
        merge_sort(L);
    }

    if (R.size()>=2) {
        merge_sort(R);
    }

// 4
    reverse(R.begin(), R.end());
    // LとRを結合
    deque<int> dq;
    for (auto x: L) dq.push_back(x);
    for (auto x: R) dq.push_back(x);
    // 空配列を作成
    v.clear();

// 5
    while (dq.size()) {
        if (dq.front()<=dq.back()) {
            v.push_back(dq.front());
            dq.pop_front();
        } else {
            v.push_back(dq.back());
            dq.pop_back();
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    merge_sort(A);

    output(A);

    return 0;
}