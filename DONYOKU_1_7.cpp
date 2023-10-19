#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	    int N;
	        cin >> N;
		    vector<vector<int>> A(N);
		        for (int i = 0; i < N; i++) {
				        int S,T;
					        cin >> S >> T;
						        vector<int> yotei = { S, T };
							        A[i] = yotei;
								    }
			 
			    sort(A.begin(), A.end(), [](const vector<int>& a, const vector<int>& b) {
					            return a[1] < b[1]; 
						        });

			        int answer = 0;
				    int last_time = 0; 
				        for (int i = 0; i < A.size(); i++) {
						        vector<int> yotei = A[i];
							        if (yotei[0] < last_time) continue;

								        answer++;
									        last_time = yotei[1];
										    }
					    cout << answer << endl;
					        return 0;
}
