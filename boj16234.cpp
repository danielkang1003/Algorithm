#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, l, r;
int map[50][50];
bool check[50][50];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool open = true;
void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;	//연합 수 확인
	int sum = map[i][j];
	q.push({ i,j });
	v.push_back({ i,j });
	check[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (check[nx][ny] == 1) continue;
			int gap = abs(map[x][y] - map[nx][ny]);
			if (l <= gap && gap <= r) {
				q.push({ nx,ny });
				v.push_back({ nx,ny });
				sum += map[nx][ny];
				check[nx][ny] = 1;
				open = true;
				//cout << "(" << x << "," << y << ")와 (" << nx << ',' << ny << ")차이는 " << gap <<'\n';
			}
		}
	}
	int avg = sum / v.size();
	//cout << "연합수: " << v.size() << " 연합의 총 인구수: " << sum << " 평균: " << avg << '\n';
	for (int i = 0; i < v.size(); i++) {
		map[v[i].first][v[i].second] = avg;
	}
}

void checkStatus() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> l >> r;
	input();
	int year = 0;
	while (open) {
		open = false;
		year++;
		memset(check, 0, sizeof(check));
		checkStatus();
		//print();
	}
	cout << year - 1 << '\n';
	return 0;
}