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
		cin >> stair[i];	//������ i = 0�� 0�̴�.
	}

	dp[1] = stair[1];
	dp[2] = dp[1] + stair[2];	//������ �� ����� ��� 2�� ����� ��ƾ� ���� ũ��. �׷��Ƿ� dp[2]�� stair[2]�� ���� ���� �����־ ��
	for (int i = 3; i <= num; i++) {
		/*
		�� ����� dp[i-2] + stair[i] : ��ĭ�� ����� ���, ���� ���
					dp[i-3] + stair[i-1] + stair[i] : ����° ����� ��� �������� ���� ���� ��ܰ�
					���� ����� ���� ��.
					ū���� ���ؼ� �迭�� �޸����ֱ�
		*/
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}
	cout << dp[num];
	return 0;
}