#include<iostream>
#include<queue>

using namespace std;

int n, answer;
int house[16][16];	//0: ��ĭ, 1: ��
//��, ��, �밢��
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };
queue<pair<pair<int, int>, int>> q;

//bfs�� Ž�� (�޸𸮿� ������ ����...)
void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curDir = q.front().second;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			//������ ���������� Ž����. ������ ����� 1 �߰�
			answer++;
			continue;
		}

		if (curDir == 0) {	//�������� ���ϴ� ����
			//���ʹ����� ���Ҷ� ������ ������ ���ʰ� �밢���̴�.
			//������ �Ұ�����.

			//1. (x,y) -> (nx,ny) : �������� ���ϴ� ��
			int nx = x + dx[curDir];
			int ny = y + dy[curDir];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0) {
					q.push({ {nx,ny}, curDir });
				}
			}

			//2. �밢������ ���� �� ���� 2��° idx�� �밢���� ����Ŵ
			nx = x + dx[2];
			ny = y + dy[2];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0 && house[x + 1][y] == 0 && house[x][y + 1] == 0) {
					//�밢������ �̵��� ���� ��, ��, �׸��� �밢���� �����Ѵ�. (����)
					q.push({ {nx,ny}, 2 });	//������ �밢������ �����ϴ� ��ǥ�� �־���
				}
			}
		}
		else if (curDir == 1) {	//�������� ���� ��
			//���ʰ� ���� ����.
			//�����������ϴµ� �������δ� �̵��� ���� ����
			//���� nx, ny �� ���� ���� �Ǵ� �밢���� �����ϴ�
			//1. ���� -> ��������
			int nx = x + dx[curDir];
			int ny = y + dy[curDir];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0) {
					q.push({ {nx,ny}, curDir });
				}
			}
			//2. ���� -> �밢������
			nx = x + dx[2];
			ny = y + dy[2];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0 && house[x + 1][y] == 0 && house[x][y + 1] == 0) {
					q.push({ {nx,ny}, 2 });
				}
			}
		}
		else if (curDir == 2) { //�밢������ ���� ��
			//�밢���� ������ �������̴�.
			//1. �밢������ �밢������
			int nx = x + dx[curDir];
			int ny = y + dy[curDir];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0 && house[x + 1][y] == 0 && house[x][y + 1] == 0) {
					q.push({ {nx,ny}, curDir });
				}
			}
			//2. �밢������ ��������
			nx = x + dx[0];
			ny = y + dy[0];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0) {
					q.push({ {nx,ny}, 0 });
				}
			}
			//3. �밢������ ��������
			nx = x + dx[1];
			ny = y + dy[1];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0) {
					q.push({ {nx,ny}, 1 });
				}
			}
		}
	}
}

//���� �ִ� �������� ��ͷ� Ž�� �޸𸮴� ���� ����. �ð��� ���� �پ�����
void dfs(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) {
		answer++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if ((i == 0 && dir == 1) || (i == 1 && dir == 0)) {
			//i = 0,1,2�� �� �� ���� ��Ÿ��
			//dir = 1�̸� ���� dir = 0�̸� ����
			//�� ���ư� ����(i)�� ����(0)�ε� ���� �������� �����ִ� ������
			//����(1)�̸� �̵��� �Ұ����ϴ�.
			//���������� ����(1)�ε� ���� �������� ������ ������
			//����(0)�̶�� �̵� �Ұ��̹Ƿ� �Ѿ�ش�
			continue;
		}
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= n || ny >= n || house[nx][ny] == 1) continue;
		
		if (i == 2 && (house[x][y + 1] == 1 || house[x + 1][y] == 1 || house[nx][ny] == 1)) {
			//�밢�� �������� �������� �̵���ų �� 3������ ��� �� �� �ִ���
			//�� ��ĭ(house = 0)���� Ȯ���ؾ���.
			//���̶�� �̵� �Ұ�
			continue;
		}
		dfs(nx, ny, i);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
		}
	}
	q.push({ {0,1}, 0 });	//������ (0,1), ���� ��
	//bfs();
	dfs(0, 1, 0);
	cout << answer << '\n';
	return 0;
}
