#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int r, c;
char map[1500][1500];
bool check[1500][1500];
int movement[1500][1500];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> v[2];

void melting(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//cout << "현재 빙판 좌표 x:" << x << " y: " << y << '\n';
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (check[nx][ny] == 1) continue;
			if (map[nx][ny] == 'L') continue;
			if (map[nx][ny] == '.') {
				map[x][y] = '.';
			}
			if (map[nx][ny] == 'X') {
				q.push({ nx,ny });
				check[nx][ny] = 1;
			}

		}
	}
}

void print() {
	cout << "========MELTING=========\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << "=======================\n";
	cout << "========CHECK=========\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << check[i][j];
		}
		cout << '\n';
	}
	cout << "=====================\n";
	cout << "movement\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << movement[i][j];
		}
		cout << '\n';
	}
}

bool bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	movement[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//cout << "x: " << x << " y :" << y << "입니다\n";
		if (x == v[1].front().first && y == v[1].front().second) {
			//cout << "x: " << x << " y: " << y << "에서 답을 찾았습니다\n";
			return true;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (movement[nx][ny] == 1) continue;
			if (map[nx][ny] != '.') continue;
			q.push({ nx,ny });
			movement[nx][ny] = 1;
		}
	}
	//cout << "길이 없습니다\n";
	return false;
}

int main() {
	cin >> r >> c;
	int goose = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				v[goose++].push_back({ i,j });
				map[i][j] = '.';
			}
		}
	}
	/*for (int i = 0; i < 2; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i].front().first << ' ' << v[i].front().second <<'\n';
		}
	}*/
	int dayCnt = 0;
	while (true) {
		memset(check, 0, sizeof(check));
		memset(movement, 0, sizeof(movement));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] == 'X' && check[i][j] == 0) {
					melting(i, j);
				}
			}
		}
		dayCnt++;
		//print();
		//cout << "지난 날 :" << dayCnt <<'\n';
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i == v[0].front().first && j == v[0].front().second) {
					if (bfs(i, j) == 1) {
						cout << dayCnt;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}