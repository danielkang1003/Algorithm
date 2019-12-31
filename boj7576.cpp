#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int m, n;
int box[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

/*���� ��̴� �����̴�. check�迭�� ����ؼ� Ǯ�ٺ��ϱ�
���� �丶�䰡 �� �� �̻󿡼� bfs�� ���ƾ��ϴ� �׽�Ʈ ���̽����� Ǯ������ �ʾҴ�

�ذ�å���� ���� ������ check�迭�� �����ְ�, �丶�䰡 1�� ���� ��� �� ť�� ����ְ� �����ߴ�.
�׷��� �� �� bfs�� ���ȴ�.
bfs�� ���鼭 �丶�䰡 �� �ڽ��� ���� �ʾҴٸ� (box[x][y] �� 0�� ��)
�丶�� ������ 1�� �������״�. (������ ���� �丶��� 1�� ���־ �������� -1�� ���־�� �ɸ� �ð��� ��� �����ϴ�)

bfs�� ������ �� ����� �Ǵ��� Ȯ���� �غ��� �� �ȴ�. �ּ����� ó���س���.
�־��� �������� ������ �丶�� �߿� ���� ���� �丶��(0) �� �ִٸ� -1 ó���ش޶�� ��
�׸��� ���� �丶�� �� (��¥) ���� ū ���� ��� ������Ʈ �����־���.
�������� �ִ� ��¥�� �丶�信�� -1 ���ָ� ����!

6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1

�̺κ��� �������µ� ����� �� �ȴ�!
*/
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (box[nx][ny] == 0) {
				box[nx][ny] = box[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)
				q.push({ i,j });
		}
	}
	bfs();

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << box[i][j] << ' ';
		}
		cout << '\n';
	}*/

	int days = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
			else days = max(days, box[i][j]);
		}
	}
	cout << days - 1;
	return 0;
}