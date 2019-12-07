#include<iostream>
#include<queue>
#include<string>
using namespace std;
int T, len, n_x, n_y, m_x, m_y;
int chess[300][300];
int check[300][300];
int dx[8] = { 1,2, 2, 1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1, 1, 2 };

void bfs(int n_x, int n_y) {
	queue<pair<pair<int, int>, int>> q;	//night�� x,y ��ǥ �� cnt�� �� ����
	q.push({{ n_x, n_y }, 0});	//cnt �� 0���� ����
	check[n_x][n_y] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;	//q�� ���� x��ǥ
		int y = q.front().first.second; //q�� ���� y��ǥ
		int cnt = q.front().second;		//q�� ���� cnt
		q.pop();

		//�̰����� bfs���鼭 �����ϸ� ���
		if (x == m_x && y == m_y) {
			cout << cnt << '\n';
			return;
		}
		
		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= len || ny >=len) continue;
			if (check[nx][ny] == 0) {
				q.push({ {nx,ny}, cnt + 1 });//cnt++�� �ϸ� �ȵ�
				check[nx][ny] = 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		//�׽�Ʈ���̽��� �������Ƿ� check�迭 �ʱ�ȭ���ֱ�
		memset(check, 0, sizeof(check));
		cin >> len;
		cin >> n_x >> n_y >> m_x >> m_y;
		bfs(n_x, n_y);
		
		//chess[n_x][n_y] = 1; // ����Ʈ �ڸ�
		//chess[m_x][m_y] = 2; // ����Ʈ�� �̵��ؾ��� ��
		//for (int i = 0; i < len; i++) {
		//	for (int j = 0; j < len; j++) {
		//		cout << chess[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}

	}

	return 0;
}