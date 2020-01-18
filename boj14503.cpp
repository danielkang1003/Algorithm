//방법 1: BFS
#include<iostream>
#include<queue>

using namespace std;

int n, m, r, c, d;
int place[50][50], clean[50][50];
//idx 0 : 북, 1 : 동, 2 : 남, 3 : 서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int answer;

//왼쪽으로 회전
int turnDirection(int n) {
	if (n == 0) return 3;	//북이면 서쪽으로
	else if (n == 1) return 0;	//동이면 북으로
	else if (n == 2) return 1;	//남이면 동으로
	else if (n == 3) return 2;	//서쪽이면 남으로
}

int backDirection(int n) {
	if (n == 0) return 2;	//북이면 남쪽으로
	else if (n == 1) return 3;	//동이면 서쪽으로
	else if (n == 2) return 0;	//남쪽이면 북쪽으로
	else if (n == 3) return 1;	//서쪽이면 동쪽으로
}

queue<pair<pair<int, int>, int>> q;

void bfs() {
	answer++;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		int nextDir = dir;
		bool flag = false;	//네 방향이 청소가 되었는지 판단 true는 청소 완료
		for (int i = 0; i < 4; i++) {
			nextDir = turnDirection(nextDir);
			int nx = x + dx[nextDir];
			int ny = y + dy[nextDir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (clean[nx][ny] == 1) continue;
			if (place[nx][ny] == 0) {
				q.push({ {nx,ny}, nextDir });
				clean[nx][ny] = 1;
				answer++;
				flag = true;	//청소를 할 곳이 한군데라도 있으면 true
				break;	//다음 방향 확인하러 감
			}
		}
		//네방향 모두 청소가 되어있다면
		if (flag == false) {
			int bDir = backDirection(dir);
			int nx = x + dx[bDir];
			int ny = y + dy[bDir];
			if (place[nx][ny] == 0) {
				q.push({ {nx,ny}, dir });
				clean[nx][ny] = 1;
			}
			else return;	//종료
		}
	}
}

int main() {
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> place[i][j];
	q.push({ {r,c,}, d });
	clean[r][c] = 1;

	//cout << "BFS 시작 전: " << '\n';
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << clean[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	answer = 0;
	bfs();

	//cout << "BFS 시작 후: " << '\n';
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << clean[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << "청소한 구역들: "<< answer << '\n';
	cout << answer << '\n';
	return 0;
}




////방법 2: 구현


//#include<iostream>
//
//using namespace std;
//
//int n, m, r, c, d;	//세로, 가로, 로봇 좌표x,y ,바라보는 방향
//int place[50][50];	//구역
//
////차례대로 북(0) 동(1) 남(2) 서(3)
//int dx[4] = { -1,0,1,0 };	//r
//int dy[4] = { 0,1,0,-1 };	//c
//
//
//pair<pair<int, int>, int> robot;
//
////청소기가 다음으로 바라볼 방향 정함
//int turnDir(int d) {
//	if (d == 0) return 3;	//북(0)이라면 왼쪽방향이 서(3)로
//	else if (d == 1) return 0;	//동(1)이라면 왼쪽방향인 북(0)으로
//	else if (d == 2) return 1;	//남(2)이라면 왼쪽방향인 동(1)으로
//	else if (d == 3) return 2;	//서(3)라면 왼쪽방향인 남(2)으로
//}
//
//void solution() {
//	int x = robot.first.first;
//	int y = robot.first.second;
//	int d = robot.second;
//	int cleanCnt = 0;	//청소한 구역들 카운트 변수
//	place[x][y] = 2;	//첫 자리는 청소한 것으로 간주
//	cleanCnt++;
//
//	int nx, ny, nd;	//다음 좌표 및 바라보는 방향
//
//	while (true) {	// 청소기가 작동 멈추면 종료
//		int back = d;	//후진을 위해 temp 변수를 기존 방향으로 기억
//		bool canClean = false;
//		int cannotClean = 0;	//4가 되면 모든 칸이 찻거나 벽이있단얘기
//		for (int i = 0; i < 4; i++) {
//			nd = turnDir(d);
//			//정해진 방향의 왼쪽방향으로 움직임
//			nx = x + dx[nd];
//			ny = y + dy[nd];
//
//			if (place[nx][ny] == 0) {
//				canClean = true;	//청소할 수 있다고 true 표시
//				break;
//			}
//			//맵이 벽(1)이거나 청소한(2) 부분 또는 범위를 넘어가면 넘어가
//			else if (place[nx][ny] == 1 || place[nx][ny] == 2 ||
//				(nx < 0 || ny < 0 || nx >= n || ny >= m)) {
//				d = nd;	//방향 바꾸어줌
//				cannotClean++;	//그 방향은 이동하지 않고 못이동하니까 1 증가
//			}
//		}
//		if (canClean == true) {
//			//청소할 수 있으면
//			place[nx][ny] = 2;	//청소했다고 표시
//			cleanCnt++;
//			d = nd;
//		}
//		if (cannotClean == 4) {
//			//이동할 방향이 이미 방문했거나 벽이라 네 방향으로 모두 이동이 불가하면
//			//뒤로 후진한다. 방향은 유지한채로
//			nx = x - dx[back];	//기존 x 좌표에서 뒤로 한칸
//			ny = y - dy[back];	//기존 y 좌표에서 뒤로 한칸
//			d = back;			//바라보는 방향은 이전 그대로
//			if ((nx < 0 || ny < 0 || nx >= n || ny >= m) || place[nx][ny] == 1) {
//				//범위를 벗어나거나 벽이라면 끝
//				break;
//			}
//		}
//		x = nx;
//		y = ny;
//	}
//	cout << cleanCnt << '\n';
//}
//
//int main() {
//	cin >> n >> m;
//	cin >> robot.first.first >> robot.first.second >> robot.second;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> place[i][j];
//		}
//	}
//
//	solution();
//
//	return 0;
//}


