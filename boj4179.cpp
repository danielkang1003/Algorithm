#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int r, c;
char map[1001][1001];
bool check[1001][1001];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

pair<int, int> jh;
vector<pair<int, int>> fire;

void bfs() {
	queue<pair<int, int>> fireQ;
	for (int i = 0; i < fire.size(); i++) {
		fireQ.push(fire[i]);
	}
	queue<pair<pair<int, int>, int>> q;
	q.push({ {jh.first, jh.second}, 0 });	//지훈 x,y, 이동 거리
	check[jh.first][jh.second] = 1;
	while (!q.empty()) {
		int fs = fireQ.size();
		for (int i = 0; i < fs; i++) {
			int x = fireQ.front().first;
			int y = fireQ.front().second;
			fireQ.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (map[nx][ny] == '#') continue;
				if (map[nx][ny] == 'F') continue;
				fireQ.push({ nx,ny });
				map[nx][ny] = 'F';
			}
		}
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			if (x == 0 || y == 0 || x == r - 1 || y == c - 1) {
				cout << cnt + 1 << '\n';
				return;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (check[nx][ny] == 1) continue;
				if (map[nx][ny] == '#') continue;
				if (map[nx][ny] == 'F') continue;
				q.push({ {nx,ny}, cnt + 1 });
				check[nx][ny] = 1;
				map[nx][ny] = 'J';
			}
		}
		/*for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}*/
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') jh.first = i, jh.second = j;
			else if (map[i][j] == 'F') fire.push_back({ i,j });
		}
	}
	bfs();
	return 0;
}