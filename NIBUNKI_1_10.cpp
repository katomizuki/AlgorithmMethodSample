#include <iostream>
using namespace std;

long long f(long long N, long long K) {
    long long count = 0;
    for (int i=0; i<N; i++) {
        count += min(N, K/(i+1));
    }
    return count;
}

int main() {
    long long N, X;
    cin >> N >> X;

    long long left = 0;
    long long right = N*N;
    while (left!=right) {
        long long mid = (left + right) / 2;
        //　Xより大きければ範囲を狭くする。
        if (f(N,mid) >= X) {
            right = mid;
        } else {
            left = mid+1;
        }
    }

    long long ans = left;
    cout << ans << endl;
}