#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

// Xは長さを表す。これがKをこえていればまだまだXは伸びしろがあるということなのでMain（）で範囲を狭めている。
int f(double x, vector<double> L) {
    double ans = 0;
    for (double l: L) {
        ans += (int)(l / x);
    }
    return ans;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<double> L(N);
    for (int i=0; i<N; i++) cin >> L[i];


    double left = 0;
    double right = 2e5;
    while (right-left>1e-8) {
        double mid = (left+right)/2;
        // 全探索する
        if (f(mid,L) >= K) { // もし f(mid,L)>=K ならば答えは mid 以上 right 以下
            left = mid; // 範囲を狭める
        }
        else {
            right = mid;
        }
    }

    double ans = left;
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}