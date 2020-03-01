#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int r, c;
int map[50][50], waterMap[50][50];
bool check[50][50], waterCheck[50][50];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

pair<int, int> start, destination;
vector<pair<int, int>> water;

void waterBFS() {
	queue<pair<int, int>> q;
	for (int i = 0; i < water.size(); i++) {
		int x = water[i].first, y = water[i].second;
		q.push({ x,y });
		waterCheck[x][y] = 1;
		waterMap[x][y] = 1;	//첫 물 시작을 1초부터 계산하기로 약속
	}
	while (!q.empty()) {
		for (int i = 0; i < q.size(); i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (waterCheck[nx][ny] == 1) continue;
				if (nx == destination.first && ny == destination.second) continue;	//비버굴은 못넘어감
				if (map[nx][ny] == -1) continue;	//벽도 물 이동불가
				q.push({ nx,ny });
				waterCheck[nx][ny] = 1;
				waterMap[nx][ny] = waterMap[x][y] + 1;
			}
		}
	}
}

void startMove() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {start.first, start.second}, 1 });	//이동 1초부터 카운트
	check[start.first][start.second] = 1;	//첫 시작점 방문 체크
	map[start.first][start.second] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;	//범위 벗어남
			if (check[nx][ny] == 1) continue;	//방문 햇던 곳 x
			if (map[nx][ny] == -1) continue;	//벽 x
			if (time + 1 < waterMap[nx][ny]) {
				q.push({ {nx,ny}, time + 1 });
				check[nx][ny] = 1;
				map[nx][ny] = map[x][y] + 1;
			}
			if (nx == destination.first && ny == destination.second) {
				cout << time << '\n';
				return;
			}

		}
	}
	cout << "KAKTUS\n";
}

void print() {
	cout << "===========물=======\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << waterMap[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
	cout << "=========고슴도치======\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "======================\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char input;
			cin >> input;
			if (input == 'D') {	//비버 굴
				destination.first = i;
				destination.second = j;
				map[i][j] = 0;
			}
			else if (input == 'X') {	//돌
				map[i][j] = -1;
			}
			else if (input == 'S') {	//시작점
				start.first = i;
				start.second = j;
				map[i][j] = 0;
			}
			else if (input == '*') {	//물
				water.push_back({ i,j });
				map[i][j] = 0;
			}
		}
	}
	waterBFS();
	startMove();
	//print();
	return 0;
}