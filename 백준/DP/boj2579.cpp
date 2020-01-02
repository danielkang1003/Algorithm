#include<iostream>

using namespace std;

int stair[301], dp[301];
int num;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> stair[i];	//시작점 i = 0은 0이다.
	}

	dp[1] = stair[1];
	dp[2] = dp[1] + stair[2];	//무조건 전 계단을 밟고 2번 계단을 밟아야 수가 크다. 그러므로 dp[2]가 stair[2]일 때는 생각 안해주어도 됨
	for (int i = 3; i <= num; i++) {
		/*
		비교 대상은 dp[i-2] + stair[i] : 두칸전 계단을 밟고, 현재 계단
					dp[i-3] + stair[i-1] + stair[i] : 세번째 계단을 밟고 연속으로 지금 전의 계단과
					현재 계단을 밟은 것.
					큰값을 비교해서 배열에 메모해주기
		*/
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}
	cout << dp[num];
	return 0;
}