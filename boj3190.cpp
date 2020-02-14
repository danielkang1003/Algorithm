#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int n, k, l;	//map ũ��, ��� ����, ���� ���� ��ȯ Ƚ��
int map[100][100];
deque<pair<int, int>> dq;
vector<pair<int, char>> info;

//�� �� �� ��
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int changeDir(int dir, char way) {
	if (way == 'L') {	//�������� 90�� ȸ��
		if (dir == 0) return 3;			//���ʿ��� ��������
		else if (dir == 1) return 2;	//������ ��������
		else if (dir == 2) return 0;	//���ʿ��� ��������
		else if (dir == 3) return 1;	//�����̸� ��������
	}
	else if (way == 'D') {
		if (dir == 0) return 2;			//���ʿ��� ��������
		else if (dir == 1) return 3;	//�����̸� ��������
		else if (dir == 2) return 1;	//�����̸� ��������
		else if (dir == 3) return 0;	//�����̸� ��������
	}
}

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x = x - 1, y = y - 1;
		map[x][y] = 1;	//����� 1�� ǥ��
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int sec;
		char dir;
		cin >> sec >> dir;
		info.push_back({ sec, dir });	//���� ���������� ���� ����
	}

	int x = 0, y = 0, dir = 0, time = 0, idx = 0;
	dq.push_back({ x,y });
	map[x][y] = 2;
	while (true) {
		time++;
		int nx = x + dx[dir];	//������ �������� ó���� �̵�
		int ny = y + dy[dir];
		if ((nx < 0 || ny < 0 || nx >= n || ny >= n) || map[nx][ny] == 2) break;
		else if (map[nx][ny] == 0) {
			//��ĭ�̶��
			map[nx][ny] = 2;
			map[dq.back().first][dq.back().second] = 0;	//���� �ڸ��� 0����
			dq.pop_back();	//ó���� �־�ξ��� ���� �ڸ� ���ֱ�
			dq.push_front({ nx,ny });	//�̵��� ���� �ڸ� �־��ֱ�
		}
		else if (map[nx][ny] == 1) {
			//����� �ִٸ�
			map[nx][ny] = 0;
			dq.push_front({ nx,ny });	//�Ӹ��� �÷��� ����ĭ�� ��ġ. ������ �״��
		}

		if (idx < info.size()) {
			if (time == info[idx].first) {
				//���� �ð��� ���� �̵��϶�� ������ �ð���ŭ�� �ð��� ������
				if (info[idx].second == 'L') dir = changeDir(dir, 'L');
				else if (info[idx].second == 'D') dir = changeDir(dir, 'D');
				idx++;
			}
		}
		x = nx;
		y = ny;
	}
	cout << time << '\n';


	return 0;
}