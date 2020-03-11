#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct INFO {
	int rx, ry, bx, by, cnt;
};
INFO ball;
int n, m;
char map[10][10];
bool check[10][10][10][10];	//빨강 파랑 공 모두 방문한 곳 저장
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') ball.rx = i, ball.ry = j;	//빨강 위치 담아주기
			else if (map[i][j] == 'B') ball.bx = i, ball.by = j;	//파랑 위치 담기
		}
	}
	ball.cnt = 0;	//이동 수 0으로 초기화
}

int bfs() {
	queue<INFO> q;
	q.push(ball);
	check[ball.rx][ball.ry][ball.bx][ball.by] = 1;
	int answer = -1;
	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();
		if (cur.cnt > 10) break;
		if (map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O') {
			answer = cur.cnt;
			break;
		}
		//cout << "빨간 공: (" << cur.rx << ',' << cur.ry << ") 파란 공: (" << cur.bx << "," << cur.by << "), 명령 횟수: " << cur.cnt<<"에서\n";
		for (int dir = 0; dir < 4; dir++) {
			int next_rx = cur.rx, next_ry = cur.ry, next_bx = cur.bx, next_by = cur.by;
			//빨간공 움직이기
			while (true) {
				if (map[next_rx][next_ry] != 'O' && map[next_rx][next_ry] != '#') {
					//벽이 아니고 골인하지 않았으면 실행
					next_rx += dx[dir], next_ry += dy[dir];
				}
				else {	//벽이면
					if (map[next_rx][next_ry] == '#') {
						next_rx -= dx[dir], next_ry -= dy[dir];
					}
					break;
				}
			}
			//이후 파란공 움직이기
			while (true) {
				if (map[next_bx][next_by] != 'O' && map[next_bx][next_by] != '#') {
					//벽이 아니고 골인하지 않았으면 실행
					next_bx += dx[dir], next_by += dy[dir];
				}
				else {	//벽이면
					if (map[next_bx][next_by] == '#') {
						next_bx -= dx[dir], next_by -= dy[dir];
					}
					break;
				}
			}
			//다움직이고 공이 겹쳐있을때 처리
			if (next_rx == next_bx && next_ry == next_by) {
				if (map[next_rx][next_ry] == 'O') continue;	//골인하지 않은 공에 대해서만 처리
				int redDist = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
				int blueDist = abs(next_bx - cur.bx) + abs(next_by - cur.by);
				if (redDist > blueDist) {
					next_rx -= dx[dir], next_ry -= dy[dir];
				}
				else {
					next_bx -= dx[dir], next_by -= dy[dir];
				}
			}
			//방문하지않았으면 큐로 넣어서 다음 이동 실행
			if (check[next_rx][next_ry][next_bx][next_by] == 0) {
				check[next_rx][next_ry][next_bx][next_by] = 1;
				INFO next;
				next.rx = next_rx, next.ry = next_ry, next.bx = next_bx, next.by = next_by;
				next.cnt = cur.cnt + 1;
				q.push(next);
				//cout << "빨간공: (" << next.rx << "," << next.ry << ") 파란 공: (" << next.bx << "," << next.by << ")로 이동합니다. 명령 횟수: " << next.cnt <<'\n';
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	input();
	int answer = bfs();
	cout << answer << '\n';
	return 0;
}