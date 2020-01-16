//��� 1: ����
#include<iostream>

using namespace std;

int n, m, r, c, d;	//����, ����, �κ� ��ǥx,y ,�ٶ󺸴� ����
int place[50][50];	//����

//���ʴ�� ��(0) ��(1) ��(2) ��(3)
int dx[4] = { -1,0,1,0 };	//r
int dy[4] = { 0,1,0,-1 };	//c


pair<pair<int, int>, int> robot;

//û�ұⰡ �������� �ٶ� ���� ����
int turnDir(int d) {
	if (d == 0) return 3;	//��(0)�̶�� ���ʹ����� ��(3)��
	else if (d == 1) return 0;	//��(1)�̶�� ���ʹ����� ��(0)����
	else if (d == 2) return 1;	//��(2)�̶�� ���ʹ����� ��(1)����
	else if (d == 3) return 2;	//��(3)��� ���ʹ����� ��(2)����
}

void solution() {
	int x = robot.first.first;
	int y = robot.first.second;
	int d = robot.second;
	int cleanCnt = 0;	//û���� ������ ī��Ʈ ����
	place[x][y] = 2;	//ù �ڸ��� û���� ������ ����
	cleanCnt++;

	int nx, ny, nd;	//���� ��ǥ �� �ٶ󺸴� ����

	while (true) {	// û�ұⰡ �۵� ���߸� ����
		int back = d;	//������ ���� temp ������ ���� �������� ���
		bool canClean = false;
		int cannotClean = 0;	//4�� �Ǹ� ��� ĭ�� ���ų� �����ִܾ��
		for (int i = 0; i < 4; i++) {
			nd = turnDir(d);
			//������ ������ ���ʹ������� ������
			nx = x + dx[nd];
			ny = y + dy[nd];

			if (place[nx][ny] == 0) {
				canClean = true;	//û���� �� �ִٰ� true ǥ��
				break;
			}
			//���� ��(1)�̰ų� û����(2) �κ� �Ǵ� ������ �Ѿ�� �Ѿ
			else if (place[nx][ny] == 1 || place[nx][ny] == 2 ||
				(nx < 0 || ny < 0 || nx >= n || ny >= m)) {
				d = nd;	//���� �ٲپ���
				cannotClean++;	//�� ������ �̵����� �ʰ� ���̵��ϴϱ� 1 ����
			}
		}
		if (canClean == true) {
			//û���� �� ������
			place[nx][ny] = 2;	//û���ߴٰ� ǥ��
			cleanCnt++;
			d = nd;
		}
		if (cannotClean == 4) {
			//�̵��� ������ �̹� �湮�߰ų� ���̶� �� �������� ��� �̵��� �Ұ��ϸ�
			//�ڷ� �����Ѵ�. ������ ������ä��
			nx = x - dx[back];	//���� x ��ǥ���� �ڷ� ��ĭ
			ny = y - dy[back];	//���� y ��ǥ���� �ڷ� ��ĭ
			d = back;			//�ٶ󺸴� ������ ���� �״��
			if ((nx < 0 || ny < 0 || nx >= n || ny >= m) || place[nx][ny] == 1) {
				//������ ����ų� ���̶�� ��
				break;
			}
		}
		x = nx;
		y = ny;
	}
	cout << cleanCnt << '\n';
}

int main() {
	cin >> n >> m;
	cin >> robot.first.first >> robot.first.second >> robot.second;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> place[i][j];
		}
	}

	solution();

	return 0;
}


