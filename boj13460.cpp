#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct INFO {
	int rx, ry, bx, by, cnt;
};
INFO ball;
int n, m;
char map[10][10];
bool check[10][10][10][10];	//���� �Ķ� �� ��� �湮�� �� ����
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') ball.rx = i, ball.ry = j;	//���� ��ġ ����ֱ�
			else if (map[i][j] == 'B') ball.bx = i, ball.by = j;	//�Ķ� ��ġ ���
		}
	}
	ball.cnt = 0;	//�̵� �� 0���� �ʱ�ȭ
}

int bfs() {
	queue<INFO> q;
	q.push(ball);
	check[ball.rx][ball.ry][ball.bx][ball.by] = 1;
	int answer = -1;
	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();
		if (cur.cnt > 10) break;
		if (map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O') {
			answer = cur.cnt;
			break;
		}
		//cout << "���� ��: (" << cur.rx << ',' << cur.ry << ") �Ķ� ��: (" << cur.bx << "," << cur.by << "), ��� Ƚ��: " << cur.cnt<<"����\n";
		for (int dir = 0; dir < 4; dir++) {
			int next_rx = cur.rx, next_ry = cur.ry, next_bx = cur.bx, next_by = cur.by;
			//������ �����̱�
			while (true) {
				if (map[next_rx][next_ry] != 'O' && map[next_rx][next_ry] != '#') {
					//���� �ƴϰ� �������� �ʾ����� ����
					next_rx += dx[dir], next_ry += dy[dir];
				}
				else {	//���̸�
					if (map[next_rx][next_ry] == '#') {
						next_rx -= dx[dir], next_ry -= dy[dir];
					}
					break;
				}
			}
			//���� �Ķ��� �����̱�
			while (true) {
				if (map[next_bx][next_by] != 'O' && map[next_bx][next_by] != '#') {
					//���� �ƴϰ� �������� �ʾ����� ����
					next_bx += dx[dir], next_by += dy[dir];
				}
				else {	//���̸�
					if (map[next_bx][next_by] == '#') {
						next_bx -= dx[dir], next_by -= dy[dir];
					}
					break;
				}
			}
			//�ٿ����̰� ���� ���������� ó��
			if (next_rx == next_bx && next_ry == next_by) {
				if (map[next_rx][next_ry] == 'O') continue;	//�������� ���� ���� ���ؼ��� ó��
				int redDist = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
				int blueDist = abs(next_bx - cur.bx) + abs(next_by - cur.by);
				if (redDist > blueDist) {
					next_rx -= dx[dir], next_ry -= dy[dir];
				}
				else {
					next_bx -= dx[dir], next_by -= dy[dir];
				}
			}
			//�湮�����ʾ����� ť�� �־ ���� �̵� ����
			if (check[next_rx][next_ry][next_bx][next_by] == 0) {
				check[next_rx][next_ry][next_bx][next_by] = 1;
				INFO next;
				next.rx = next_rx, next.ry = next_ry, next.bx = next_bx, next.by = next_by;
				next.cnt = cur.cnt + 1;
				q.push(next);
				//cout << "������: (" << next.rx << "," << next.ry << ") �Ķ� ��: (" << next.bx << "," << next.by << ")�� �̵��մϴ�. ��� Ƚ��: " << next.cnt <<'\n';
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	input();
	int answer = bfs();
	cout << answer << '\n';
	return 0;
}