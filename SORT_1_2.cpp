#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

void output(vector<int> A) {
    for (int i=0; i<A.size(); i++) {
        cout << A[i];
        if (i!=A.size()-1) cout << " ";
        else cout << endl;
    }
}


int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int k = 0; k < N-1; k++) {
        auto ele = min_element(A.begin()+k, A.end());
        swap(A[k], *ele);
        output(A);
    }
    return 0;
}

