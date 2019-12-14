#include<iostream>
#include<queue>
using namespace std;

int n, m;
int map[1000][1000];
int check[1000][1000][2];	//���� �μ������� �Ⱥμ����ִ���
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<pair<int, int>, pair<int, int>>> q;
int bfs() {
	//������ x�� y ��ǥ�� 0,0���� �̰�, ���� �μ������� ���� ������ 0 �� �Ÿ��� 1 �� ����
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	//üũ ������ ������ 0�� ���� �Ⱥμ��� ���¿� �湮�ߴٰ� ǥ��.
	//�ֳĸ� ù ������ ������ 0���� �̵������ϰ� �س��ұ� ����
	check[0][0][0] = 1;
	while (!q.empty()) {
		//�̵��� x,y, �� �׸��� �̵� ������ ������
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second.first;
		int move = q.front().second.second;
		q.pop();
		//���⼭ ���� ������ �̵��ߴٸ� move�� �����Ѵ�
		if (x == n - 1 && y == m - 1) return move;
		//�Ϲ� bfs�� ����
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			//�̺κ��� �Ϲ� bfs�� �ٸ�
			//���� (nx,ny)�� ������ �����ְ�, ���� �μ��� �ʾҴٸ�
			if (map[nx][ny] == 1 && wall == 0) {
				q.push({ {nx,ny},{wall + 1, move + 1} });
				check[nx][ny][wall + 1] = 1;
			}
			//���� ���� �ƴϰ� �湮���� ���� ���̶�� (�Ϲ� bfs)
			else if (map[nx][ny] == 0 && check[nx][ny][wall] == 0) {
				q.push({ {nx, ny}, {wall, move + 1} });
				check[nx][ny][wall] = 1;
			}
		}
	}
	//���࿡ ��� �����־ ���� ���ϸ� -1 �����ؾ���
	return -1;
}

int main() {
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	int answer = bfs();
	cout << answer;
	return 0;
}