#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo;

long long func(long long N) {
    if (memo[N]!=-1) return memo[N];

    if (N==0) return memo[N] = 0;
    if (N==1) return memo[N] = 1;

    return memo[N] = func(N-1) + func(N-2);
}

int main() {
    long long N;
    cin >> N;
    memo.resize(N+1,-1);
    cout << func(N) << endl;
}