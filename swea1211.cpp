#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int tnum, minCnt, answer;
int map[100][100];

////��������, ������, ����
//int dx[3] = { 1,0,0 };
//int dy[3] = { 0,1,-1 };

vector<pair<int, int>> start;

void init() {
	minCnt = 987654321;	//�ּ� �Ÿ�
	answer = -1;	//��ٸ� ��ȣ
	start.clear();
}

void input() {
	cin >> tnum;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> map[i][j];
			if (i == 0 && map[i][j] == 1) start.push_back({ i,j });
		}
	}
}

int ladderGame(int sx, int sy) {	//������ ����
	int dir = 0;
	int x = sx, y = sy;
	int cnt = 0;
	while (true) {
		if (dir == 0) {//�Ʒ��� ��������
			x++;
			cnt++;
			while (true) {
				if (x == 99) return cnt;//����
				if (y + 1 < 100) {	//�迭 ������
					if (map[x][y + 1] == 1) { //�����ʿ� ���� ����
						dir = 1;
						break;
					}
				}
				if (y - 1 >= 0) {
					if (map[x][y - 1] == 1) {	//���ʿ� ���� ����
						dir = 2;
						break;
					}
				}
				//�¿쿡 ���� ���ٸ� ������ ��������
				x++;
				cnt++;
			}
		}
		else if (dir == 1) {
			y++;
			cnt++;
			while (true) {
				if (x + 1 < 100) {
					if (map[x + 1][y] == 1) {//�Ʒ��� �������� ���� ����
						dir = 0;
						break;
					}
				}
				//��� ������ �����̸� ��� ����
				y++;
				cnt++;
			}
		}
		else if (dir == 2) {
			y--;
			cnt++;
			while (true) {
				if (x + 1 < 100) {
					if (map[x + 1][y] == 1) {
						dir = 0;
						break;
					}
				}
				//�� ���� �ƴ� �� ���� �������� ��� �̵�
				y--;
				cnt++;
			}
		}
	}
}

void simulation() {
	for (int i = 0; i < start.size(); i++) {
		int x = start[i].first, y = start[i].second;
		//cout << x << ' ' << y << '\n';
		int temp = ladderGame(x, y);	//ī��Ʈ ��������
		if (minCnt > temp) {
			minCnt = temp;
			answer = y;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for (int t = 1; t <= 10; t++) {
		init();
		input();
		simulation();
		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}

/*
1
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 1
*/