#include <bits/stdc++.h>
#define deb(x) cerr<<"{ "<<#x<<": "<<x<<" }"<<endl;
using namespace std;

#define int long long

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int W, n; cin >> n >> W; 
	vector<int> val(n), wt(n); 
	for(int i = 0; i < n; i++) {
		cin >> wt[i] >> val[i];
	}

	vector<vector<int>> dp(n + 1, vector<int> (W + 1, 0)); 

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= W; j++) {
			if(wt[i - 1] > j) 
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i -1][j], dp[i -1][j - wt[i - 1]] + val[i -1]);
		}
	}
	cout << dp[n][W];
}