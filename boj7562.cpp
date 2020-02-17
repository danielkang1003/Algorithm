#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int tc, l;
int sx, sy, ex, ey;

int map[300][300];
bool check[300][300];

int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };

void print() {
	cout << "########################\n";
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "########################\n";
}

void bfs(int sx, int sy) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {sx,sy}, 0 });
	check[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		//cout << "ÇöÀç °ª x: " << x << " y: " << y << " cnt: " << cnt << '\n';
		if (x == ex && y == ey) {
			//print();
			cout << cnt << '\n';
			return;
		}
		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
			if (check[nx][ny] == 1) continue;
			map[nx][ny] = map[x][y] + 1;
			check[nx][ny] = 1;
			q.push({ {nx,ny}, cnt + 1 });
		}

	}
}

int main() {
	cin >> tc;
	while (tc--) {
		cin >> l;
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		cin >> sx >> sy >> ex >> ey;
		bfs(sx, sy);
		//cout << map[ex][ey] << '\n';
	}

	return 0;
}