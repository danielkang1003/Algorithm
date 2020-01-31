#include<iostream>
#include<algorithm>

using namespace std;

int tc, n, m;
int map[15][15];
int maxKill;

int cnt(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + m; i++)
		for (int j = y; j < y + m; j++)
			cnt += map[i][j];

	return cnt;
}

int killFly() {
	maxKill = 0;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			maxKill = max(maxKill, cnt(i, j));
		}
	}

	return maxKill;
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		memset(map, 0, sizeof(map));
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		int result = killFly();
		cout << "#" << t << ' ' << result << '\n';
	}
	return 0;
}