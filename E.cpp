#include <bits/stdc++.h>
#define deb(x) cerr<<"{ "<<#x<<": "<<x<<" }"<<endl;
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, w; cin >> n >> w; 
	vector<int> wt(n), val(n); 
	for(int i = 0; i < n; i++) 
		cin >> wt[i] >> val[i];

	int val_sum = 0; 
	for(int i = 0; i < n; ++i) val_sum += val[i];

	const int INF = 1e9 + 9; 
	vector<vector<int>> dp(n + 1, vector<int>(val_sum + 1, INF));

	for(int i = 0; i <= n; i++) { // only this will be the base case, to make profit 0, 0 weight is needed
		dp[i][0] = 0; 
	}

	for(int i = 1; i <= n; i++) { 
		for(int j = 1; j <= val_sum; j++) {
			if(val[i - 1] > j) 
				dp[i][j] = dp[i - 1][j];
			else 
				dp[i][j] = min(dp[i - 1][j], wt[i - 1] + dp[i - 1][j - val[i - 1]]);
		}
	}
	int max_valid_val = 0; 
	for(int i = 1; i <= val_sum; i++) {
		if(dp[n][i] <= w) 
			max_valid_val = i; 
	}
	cout << max_valid_val;
}
