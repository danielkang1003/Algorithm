#include<iostream>

using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;
	//Ÿ���� 2 x 1 �� ���� 1�� �ۿ� ���� �ʴ´�.
	//�ΰ� �� ���� 1���� �� ��� 1�� 2 x 2 Ÿ�� 1��  1 x 2 Ÿ�� �ΰ��� �� 3������� �����ϴ�
	//Ÿ���� 3������ �׷����ϱ� 1 x 2 Ÿ�ϰ� 2 x 2 Ÿ����
	// i -2 ��° Ÿ�Ͽ� �پ ���� �� �ִ�. �׷��� *2��
	//dp[i-2] �� ���־���.
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	cout << dp[n];
	return 0;
}