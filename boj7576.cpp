#include<iostream>
#include<queue>

using namespace std;

int m, n, answer;
int map[1000][1000];
bool check[1000][1000];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<pair<int, int>, int>> q;


void print() {
	cout << "##############\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "##############\n";
}
//토마토 익는 거 끝나고 한번 돌아서 덜 익은게 잇는지 확인
bool checkMatured() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		//cout << "현재 BFS 수행 좌표 x: " << x << " y: " << y << " cnt: " << cnt <<'\n';

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;	//범위 벗어남
			if (map[nx][ny] == -1) continue;	//벽
			if (check[nx][ny] == 1) continue;	//방문했다면
			//cout << "조건에 부합하는 다음 좌표 nx: " << nx << " ny: " << ny << '\n';
			map[nx][ny] = map[x][y] + 1;
			check[nx][ny] = 1;
			q.push({ {nx,ny}, cnt + 1 });
			//print();
		}
		answer = cnt;
	}
	if (checkMatured() == 0) cout << "-1\n";
	else cout << answer << '\n';
}



int main() {
	cin >> m >> n;
	bool matured = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) matured = false;
		}
	}
	//이미 모든 토마토가 익어있는 상태
	if (matured == true) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				q.push({ {i,j}, 0 });
				check[i][j] = 1;
			}
		}
	}
	bfs();

	return 0;
}