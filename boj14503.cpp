//��� 1: BFS
#include<iostream>
#include<queue>

using namespace std;

int n, m, r, c, d;
int place[50][50], clean[50][50];
//idx 0 : ��, 1 : ��, 2 : ��, 3 : ��
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int answer;

//�������� ȸ��
int turnDirection(int n) {
	if (n == 0) return 3;	//���̸� ��������
	else if (n == 1) return 0;	//���̸� ������
	else if (n == 2) return 1;	//���̸� ������
	else if (n == 3) return 2;	//�����̸� ������
}

int backDirection(int n) {
	if (n == 0) return 2;	//���̸� ��������
	else if (n == 1) return 3;	//���̸� ��������
	else if (n == 2) return 0;	//�����̸� ��������
	else if (n == 3) return 1;	//�����̸� ��������
}

queue<pair<pair<int, int>, int>> q;

void bfs() {
	answer++;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		int nextDir = dir;
		bool flag = false;	//�� ������ û�Ұ� �Ǿ����� �Ǵ� true�� û�� �Ϸ�
		for (int i = 0; i < 4; i++) {
			nextDir = turnDirection(nextDir);
			int nx = x + dx[nextDir];
			int ny = y + dy[nextDir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (clean[nx][ny] == 1) continue;
			if (place[nx][ny] == 0) {
				q.push({ {nx,ny}, nextDir });
				clean[nx][ny] = 1;
				answer++;
				flag = true;	//û�Ҹ� �� ���� �ѱ����� ������ true
				break;	//���� ���� Ȯ���Ϸ� ��
			}
		}
		//�׹��� ��� û�Ұ� �Ǿ��ִٸ�
		if (flag == false) {
			int bDir = backDirection(dir);
			int nx = x + dx[bDir];
			int ny = y + dy[bDir];
			if (place[nx][ny] == 0) {
				q.push({ {nx,ny}, dir });
				clean[nx][ny] = 1;
			}
			else return;	//����
		}
	}
}

int main() {
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> place[i][j];
	q.push({ {r,c,}, d });
	clean[r][c] = 1;

	//cout << "BFS ���� ��: " << '\n';
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << clean[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	answer = 0;
	bfs();

	//cout << "BFS ���� ��: " << '\n';
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << clean[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << "û���� ������: "<< answer << '\n';
	cout << answer << '\n';
	return 0;
}




////��� 2: ����


//#include<iostream>
//
//using namespace std;
//
//int n, m, r, c, d;	//����, ����, �κ� ��ǥx,y ,�ٶ󺸴� ����
//int place[50][50];	//����
//
////���ʴ�� ��(0) ��(1) ��(2) ��(3)
//int dx[4] = { -1,0,1,0 };	//r
//int dy[4] = { 0,1,0,-1 };	//c
//
//
//pair<pair<int, int>, int> robot;
//
////û�ұⰡ �������� �ٶ� ���� ����
//int turnDir(int d) {
//	if (d == 0) return 3;	//��(0)�̶�� ���ʹ����� ��(3)��
//	else if (d == 1) return 0;	//��(1)�̶�� ���ʹ����� ��(0)����
//	else if (d == 2) return 1;	//��(2)�̶�� ���ʹ����� ��(1)����
//	else if (d == 3) return 2;	//��(3)��� ���ʹ����� ��(2)����
//}
//
//void solution() {
//	int x = robot.first.first;
//	int y = robot.first.second;
//	int d = robot.second;
//	int cleanCnt = 0;	//û���� ������ ī��Ʈ ����
//	place[x][y] = 2;	//ù �ڸ��� û���� ������ ����
//	cleanCnt++;
//
//	int nx, ny, nd;	//���� ��ǥ �� �ٶ󺸴� ����
//
//	while (true) {	// û�ұⰡ �۵� ���߸� ����
//		int back = d;	//������ ���� temp ������ ���� �������� ���
//		bool canClean = false;
//		int cannotClean = 0;	//4�� �Ǹ� ��� ĭ�� ���ų� �����ִܾ��
//		for (int i = 0; i < 4; i++) {
//			nd = turnDir(d);
//			//������ ������ ���ʹ������� ������
//			nx = x + dx[nd];
//			ny = y + dy[nd];
//
//			if (place[nx][ny] == 0) {
//				canClean = true;	//û���� �� �ִٰ� true ǥ��
//				break;
//			}
//			//���� ��(1)�̰ų� û����(2) �κ� �Ǵ� ������ �Ѿ�� �Ѿ
//			else if (place[nx][ny] == 1 || place[nx][ny] == 2 ||
//				(nx < 0 || ny < 0 || nx >= n || ny >= m)) {
//				d = nd;	//���� �ٲپ���
//				cannotClean++;	//�� ������ �̵����� �ʰ� ���̵��ϴϱ� 1 ����
//			}
//		}
//		if (canClean == true) {
//			//û���� �� ������
//			place[nx][ny] = 2;	//û���ߴٰ� ǥ��
//			cleanCnt++;
//			d = nd;
//		}
//		if (cannotClean == 4) {
//			//�̵��� ������ �̹� �湮�߰ų� ���̶� �� �������� ��� �̵��� �Ұ��ϸ�
//			//�ڷ� �����Ѵ�. ������ ������ä��
//			nx = x - dx[back];	//���� x ��ǥ���� �ڷ� ��ĭ
//			ny = y - dy[back];	//���� y ��ǥ���� �ڷ� ��ĭ
//			d = back;			//�ٶ󺸴� ������ ���� �״��
//			if ((nx < 0 || ny < 0 || nx >= n || ny >= m) || place[nx][ny] == 1) {
//				//������ ����ų� ���̶�� ��
//				break;
//			}
//		}
//		x = nx;
//		y = ny;
//	}
//	cout << cleanCnt << '\n';
//}
//
//int main() {
//	cin >> n >> m;
//	cin >> robot.first.first >> robot.first.second >> robot.second;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> place[i][j];
//		}
//	}
//
//	solution();
//
//	return 0;
//}


