#include<iostream>
#include<queue>

using namespace std;

int n, m;
int map[500][500];
bool check[500][500];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;

void bfs(int i, int j, int cnt) {
	int area = 0;
	queue<pair<int, int>> q;
	q.push({ i, j });
	check[i][j] = 1;
	map[i][j] = cnt;
	while (!q.empty()) {
		area++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0) continue;
			if (check[nx][ny] == 1) continue;
			map[nx][ny] = cnt;
			check[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	if (answer < area) answer = area;
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {

				bfs(i, j, cnt++);
			}
		}
	}
	//print();
	cout << cnt - 1 << '\n' << answer << '\n';
	return 0;
}