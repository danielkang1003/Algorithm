#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int n;
int map[100][100], c_map[100][100];
bool check[100][100];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c_map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void copyMap(int height) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c_map[i][j] = map[i][j] - height;
			if (c_map[i][j] < 0) c_map[i][j] = 0;
		}
	}
}

void bfs(int i, int j, int labeling) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = 1;
	c_map[i][j] = labeling;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (c_map[nx][ny] == 0) continue;
			if (check[nx][ny] == 1) continue;
			c_map[nx][ny] = labeling;
			check[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	int high = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (high < map[i][j]) high = map[i][j];
		}
	}

	int answer = -1;
	//cout <<"강우 최대: "<< high << '\n';
	for (int i = 0; i < high; i++) {
		copyMap(i);
		memset(check, 0, sizeof(check));
		int labeling = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (c_map[a][b] != 0 && check[a][b] == 0) {
					bfs(a, b, ++labeling);
				}
			}
		}
		//print();
		if (answer < labeling) answer = labeling;
		//cout << answer << '\n';
	}
	//cout << "최종 안전 영역: " << answer;
	cout << answer << '\n';
	return 0;
}