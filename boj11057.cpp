#include<iostream>

using namespace std;

int dp[1001][10];
int n, sum = 0;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	//n ���̰� 1�� �� 0 ���� 9���� ��� �����ϹǷ� 1 �� ����
	for (int i = 0; i < 10; i++) dp[1][i] = 1;

	//n ���̰� 2 �̻���ʹ� ���ڸ� ���� ���ڸ� �� ���� ������
	//����� �ϸ� �ȵǹǷ� k�� ó��.
	//dp[n][j] �� n �ڸ����� ������ ���� j �� ������ ���� ������ ����.
	//��ȭ���� dp[i][j] = dp[i-1][k] �̰�, k�� 0���� j ���� ó��
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
