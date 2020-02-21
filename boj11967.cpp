#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
bool map[101][101];
bool check[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<pair<pair<int, int>, pair<int, int>>> v;

bool isLightOn(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 1 || ny < 1 || nx >= n + 1 || ny >= n + 1) continue;
		if (check[nx][ny] == 1) return 1;
	}
	return 0;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	map[1][1] = 1;
	check[1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < v.size(); i++) {
			int nx = v[i].first.first;
			int ny = v[i].first.second;
			int nxOn = v[i].second.first;
			int nyOn = v[i].second.second;
			if (x == nx && y == ny) {
				if (check[nxOn][nyOn] == 1) continue;
				if (isLightOn(nxOn, nyOn) == 1) {
					q.push({ nx,ny });
					check[nx][ny] = 1;
				}
			}
			map[nxOn][nyOn] = 1;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 1 || ny < 1 || nx >= n + 1 || ny >= n + 1) continue;
			if (map[nx][ny] == 0 || check[nx][ny] == 1) continue;
			check[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> n >> m;
	while (m--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v.push_back({ {x,y},{a,b} });
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j] == 1) cnt++;
	cout << cnt;
	return 0;
}