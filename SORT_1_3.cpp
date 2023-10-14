#include <bits/stdc++.h>
#include <vector>
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

    for (int k = 1; k < N; k++) {
        int pos = k;
        while(pos > 0) {
            if (A[pos-1]>A[pos]) swap(A[pos-1], A[pos]);
            pos--;
        }
        output(A);
    }
    return 0;
}