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

vector<pair<int, int>> fire;
pair<int, int> me;

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


void print() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}


void bfs() {
	queue<pair<int, int>> fireMove;	//불 넣어주기
	for (int i = 0; i < fire.size(); i++) {
		fireMove.push(fire[i]);
	}
	queue<pair<pair<int, int>, int>> q;	//상근 첫 시작 넣어주기
	q.push({ {me.first, me.second}, 0 });	//상근 좌표 x, y, 이동 거리

	while (!q.empty()) {
		//주변에 불을 먼저 붙인다
		int size = fireMove.size();
		//cout << "불이 번질 크기: " << size << '\n';
		for (int i = 0; i < size; i++) {
			int x = fireMove.front().first;
			int y = fireMove.front().second;
			fireMove.pop();
			//cout << "불 정보 x: " << x << " y: " << y << '\n';
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (map[nx][ny] != '.') continue;
				//cout << "이동 가능한 불 nx: " << nx << " ny: " << ny << '\n';
				map[nx][ny] = map[x][y];
				fireMove.push({ nx,ny });
			}
		}
		//상근 움직임. 계속 자리를 이동하면서 큐에 넣었다 뺏다 반복할것임
		size = q.size();
		//cout << "상근의 이동: " << size << '\n';
		for (int i = 0; i < size; i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cnt = q.front().second;
			q.pop();
			//cout << "상근 현재 좌표 x: " << x << " y: " << y << " 이동 거리: " << cnt<< '\n';
			if (x == 0 || y == 0 || x == h - 1 || y == w - 1) {
				cout << cnt + 1 << '\n';
				return;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (check[nx][ny] == 1) continue;
				if (map[nx][ny] == '*') continue;
				if (map[nx][ny] == '#') continue;
				//cout << "상근 다음 경로 nx: " << nx << " ny: " << ny << '\n';
				check[nx][ny] = 1;
				//map[nx][ny] = '@';
				q.push({ {nx, ny}, cnt + 1 });
			}
		}
		//print();
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	cin >> tc;
	while (tc--) {
		init();
		input();
		bfs();
	}
	return 0;
}