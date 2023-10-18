#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double calc(vector<double> to, vector<double> from) {
    return sqrt((from[0] - to[0])*(from[0] - to[0]) + (from[1] - to[1])*(from[1] - to[1]));
}

int main() {
    int N;
    cin >> N;
    vector<vector<double>> T(N);
    for (int i = 0; i < N; i++) {
        double X, Y;
        cin >> X >> Y;
        vector<double> point = { X, Y };
        T[i] = point;
    }

    double res = 0.0;

    vector<bool> used(N, false);
    used[0] = true;

    vector<double> currentPoint = T[0];

    for (int i = 0; i < N - 1; ++i) {
        int nex = -1;
        double min_dis = 1000000;
        for (int j = 0; j < N; ++j) {

            if (used[j]) continue;
            double dis = calc(T[j], currentPoint);
            if (min_dis > dis) {
                min_dis = dis;
                nex = j;
            }
        }

        used[nex] = true;
        res += min_dis;
        currentPoint = T[nex];
    }


    res += calc(T[0], currentPoint);

    // 小数点出力
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}