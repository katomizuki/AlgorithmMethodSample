#include <bits/stdc++.h>
using namespace std;

int sum(int num, int total) {
    if (num == 0) return total;
    return sum(num - 1, total + num);
}

int main() {
    int N;
    cin >> N;
    cout << sum(N, 0);
    return 0;
}