#include<iostream>
#include<algorithm>
using namespace std;

int n, k, s, y;
int student[2][7];	//s: ������ 0 (��) �Ǵ� 1(��)  y: 1~6�г�

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> s >> y;
		student[s][y]++;
	}
	int cnt = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 1; j <= 6; j++) {
			cnt += (student[i][j] / k);
			if (student[i][j] % k != 0) cnt++;
		}
	}
	cout << cnt;

	return 0;
}