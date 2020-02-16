#include<iostream>
#include<queue>

using namespace std;

int n, m;
int map[100][100];
bool check[100][100];

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
		if (x == n - 1 && y == m - 1) {
			cout << map[n - 1][m - 1] << '\n';
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] == 1) continue;
			if (map[nx][ny] == 0) continue;
			map[nx][ny] = map[x][y] + 1;
			check[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%1d", &map[i][j]);
	bfs(0, 0);
	//print();

	return 0;
}