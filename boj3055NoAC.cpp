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
		waterMap[x][y] = 1;	//ù �� ������ 1�ʺ��� ����ϱ�� ���
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
				if (nx == destination.first && ny == destination.second) continue;	//������� ���Ѿ
				if (map[nx][ny] == -1) continue;	//���� �� �̵��Ұ�
				q.push({ nx,ny });
				waterCheck[nx][ny] = 1;
				waterMap[nx][ny] = waterMap[x][y] + 1;
			}
		}
	}
}

void startMove() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {start.first, start.second}, 1 });	//�̵� 1�ʺ��� ī��Ʈ
	check[start.first][start.second] = 1;	//ù ������ �湮 üũ
	map[start.first][start.second] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;	//���� ���
			if (check[nx][ny] == 1) continue;	//�湮 �޴� �� x
			if (map[nx][ny] == -1) continue;	//�� x
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
	cout << "===========��=======\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << waterMap[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "====================\n";
	cout << "=========����ġ======\n";
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
			if (input == 'D') {	//��� ��
				destination.first = i;
				destination.second = j;
				map[i][j] = 0;
			}
			else if (input == 'X') {	//��
				map[i][j] = -1;
			}
			else if (input == 'S') {	//������
				start.first = i;
				start.second = j;
				map[i][j] = 0;
			}
			else if (input == '*') {	//��
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