#include<iostream>

using namespace std;

int n, ans;
int col[15], increase[30], decrease[30];
// �� �ľ�,  �����ϴ� �밢��, �����ϴ� �밢��
// �� ũ��� n ��ŭ, 2*n -1��ŭ �밢���� �ο�
// ���ǻ� -1�� ������ϰ� 2n������ �ؼ� ����

void N_Queen(int k) {
	if (k == n) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0 && increase[i + k] == 0 && decrease[n + (k - i) - 1] == 0) {
			col[i] = 1;
			increase[k + i] = 1;
			decrease[n + (k - i) - 1] = 1;
			N_Queen(k + 1);
			col[i] = 0;
			increase[k + i] = 0;
			decrease[n + (k - i) - 1] = 0;
		}
	}
}

int main() {
	cin >> n;
	N_Queen(0);
	cout << ans;
	return 0;
}