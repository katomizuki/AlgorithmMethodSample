#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 0;
    while (N > 0) {
        count++;
        if (N % 2 == 0) N /= 2;
        else N--;
    }
    cout << count << endl;
    return 0;
}