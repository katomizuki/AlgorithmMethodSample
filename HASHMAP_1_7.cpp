#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    unordered_map<int, int> hashMap;
    for (int i = 0; i < N; i++) {
        int A; cin >> A;
        hashMap[A]++;
    }

    int answer = 0;
    for(auto v: hashMap) 
        if (v.second != 1) 
            answer += (v.second - 1);
        
    

    cout << answer << endl;
    return 0;
}