#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int tc, n, m, k;
int map[50][50];
bool check[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	check[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] == 1) continue;
			if (map[nx][ny] == 0) continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
		}
	}
}

int main() {
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> y >> x;
			map[x][y] = 1;
		}
		int answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && check[i][j] == 0) {
					bfs(i, j);
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}

	return 0;
}