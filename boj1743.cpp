#include<iostream>

using namespace std;
/*
dfs�� bfs Ǯ�̰� ��� ����.
������ bfs�� Ǯ���µ� �� ��Ǯ����.
�׷��� dfs�� Ǯ���ٰ� bfs�� Ǯ�鼭 dfs�� ���鼭 ���̰� ���� ū�ɷ� �������ָ鼭 Ǯ����.
bfs�� ��ͷ� Ǯ��ȴ�. �迭�� �ѱ��� �ʰ� �湮���� �ʾҴ� ����� ���Ĺ��� �ִٸ�
���̸� 1�� �����������.
�׸��� ���� ���� ������ ������Ʈ �������.
dfsǮ�鼭 bfs�� �̷��� Ǯ��ǰڴ� �ؼ� Ǯ����.
*/

int n, m, k, r, c;
int trash[101][101];
bool check[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int area, maxArea;
void dfs(int x, int y) {
	check[x][y] = 1;
	area++;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
		if (trash[nx][ny] == 1 && check[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		trash[r][c] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (trash[i][j] == 1 && check[i][j] == 0) {
				area = 0;
				dfs(i, j);
				maxArea = maxArea > area ? maxArea : area;
			}
		}
	}
	cout << maxArea;
	return 0;
}

/*
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int n, m, k, r, c;
int trash[101][101];
int check[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int area;

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = 1;
	area = 0;
	while (!q.empty()) {
		area++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (check[nx][ny] == 0 && trash[nx][ny] == 1) {
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		trash[r][c] = 1;
	}
	int maxArea = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (trash[i][j] == 1 && check[i][j] == 0) {
				bfs(i, j);
				maxArea = max(maxArea, area);
			}
		}
	}
	cout << maxArea;
	return 0;
}
*/