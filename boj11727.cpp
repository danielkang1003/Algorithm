#include<iostream>

using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;
	//타일이 2 x 1 일 때는 1개 밖에 되지 않는다.
	//두개 일 때는 1개일 떄 방법 1과 2 x 2 타일 1개  1 x 2 타일 두개로 총 3방법으로 가능하다
	//타일을 3개까지 그려보니까 1 x 2 타일과 2 x 2 타일이
	// i -2 번째 타일에 붙어서 나올 수 있다. 그래서 *2를
	//dp[i-2] 에 해주었다.
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	cout << dp[n];
	return 0;
}
