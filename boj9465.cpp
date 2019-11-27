#include<iostream>
#include<algorithm>
using namespace std;

int sticker[2][100000], dp[2][100000];
int n, t;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		//스티커 배열에 넣기
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> sticker[i][j];

		//기저 사례
		//가장 첫번쨰 수들은 sticker에 있는 값으로 저장
		//그 이후 옆의 숫자는 대각선 + sticker의 값으로 설정
		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = dp[1][0] + sticker[0][1];
		dp[1][1] = dp[0][0] + sticker[1][1];

		//2부터 돌면서 max 값을 찾아준다.
		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
		}
		//최대값 출력해주면 끝!
		int result = max(dp[0][n - 1], dp[1][n - 1]);
		cout << result <<'\n';
	}

	return 0;
}