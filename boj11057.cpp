#include<iostream>

using namespace std;

int dp[1001][10];
int n, sum = 0;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	//n 길이가 1일 때 0 부터 9까지 모두 가능하므로 1 로 세팅
	for (int i = 0; i < 10; i++) dp[1][i] = 1;

	//n 길이가 2 이상부터는 뒷자리 수가 앞자리 수 보다 낮으면
	//계산을 하면 안되므로 k로 처리.
	//dp[n][j] 는 n 자리수의 마지막 수가 j 인 오르막 수의 갯수를 뜻함.
	//점화식은 dp[i][j] = dp[i-1][k] 이고, k는 0부터 j 까지 처리
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][k] += dp[i - 1][j];
				dp[i][k] %= 10007;
			}
		}
	}
	for (int i = 0; i < 10; i++) sum += dp[n][i];
	cout << sum % 10007 << '\n';
	return 0;
}
