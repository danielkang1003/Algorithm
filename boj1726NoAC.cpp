#include<iostream>
#include<queue>

using namespace std;

int m, n;
int sx, sy, sdir;	//���� ��ġ�� ����
int destinationX, destinationY, destinationDir;	//���� ��ġ�� ����
int map[101][101];
bool check[101][101];

//�� �� �� ��	0��° ��� x
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };

void input() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sx >> sy >> sdir;
	cin >> destinationX >> destinationY >> destinationDir;
}

void Move(int dir) {	//�ٶ󺸴� �������� 1,2,3ĭ �� �ϳ� �̵�

}

int turnDir(int dir) {	//�������� ���� ��ȯ
	if (dir == 1) return 3;	//�� -> ��
	else if (dir == 2) return 4;	//�� -> ��
	else if (dir == 3) return 2;	//�� -> ��
	else if (dir == 4) return 1;	//�� -> ��
}

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {sx,sy}, {sdir, 0} });	//��ġ x,y, ����, ��� ��
	check[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curDir = q.front().second.first;	//���� �ٶ󺸴� ����
		int orderCnt = q.front().second.second;
		q.pop();
		if (x == destinationX && y == destinationY) {
			bool flag = false;
			while (true) {
				if (curDir != destinationDir) {
					int nextDir = turnDir(curDir);
					curDir = nextDir;
					flag = true;
					if (curDir == destinationDir) break;
				}
			}
			if (flag == true) cout << orderCnt + 1;
			else cout << orderCnt;
			return;
		}
		//�ٶ󺸴� �������� �̵� �Ǵ� ���� ��ȯ�� ����
		for (int dir = 1; dir <= 4; dir++) {	//���� ������ ����
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 1 || ny < 1 || nx >= m + 1 || ny >= n + 1) continue; //���� ��
			if (check[nx][ny] == 1) continue;	//�湮�� ��
			if (map[nx][ny] == 1) continue;	//�˵� ��� �̵� �Ұ�
			if (dir == curDir) {	//���� �ٶ󺸴� �����̶� �̵��Ϸ��� ������ ���ٸ�
				Move(dir);
			}
			else {	//������ �޶� �̵��� ���� ������ ��ȯ���־���Ѵٸ�
				while (true) {
					//cout << "���� ��ǥ: " << x <<", "<< y <<"���� ������ ��ȯ�մϴ� " << curDir <<" ";
					int nextDir = turnDir(curDir);
					curDir = nextDir;
					//cout << "���� " << nextDir << "�� ��ȯ �Ϸ�!\n";
					if (curDir == dir) break;
				}
			}
			//cout << "���� ��ǥ (" << x << "," << y << ")" << "�ٶ󺸴� ����: " << curDir << " ���� ��ǥ (" << nx << "," << ny << ")\n";
			q.push({ {nx,ny},{curDir, orderCnt + 1} });
			check[nx][ny] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	input();
	bfs();
	return 0;
}