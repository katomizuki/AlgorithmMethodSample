#include <iostream>
using namespace std;

double f(double x) {
    return x*(x*(x+1)+2)+3;
}

int main() {
    double N;
    cin >> N;

    double left = 0;
    double right = 100;
    while (right-left>1e-4) {
        double mid = (left+right)/2;
        if (f(mid)<N) { // もっと大きい(midより大きい)
            left = mid;
        } else { // もっと小さい(midより小さい)
            right = mid;
        }
    }

    double ans = left;
    cout << ans << endl;
    return 0;
}