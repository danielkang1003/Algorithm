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
	queue<pair<pair<int, int>, int>> q;	//night의 x,y 좌표 와 cnt를 셀 예정
	q.push({{ n_x, n_y }, 0});	//cnt 는 0부터 시작
	check[n_x][n_y] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;	//q에 넣은 x좌표
		int y = q.front().first.second; //q에 넣은 y좌표
		int cnt = q.front().second;		//q에 넣은 cnt
		q.pop();

		//이곳에서 bfs돌면서 도착하면 출력
		if (x == m_x && y == m_y) {
			cout << cnt << '\n';
			return;
		}
		
		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= len || ny >=len) continue;
			if (check[nx][ny] == 0) {
				q.push({ {nx,ny}, cnt + 1 });//cnt++로 하면 안됨
				check[nx][ny] = 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		//테스트케이스가 여러개므로 check배열 초기화해주기
		memset(check, 0, sizeof(check));
		cin >> len;
		cin >> n_x >> n_y >> m_x >> m_y;
		bfs(n_x, n_y);
		
		//chess[n_x][n_y] = 1; // 나이트 자리
		//chess[m_x][m_y] = 2; // 나이트가 이동해야할 곳
		//for (int i = 0; i < len; i++) {
		//	for (int j = 0; j < len; j++) {
		//		cout << chess[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}

	}

	return 0;
}