#include<iostream>
#include<algorithm>
using namespace std;

int sticker[2][100000], dp[2][100000];
int n, t;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		//��ƼĿ �迭�� �ֱ�
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> sticker[i][j];

		//���� ���
		//���� ù���� ������ sticker�� �ִ� ������ ����
		//�� ���� ���� ���ڴ� �밢�� + sticker�� ������ ����
		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = dp[1][0] + sticker[0][1];
		dp[1][1] = dp[0][0] + sticker[1][1];

		//2���� ���鼭 max ���� ã���ش�.
		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
		}
		//�ִ밪 ������ָ� ��!
		int result = max(dp[0][n - 1], dp[1][n - 1]);
		cout << result <<'\n';
	}

	return 0;
}