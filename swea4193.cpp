#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;

int tc, n, sx, sy, ex, ey, answer;
int map[15][15];
bool check[15][15];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {sx,sy}, 0 });	//���� ��ǥ�� �ð��� ����
	check[sx][sy] = 1;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int time = q.front().second;
			q.pop();
			//cout << "���� �Ｚ�� ��ǥ: " << x << "," << y << " �ð�: " << time << '\n';
			if (x == ex && y == ey) {
				//cout << "�������� �ɸ� �ð�: " << time << '\n';
				return time;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (check[nx][ny] == 1) continue;
				if (map[nx][ny] == 1) continue;
				if (map[nx][ny] == 2) {
					if (time % 3 == 2) {
						q.push({ {nx, ny}, time + 1 });
						check[nx][ny] = 1;
					}
					else q.push({ {x,y}, time + 1 });
				}
				if (map[nx][ny] == 0) {
					q.push({ {nx,ny}, time + 1 });
					check[nx][ny] = 1;
				}
			}
		}
	}
	return -1;
}

void input() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		answer = INT_MAX;
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		cin >> sx >> sy;	//������
		cin >> ex >> ey;	//��ǥ��
		int answer = bfs();
		cout << "#" << t << " ";
		if (answer == -1) cout << "-1\n";
		else cout << answer << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	input();
	return 0;
}