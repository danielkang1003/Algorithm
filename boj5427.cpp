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
	queue<pair<int, int>> fireMove;	//�� �־��ֱ�
	for (int i = 0; i < fire.size(); i++) {
		fireMove.push(fire[i]);
	}
	queue<pair<pair<int, int>, int>> q;	//��� ù ���� �־��ֱ�
	q.push({ {me.first, me.second}, 0 });	//��� ��ǥ x, y, �̵� �Ÿ�

	while (!q.empty()) {
		//�ֺ��� ���� ���� ���δ�
		int size = fireMove.size();
		//cout << "���� ���� ũ��: " << size << '\n';
		for (int i = 0; i < size; i++) {
			int x = fireMove.front().first;
			int y = fireMove.front().second;
			fireMove.pop();
			//cout << "�� ���� x: " << x << " y: " << y << '\n';
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (map[nx][ny] != '.') continue;
				//cout << "�̵� ������ �� nx: " << nx << " ny: " << ny << '\n';
				map[nx][ny] = map[x][y];
				fireMove.push({ nx,ny });
			}
		}
		//��� ������. ��� �ڸ��� �̵��ϸ鼭 ť�� �־��� ���� �ݺ��Ұ���
		size = q.size();
		//cout << "����� �̵�: " << size << '\n';
		for (int i = 0; i < size; i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cnt = q.front().second;
			q.pop();
			//cout << "��� ���� ��ǥ x: " << x << " y: " << y << " �̵� �Ÿ�: " << cnt<< '\n';
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
				//cout << "��� ���� ��� nx: " << nx << " ny: " << ny << '\n';
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