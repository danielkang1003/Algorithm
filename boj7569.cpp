#include<iostream>	
#include<queue>

using namespace std;

int m, n, h, answer;
int map[100][100][100];	// 높이, x,y
bool check[100][100][100];

//동,서,남,북,아래,위
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, pair<int, int>>> q;	//x,y, 높이, cnt
void print() {
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[k][i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

bool checkMatured() {
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[k][i][j] == 0) return false;
			}
		}
	}
	return true;
}

void bfs() {
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int height = q.front().second.first;
		cnt = q.front().second.second;
		q.pop();
		//cout << "현재 꺼낸 queue 정보 x: " << x << " y: " << y << " h: " << h << " cnt: " << cnt << '\n';
		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nheight = height + dh[dir];
			if (nx < 0 || ny < 0 || nheight < 0 || nx >= n || ny >= m || nheight >= h) continue;
			if (map[nheight][nx][ny] == -1) continue;	//벽에 막힘
			if (check[nheight][nx][ny] == 1) continue;	//이미 방문함
			//cout << "다음 방문할 queue 정보 nx: " << nx << " ny: " << ny << " nh: " << nheight<< '\n';
			q.push({ {nx,ny}, {nheight, cnt + 1} });
			check[nheight][nx][ny] = 1;
			map[nheight][nx][ny] = map[height][x][y] + 1;
		}
		//print();
	}
	answer = cnt;
	if (checkMatured() == false) cout << "-1\n";
	else cout << answer << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> m >> n >> h;
	bool matured = true;	//모든 토마토가 익었는지 확인
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[k][i][j];
				if (map[k][i][j] == 0) matured = false;	//안익었다는 것
				if (map[k][i][j] == 1 && check[k][i][j] == 0) {
					//방문한적없고 토마토가 있다면
					q.push({ {i,j}, {k, 0} });	//x,y, 높이, 0을 담음
					check[k][i][j] = 1;
				}
			}
		}
	}
	if (matured == true) {
		cout << "0\n";
		return 0;	//종료
	}
	bfs();
	return 0;
}