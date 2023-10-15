#include <bits/stdc++.h>
#include <vector>
using namespace std;

mt19937 mt;

void output(vector<int> A) {
    for (int i=0; i<A.size(); i++) {
        cout << A[i];
        if (i!=A.size()-1) cout << " ";
        else cout << endl;
    }
}

int random_int(int N) {
    return mt() % N;
}


void quick_sort(vector<int> &v) {
    if (v.size() == 0) return;

    vector<int> L, R;
    int X = random_int(v.size());
    for (int i=0; i<v.size(); i++) {
        if (i==X) continue;
        if (v[i]==v[X]) {
            if (random_int(2)) L.push_back(v[i]);
            else R.push_back(v[i]);
        }
        else if (v[i]<v[X]) L.push_back(v[i]);
        else R.push_back(v[i]);
    }

    quick_sort(L);
    quick_sort(R);
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