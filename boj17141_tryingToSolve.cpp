#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, answer = 987654321;;
int map[50][50], c_map[50][50];	//0은 빈칸, 1은 벽, 2는 바이러스 놓을 수 있음
bool check[50][50], dfsCheck[10];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<pair<int, int>> v, virus;
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (check[nx][ny] == 1) continue;
			if (c_map[nx][ny] == 1) continue;	//벽이므로 x
			q.push({ nx,ny });
			check[nx][ny] = 1;
			c_map[nx][ny] = c_map[x][y] + 1;
			//값이 더 크다면 작은 것으로 변경
			cout << "현재 큐 (" << x << "," << y << ") -> 다음 큐 (" << nx << "," << ny << ")로 이동\n";
		}
	}
}
void copyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c_map[i][j] = map[i][j];
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c_map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int minVal() {
	int time = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c_map[i][j] > time&& c_map[i][j] != 0)
				time = c_map[i][j];
		}
	}
	cout << "최소값: " << time << '\n';
	return time;
}

void dfs(int idx, int cnt) {
	if (cnt == m) {	//바이러스 놓을수 있는 크기만큼
		memset(check, false, sizeof(check));
		copyMap();
		for (int i = 0; i < virus.size(); i++) {
			cout << "(" << virus[i].first << " " << virus[i].second << ") ";
			q.push({ virus[i].first, virus[i].second });
			check[virus[i].first][virus[i].second] = 1;
		}
		cout << '\n';
		bfs();
		print();
		int time = minVal();
		if (answer > time) answer = time;
		cout << '\n';
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		if (dfsCheck[i] == 0) {
			dfsCheck[i] = 1;
			virus.push_back(v[i]);
			dfs(i + 1, cnt + 1);
			virus.pop_back();
			dfsCheck[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });	//바이러스 가능한 칸 넣어주고 0으로 변환
				map[i][j] = 0;
			}
		}
	}

	//순열로 바이러스 가능한 곳 중 m개 만큼 자리 고르고 실행
	dfs(0, 0);
	cout << "최종 값: " << answer << '\n';
	return 0;
}