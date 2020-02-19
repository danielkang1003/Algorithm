#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int tc, w, h;
char map[1000][1000];
bool check[1000][1000];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

pair<int, int> me;
vector<pair<int, int>> fire;

void init() {
	memset(map, ' ', sizeof(map));
	memset(check, 0, sizeof(check));
	fire.clear();
}

void input() {
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == '@') me.first = i, me.second = j;
			else if (map[i][j] == '*') fire.push_back({ i,j });
		}
	}
}

void bfs() {
	queue<pair<int, int>> q;
	queue<pair<int, int>> onFire;
	q.push({ me.first, me.second });
	for (int i = 0; i < fire.size(); i++) onFire.push(fire[i]);
	int cnt = 0;
	while (!q.empty()) {
		int fireSize = onFire.size();
		for (int i = 0; i < fireSize; i++) {
			int x = onFire.front().first;
			int y = onFire.front().second;
			onFire.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (map[nx][ny] != '.') continue;
				map[nx][ny] = map[x][y];
				onFire.push({ nx,ny });
			}
		}
		int size = q.size();
		for (int i = 0; i < size; i++) {
			//상근 움직임. 계속 자리를 이동하면서 큐에 넣었다 뺏다 반복할것임
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
				cout << cnt + 1 << '\n';
				return;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (check[nx][ny] == 1) continue;
				if (map[nx][ny] == '#') continue;
				if (map[nx][ny] == '*') continue;
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
		cnt++;
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> tc;
	while (tc--) {
		init();
		input();
		bfs();
	}
	return 0;
}