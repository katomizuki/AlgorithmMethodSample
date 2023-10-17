#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> func(int N, int L, int R) {
    if (L > R) {
        return {};
    }

    if (N == 0) {
        return {{}};
    }

    vector<vector<int>> ans;

    for (auto x: func(N-1, L, R)) {
        vector<int> to = {L};
        to.insert(to.end(), x.begin(), x.end());
        ans.push_back(to);
    }

    for (auto x: func(N,L+1,R)) {
        ans.push_back(x);
    }

    return ans;
}

int main() {
    int N, L, R;
    cin >> N >> L >> R;

    vector<vector<int>> ans = func(N,L,R);
    for (vector<int> x: ans) {
        for (int i = 0; i<x.size(); i++) {
            cout << x[i];
            if (i!=x.size()-1) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}