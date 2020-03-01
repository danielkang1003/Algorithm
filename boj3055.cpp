#include<iostream>
#include<queue>
using namespace std;

int r, c;
int map[50][50], waterMap[50][50];
bool check[50][50];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

pair<int, int> start, destination;
queue<pair<int, int>> water;

void waterBFS() {
	while (!water.empty()) {
		int size = water.size();
		for (int i = 0; i < size; i++) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (map[nx][ny] == -1) continue;
				if (nx == destination.first && ny == destination.second) continue;
				if (waterMap[nx][ny] > waterMap[x][y] + 1) {
					//작은 것으로 만들어주기
					waterMap[nx][ny] = waterMap[x][y] + 1;
					water.push({ nx,ny });
				}
			}
		}
	}
}

void startMove() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {start.first, start.second}, 0 });
	check[start.first][start.second] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();
		if (x == destination.first && y == destination.second) {
			cout << time << '\n';
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (check[nx][ny] == 1) continue;
			if (map[nx][ny] == -1) continue;
			if (time + 1 < waterMap[nx][ny]) {
				q.push({ {nx,ny}, time + 1 });
				check[nx][ny] = 1;
				map[nx][ny] = map[x][y] + 1;
			}
		}
	}
	cout << "KAKTUS\n";
}

void print() {
	cout << "=======물=======\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << waterMap[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "================\n";
	cout << "=======맵=======\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "================\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			waterMap[i][j] = 999;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char input;
			cin >> input;
			if (input == 'S') {
				start.first = i;
				start.second = j;
				map[i][j] = 0;
			}
			else if (input == 'D') {
				destination.first = i;
				destination.second = j;
				map[i][j] = 0;
			}
			else if (input == 'X') {
				map[i][j] = -1;
			}
			else if (input == '*') {
				water.push({ i,j });
				waterMap[i][j] = 0;
			}
		}
	}
	waterBFS();
	startMove();
	//print();
	return 0;
}