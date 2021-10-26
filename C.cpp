#include <bits/stdc++.h>
#define deb(x) cerr<<"{ "<<#x<<": "<<x<<" }"<<endl;
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	vector<vector<int>> arr(n, vector<int>(3, 0));
	for(int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	vector<vector<int>> dp(n, vector<int>(3, 0)); 

	for(int i = 0; i < 3; i++) {
		dp[0][i] = arr[0][i];
	}

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			if(j - 1 >= 0) 
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			if(j - 2 >= 0) 
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 2]);
			if(j + 1 < 3)
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
			if(j + 2 < 3) 
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 2]);
			dp[i][j] += arr[i][j];
		}
	}

	int ans = 0; 
	for(int i = 0; i < 3; i++) {
		ans = max(ans, dp[n - 1][i]);
	}
	cout << ans; 
}