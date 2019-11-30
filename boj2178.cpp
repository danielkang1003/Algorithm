#include<iostream>
#include<queue>

using namespace std;

int maze[100][100];
int check[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;

void bfs(int i, int j) {
	queue<pair<int, int>>q;
	q.push({ i,j });
	check[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (check[nx][ny] == 1 || maze[nx][ny] == 0)
				continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
			maze[nx][ny] = maze[x][y] + 1;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	bfs(0, 0);
	cout << maze[n - 1][m - 1];
	return 0;
}