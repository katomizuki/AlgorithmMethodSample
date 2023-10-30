#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q; cin >> N >> Q;

    vector<vector<int>> isfollower(N, vector<int>(N, 0));
    map<vector<int>, int> counter;
    for (int i = 0; i < N; i++) counter[isfollower[i]]++;
    
    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        if (query == 0) {
            int x, y; cin >> x >> y;
             if(isfollower[y][x] == 0) {
                counter[isfollower[y]]--;
                isfollower[y][x] = 1;
                counter[isfollower[y]]++;
            }
        } else if (query == 1) {
            int x, y; cin >> x >> y;
            if (isfollower[y][x] == 1) {
                counter[isfollower[y]]--;
                isfollower[y][x] = 0;
                counter[isfollower[y]]++;
            }
        } else if (query == 2) {
            int z; cin >> z;
            cout << counter[isfollower[z]] - 1 << endl;
        }
    }
    return 0;
}