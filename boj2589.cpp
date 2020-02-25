#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

int n, m;
char map[50][50];
bool check[50][50];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int answer = 0;

void bfs(int i, int j) {
	int dist = 0;
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int s = 0; s < size; s++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (check[nx][ny] == 1) continue;
				if (map[nx][ny] == 'W') continue;
				q.push({ nx,ny });
				check[nx][ny] = 1;
			}
		}
		++dist;
	}
	if (answer < dist - 1) answer = dist - 1;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				memset(check, 0, sizeof(check));
				bfs(i, j);
			}
		}
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	input();
}