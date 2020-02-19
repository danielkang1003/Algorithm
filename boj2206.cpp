#include<iostream>
#include<queue>

using namespace std;

int n, m;
int map[1000][1000], movement[1000][1000];
bool check[1000][1000][2];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void print() {
	cout << "=========Move===========\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << movement[i][j];
		}
		cout << '\n';
	}
	cout << "=======================\n";
	cout << "=========CHECK=========\n";
	cout << check[0][0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			cout << check[i][j][1];
		}
		cout << '\n';
	}
	cout << "=======================\n";
}

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0,},{0,1} });	//x,y, ��, �̵� �Ÿ��� ������
	check[0][0][0] = 1;	//�� �Ⱥμ� ���·� �湮 ǥ��
	movement[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second.first;	//���� �ν��ٸ� 1
		int dist = q.front().second.second;	//�̵� �Ÿ�
		//cout << "x: " << x << " y: " << y << " wall: " << wall << " dist: " << dist << '\n';
		q.pop();

		if (x == n - 1 && y == m - 1) {	//�� �����ϸ� �̵��Ÿ� ����ϰ� ����
			cout << dist << '\n';
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			//���� ����. 1) ���� �������, 2) ���� ������ �μ����� ����, ���� ĭ�� ���̶��
			//3) �湮���� �ʾҰ� ����ĭ�� ��ĭ�̶��
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;	//1)
			//if (check[nx][ny][0] == 1 || check[nx][ny][1] == 1) continue;
			if (wall == 0 && map[nx][ny] == 1) {	//2)
				//cout << "nx: " << nx << " ny: " << ny << " wall: " << wall << " dist: " << dist << '\n';
				q.push({ {nx,ny},{wall + 1, dist + 1} });
				check[nx][ny][wall + 1] = 1;
				movement[nx][ny] = movement[x][y] + 1;
			}
			if (check[nx][ny][wall] == 0 && map[nx][ny] == 0) {	//3)
				//cout << "nx: " << nx << " ny: " << ny << " wall: " << wall << " dist: " << dist << '\n';
				q.push({ {nx,ny},{wall, dist + 1} });
				check[nx][ny][wall] = 1;
				movement[nx][ny] = movement[x][y] + 1;
			}
			//print();
		}
	}
	cout << "-1\n";	//�������� ���ߴٸ� -1 ��� �� ����
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs();

	return 0;
}