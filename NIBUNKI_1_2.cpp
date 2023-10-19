#include <iostream>
using namespace std;

double f(double N, double x) {
    double ans = N + 1;
    for (int i=0; i<5; i++) {
        ans = ans * x + 1;
    }
    return ans;
}

int main() {
    double N, M; cin >> N >> M;

    double left = 0, right = 100;
    while (right-left>1e-4) {
        double mid = (left+right)/2;
        if (f(N,mid)<M) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    double ans = left;
    cout << ans << endl;
    return 0;
}