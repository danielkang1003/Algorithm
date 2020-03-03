#include<iostream>
#include<queue>

using namespace std;

int m, n, a, b, c, ea, eb, ec;
int map[101][101];
bool check[101][101][5];	//���⿡ ���� ����

//0��° �ε��� �����ϰ� 1���� ���ʴ�� ��������
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };

pair<pair<int, int>, int> robot, desti;

void input() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> a >> b >> c;
	//�������� ���� �Է¹ޱ�
	robot.first.first = a;
	robot.first.second = b;
	robot.second = c;

	//������ ���� �Է¹ޱ�
	cin >> ea >> eb >> ec;
	desti.first.first = ea;
	desti.first.second = eb;
	desti.second = ec;
}

//180���� ���� ������
int turnDir(int dir, int ndir) {
	switch (dir) {
	case 1:	//���� ������ ������ ��
		if (ndir == 2) return 2;	//�����̶�� �ι� ��ɼ����ؾ� �������� �̵�����
		break;
	case 2:	//���� ������ ������ ��
		if (ndir == 1) return 2;	//�������� ������ �ι� ��� �����ؾ���
		break;
	case 3:	//���� �϶�
		if (ndir == 4) return 2;	//������ ������ �̵��� 2���� ����� �ʿ�
		break;
	case 4:	//������ ��
		if (ndir == 3) return 2;	//�Ͽ��� �����ε� 2���� ������� ���� ��ȯ ����
		break;
	}
	return 1;	//�������� ��ĭ. �� 90 �Ǵ� ���� 90���� ���� ��ȯ����
}

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	//������ x,y, ���� �׸��� ��� �� ����
	q.push({ {robot.first.first, robot.first.second},{robot.second, 0} });
	//�������� ���� �湮ó��
	check[robot.first.first][robot.first.second][robot.second] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curDir = q.front().second.first;
		int order = q.front().second.second;
		q.pop();

		if (x == desti.first.first && y == desti.first.second && curDir == desti.second) {
			//������ ��ɰ� x,y �׸��� ������ ���ٸ� ����
			//cout << "���� ����: (" << x << "," << y << ") ����: " << curDir <<"�̵� Ƚ��: " << order << '\n';
			cout << order << '\n';
			return;
		}

		for (int i = 1; i <= 3; i++) {	//���� �������� ����
			int nx = x + dx[curDir] * i;
			int ny = y + dy[curDir] * i;
			if (nx < 1 || ny < 1 || nx > m || ny > n) break;//���� ���̶�� ���̻� ������ص���
			if (map[nx][ny] == 1) break;	//�˵� ��Ż�� ���̻� ���ư� �ʿ� x
			if (check[nx][ny][curDir] == 1) continue;	//�湮�ߴ� ��. �ٸ����� �湮������ �� �����Ƿ� continue��
			//if (nx == desti.first.first && ny == desti.first.second) break;	//�������̸� ��
			check[nx][ny][curDir] = 1;	//��� ���� �����ϸ� �湮ó��
			q.push({ {nx,ny},{curDir, order + 1} });
			//cout << "(" << x << ',' << y << ")���� (" << nx << "," << ny << ")�� �̵�. ����: " << curDir << "��� Ƚ��: " << order + 1 << '\n';
		}
		for (int dir = 1; dir <= 4; dir++) {	//���� Ž��
			if (dir == curDir) continue;	//���������̶�� �Ѿ
			if (check[x][y][dir] == 0) {
				int orderCnt = order + turnDir(curDir, dir);
				q.push({ {x,y},{dir, orderCnt} });	//��ǥ�� ������ �ʴ´�. ���� ����� ���Ƚ����ŭ�� �־��ֱ�
				check[x][y][dir] = 1;
				//cout << "(" << x << ',' << y << ")���� ������ȯ �ǽ�. ���� ����: " << curDir << " -> " <<dir  << " ��� Ƚ��: " << orderCnt << '\n';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	input();
	bfs();
	return 0;
}