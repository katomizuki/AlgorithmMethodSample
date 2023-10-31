#include <bits/stdc++.h>
using namespace std;

int main() {
    string N; cin >> N;
    int X; cin >> X;
    stack<int> numbers;
    for (int i = 0; i < X; i++) {
        string S; cin >> S;
        if(S == "+" || S == "-" || S == "*") {
        // 今見ている文字列が演算子ならば、スタックから数字を 2 つ取り出して計算結果をスタックに入れる
            int n2 = numbers.top(); numbers.pop();
            int n1 = numbers.top(); numbers.pop();
            int n;

            if(S == "+") n = n1 + n2;
            else if(S == "-") n = n1 - n2;
            else if(S == "*") n = n1 * n2;
            numbers.push(n);
        } else {
            int number = stoi(S);
            numbers.push(number);
        }
    }

    cout << N << "=" << numbers.top() << endl;
    return 0;
}