#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int answer = 0;
    while (N) {
        answer++;
        if (N % 3 == 0) N /= 3;
        else --N;
    }
    cout << answer << endl;
}