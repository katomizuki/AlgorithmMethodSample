#include <bits/stdc++.h>
#include <vector>
using namespace std;

int func(int n, int l, int r) {
    if (n==0) return 1;
    if (l>r) return 0;
    int ans = func(n-1,l+1,r) + func(n,l+1,r);
    return ans;
}

int main() {
    int N, L, R;
    cin >> N >> L >> R;

    cout << func(N, L,R) << endl;
    return 0;
}