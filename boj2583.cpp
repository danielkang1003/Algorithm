#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int m, n, k, x_1, x_2, y_1, y_2;
int paper[100][100];
int check[100][100];
/*
	m 과 n 조심
	0 0 1 1 0
	0 1 1 1 1
	0 0 1 1 0
	0 0 1 1 0
	1 1 0 0 0
	1 1 0 0 0
	0 0 0 0 0
*/
int area;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<int> v;

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
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			
			//이부분을
			//if(paper[nx][ny]== 1 || check[nx][ny] == 1) continue;
			//로 하니까 무한 루프에 빠졌는데 밑의 것으로 바꾸니까 정답 나옴
			if (paper[nx][ny] == 0 && check[nx][ny] == 0) {
				q.push({ nx,ny });
				check[nx][ny] = 1;
			}
		}
	}
	v.push_back(area);
}

int main() {
	cin >> m >> n >> k;
	while (k--) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int i = x_1; i < x_2; i++) {
			for (int j = y_1; j < y_2; j++) {
				paper[i][j] = 1;
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << paper[i][j] << ' ';
		}
		cout << '\n';
	}*/
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] == 0 && check[i][j] == 0) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}

	return 0;
}