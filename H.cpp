#include <bits/stdc++.h>
#define deb(x) cerr<<"{ "<<#x<<": "<<x<<" }"<<endl;
using namespace std;

const int mod = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int h, w; cin >> h >> w; 
	vector<vector<char>> mat(h, vector<char>(w)); 

	for(int i = 0; i < h; i++) 
		for(int j = 0; j < w; j++) 
			cin >> mat[i][j];
		
	vector<vector<int>> dp(h, vector<int>(w)); 

	dp[0][0] = 1; 
	for(int i = 1; i < w; i++) {
		if(mat[0][i] == '.') dp[0][i] = 1;
		else break;
	}
	
	for(int i = 1; i < h; i++) {
		if(mat[i][0] == '.') dp[i][0] = 1; 
		else break;
	}

	for(int i = 1; i < h; i++) {
		for(int j = 1; j < w; j++) {
			if(mat[i][j] == '.') {
				dp[i][j] += dp[i - 1][j] % mod; 
				dp[i][j] += dp[i][j - 1] % mod;
			}
		}
	}
	cout << dp[h - 1][w - 1] % mod;
}