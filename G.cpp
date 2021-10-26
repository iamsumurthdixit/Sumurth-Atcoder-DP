#include <bits/stdc++.h>
#define deb(x) cerr<<"{ "<<#x<<": "<<x<<" }"<<endl;
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string s, t; 
	cin >> s >> t; 
	int n = s.length(), m = t.length(); 

	vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0)); 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i - 1] == t[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string ans; 
	int i = n, j = m; 
	while(i > 0 and j > 0) {
		if(s[i - 1] == t[j - 1]) {
			ans += s[i - 1];
			i--; 
			j--;
		} else if(dp[i - 1][j] > dp[i][j - 1]) {
			i--; 
		} else {
			j--;
		}
	}
	reverse(ans.begin(), ans.end()); 
	cout << ans;
}