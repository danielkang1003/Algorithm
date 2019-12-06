#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int m, n, k;
int t, x, y;
int land[50][50];
int check[50][50];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (land[nx][ny] == 0 || check[nx][ny] == 1) continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		memset(land, 0, sizeof(land));
		memset(check, 0, sizeof(check));
		cin >> m >> n >> k;
		while (k--) {
			//x¿Í y Á¶½É!!!
			cin >> y >> x;
			land[x][y] = 1;
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << land[i][j] << ' ';
			}
			cout << '\n';
		}*/

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (land[i][j] == 1 && check[i][j] == 0) {
					cnt++;
					bfs(i, j);
				}
			}
		}
		cout << cnt << '\n';
	}
}
