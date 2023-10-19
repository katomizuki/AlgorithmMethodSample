#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    long long count = 0;
    for (int i = 0; i < N; i++) {
        count += min(N, K/(i+1))
    }

    cout << count << endl;
    return 0;
}