#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
//int d[1001];
//int fibo(int n) {
//	if (n == 1) return 1;
//	if (n == 2) return 2;
//	if (d[n] != 0) return d[n];
//	return d[n] = (fibo(n - 1) + fibo(n - 2)) % 10007;
//
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int res = fibo(n);
//	cout << res;
//}


int dp[1001];
int main(){
	int n;
	cin >> n;
	//그림을 그려보면 n = 1일때 1개
	//n = 2일 때 2개
	//n = 3일 때 3개가 나온다.
	//점화식은 i = 4일때부터
	//타일 i의 방법 = 타일 i -1 의 방법 + 타일 i-2의 방법을 더해준다.
	dp[1] = 1, dp[2] = 2; dp[3] = 3;
	for (int i = 4; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	cout << dp[n];
	return 0;
}