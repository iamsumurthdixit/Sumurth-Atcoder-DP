#include <bits/stdc++.h>
#define deb(x) cerr<<"{ "<<#x<<": "<<x<<" }"<<endl;
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	const int INF = 1e9 + 5; 

	int n, k; cin >> n >> k; 
	vector<int> h(n), dp(n, INF); 
	for(int & i: h) cin >> i; 

	dp[0] = 0; 

	// PUSH DP

	// for(int i = 0; i < n; i++) {
	// 	for(int j = i + 1; j <= i + k; j++) {
	// 		if(j < n)
	// 			dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
	// 	}
	// }

	// WITHOUT PUSH DP

	for(int i = 0; i < n; i++) {
		for(int j = i - 1; j >= i - k; j--) {
			if(j >= 0) {
				dp[i] = min(dp[i], abs(h[i] - h[j]) + dp[j]);
			}
		}
	}
	
	// for(int i : dp) cout << i << " "; cout << endl; 
	cout << dp[n - 1]; 
}