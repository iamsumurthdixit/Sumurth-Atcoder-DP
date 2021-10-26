#include <bits/stdc++.h>
#define deb(x) cerr<<"{ "<<#x<<": "<<x<<" }"<<endl;
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n; 
	vector<int> h(n), dp(n,0);
	for(int i = 0; i < n; ++i) cin >> h[i];
	
	dp[0] = 0; dp[1] = abs(h[1] - h[0]);

	for(int i = 2; i < n; i++) {
		dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
		// deb(dp[i])
	}
	cout << dp[n - 1]; 
}