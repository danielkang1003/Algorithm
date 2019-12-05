#include<iostream>

using namespace std;

int n, ans;
int col[15], increase[30], decrease[30];
// 열 파악,  증가하는 대각선, 감소하는 대각선
// 각 크기는 n 만큼, 2*n -1만큼 대각선에 부여
// 편의상 -1은 적용안하고 2n까지만 해서 적용

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