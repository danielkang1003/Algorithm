#include<iostream>
#include<queue>
using namespace std;

int n, m;
int map[1000][1000];
int check[1000][1000][2];	//벽이 부셔졌는지 안부셔져있는지
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<pair<int, int>, pair<int, int>>> q;
int bfs() {
	//시작은 x와 y 좌표가 0,0부터 이고, 벽은 부셔져있지 않은 상태인 0 과 거리인 1 로 시작
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	//체크 변수의 마지막 0은 벽이 안부셔진 상태에 방문했다고 표시.
	//왜냐면 첫 시작은 무조건 0으로 이동가능하게 해놓았기 떄문
	check[0][0][0] = 1;
	while (!q.empty()) {
		//이동할 x,y, 벽 그리고 이동 변수를 가진다
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second.first;
		int move = q.front().second.second;
		q.pop();
		//여기서 만약 끝까지 이동했다면 move를 리턴한다
		if (x == n - 1 && y == m - 1) return move;
		//일반 bfs와 같임
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			//이부분이 일반 bfs랑 다름
			//만약 (nx,ny)가 벽으로 막혀있고, 벽을 부수지 않았다면
			if (map[nx][ny] == 1 && wall == 0) {
				q.push({ {nx,ny},{wall + 1, move + 1} });
				check[nx][ny][wall + 1] = 1;
			}
			//만약 벽이 아니고 방문한적 없는 곳이라면 (일반 bfs)
			else if (map[nx][ny] == 0 && check[nx][ny][wall] == 0) {
				q.push({ {nx, ny}, {wall, move + 1} });
				check[nx][ny][wall] = 1;
			}
		}
	}
	//만약에 모두 막혀있어서 가지 못하면 -1 리턴해야함
	return -1;
}

int main() {
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	int answer = bfs();
	cout << answer;
	return 0;
}