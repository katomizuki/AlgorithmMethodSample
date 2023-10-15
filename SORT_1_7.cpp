#include <bits/stdc++.h>
#include <vector>
using namespace std;

void output(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size()-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

void ready_heap(vector<int> &v) {
    for (int x=v.size()/2-1; x>=0; x--) {
        int k = x;
        while(true) {
            int left = 2*k+1<v.size() ? v[2*k+1] : 0;
            int right = 2*k+2<v.size() ? v[2*k+2] : 0;

            if (!left && !right) {
                break;
            } else if (v[k]>=left && v[k]>=right) {
                break;
            } else if (left>=right) {
                swap(v[k], v[2*k+1]);
                k = 2*k+1;
            } else {
                swap(v[k], v[2*k+2]);
                k = 2*k+2;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ready_heap(A);
    output(A);
    return 0;
}