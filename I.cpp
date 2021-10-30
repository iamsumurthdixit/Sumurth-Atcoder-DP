#include <bits/stdc++.h>
#define deb(x) cerr<<"{ "<<#x<<": "<<x<<" }"<<endl;
using namespace std;

double dp[3005][3005];

double coins(double arr[], int i, int x) {
	if(x == 0) return 1; 
	if(i == 0) return 0; 

	if(dp[i][x] > -0.9) return dp[i][x];

	return dp[i][x] = arr[i] * coins(arr, i - 1, x - 1) + (1 - arr[i]) * coins(arr, i - 1, x);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n; 
	double arr[n + 1]; 
	for(int i = 1; i <= n; i++) cin >> arr[i]; 

	memset(dp, -1, sizeof(dp));

	cout << fixed << setprecision(10) << coins(arr, n, (n + 1) / 2);	
}