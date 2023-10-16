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
//https://www.youtube.com/watch?v=8DIcNEfjfP8
void align_heap(vector<int> &v, int start_pos, int end_pos) {
    int k = start_pos;
    while (true) {
        int left = 2*k+1<end_pos ? v[2*k+1] : 0;
        int right = 2*k+2<end_pos ? v[2*k+2] : 0;

        if (!left && !right) break;
        else if (v[k]>=left && v[k]>=right) break;
        else if (left>=right) {
            swap(v[k], v[2*k+1]);
            k = 2*k+1;
        }
        else {
            swap(v[k], v[2*k+2]);
            k = 2*k+2;
        }
    }
}

void ready_heap(vector<int> &v) {
    for (int x=v.size()/2-1; x>=0; x--) {
        align_heap(v, x, v.size());
    }
}

void exec_heap_sort(vector<int> &v, int end_pos) {
    swap(v[0], v[end_pos]);
    align_heap(v, 0, end_pos);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ready_heap(A);

    for (int i=N-1; i>0; i--) {
        exec_heap_sort(A, i);
        if (i == M) {
            output(A);
        }
    }

    output(A);
    return 0;
}