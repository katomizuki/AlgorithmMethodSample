#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    unordered_map<string, int> counter;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        counter[S[i]]++;
    }
    
    cout << counter.size() << endl;
    return 0;
}