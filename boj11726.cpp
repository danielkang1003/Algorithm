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
	//�׸��� �׷����� n = 1�϶� 1��
	//n = 2�� �� 2��
	//n = 3�� �� 3���� ���´�.
	//��ȭ���� i = 4�϶�����
	//Ÿ�� i�� ��� = Ÿ�� i -1 �� ��� + Ÿ�� i-2�� ����� �����ش�.
	dp[1] = 1, dp[2] = 2; dp[3] = 3;
	for (int i = 4; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	cout << dp[n];
	return 0;
}