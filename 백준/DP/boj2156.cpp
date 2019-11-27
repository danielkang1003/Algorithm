#include<iostream>
#include<algorithm>

using namespace std;

int wine[10001];
int dp[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> wine[i];
	

	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];
	if (n == 1) {
		cout << wine[1];
		return 0;
	}

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n];


	return 0;
}

/*
//메모리를 너무 많이 잡길래 백준 순위권에 있는
//랭커 코드를 봤는데 이런 식으로 간단히 하는 걸 보고 놀람...

#include<iostream>

using namespace std;

int MAX(int a, int b) {
	return a > b ? a : b;
}

int wine[10001], dp[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> wine[i];

	dp[0] = 0, dp[1] = wine[1], dp[2] = wine[2] + wine[1];
	for (int i = 3; i <= n; i++) {
		dp[i] = MAX(dp[i - 2] + wine[i], MAX(dp[i - 1], dp[i - 3] + wine[i - 1] + wine[i]));
	}
	cout << dp[n];
	return 0;
}
*/
