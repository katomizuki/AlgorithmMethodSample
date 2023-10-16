#include <bits/stdc++.h>
using namespace std;

int sum(int num , int total, int limit) {
    if (num == limit) return total + num;
    return sum(num + 1, total + num, limit);
}

int main() {
    int A, B;
    cin >> A >> B;
    cout << sum(A, 0, B) << endl;
    return 0;
}