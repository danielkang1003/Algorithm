#include<iostream>
#include<queue>

using namespace std;

int k, w, h;
int map[200][200];
bool check[200][200][31];	//k 사용 여부 최대 30번

//원숭이 이동 가능한 경로
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
//말의 모양 모방해서 이동가능한 경로
int hdx[8] = { -1,-2,-2,-1,1,2,2,1 };
int hdy[8] = { -2,-1,1,2,2,1,-1,-2 };

void input() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0}, {0,0} });	//x, y, k번 사용 수, 이동거리
	check[0][0][0] = 1;	//k 사용 x
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int kth = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == h - 1 && y == w - 1) {
			cout << cnt << '\n';
			return;
		}
		if (kth < k) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = x + hdx[dir];
				int ny = y + hdy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (check[nx][ny][kth + 1] == 1) continue;
				if (map[nx][ny] == 1) continue;
				q.push({ {nx,ny}, {kth + 1, cnt + 1} });
				check[nx][ny][kth + 1] = 1;
			}
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (check[nx][ny][kth] == 1) continue;
			if (map[nx][ny] == 1) continue;
			q.push({ {nx,ny},{kth, cnt + 1} });
			check[nx][ny][kth] = 1;
		}
	}
	cout << "-1\n";
}


int main() {
	input();
	bfs();
	return 0;
}