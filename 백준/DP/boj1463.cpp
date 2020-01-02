#include<iostream>

using namespace std;

int x;
int dp[1000000];

int min(int a, int b) {
	return a > b ? b : a;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> x;
	dp[1] = 0;
	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
			//cout <<"DP[" << i << "]ดย "<< dp[i] << '\n';
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
			//cout << "DP[" << i << "]ดย " << dp[i] << '\n';
		}
	}
	cout << dp[x] << '\n';

	return 0;
}