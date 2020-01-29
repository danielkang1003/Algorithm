#include<iostream>
#include<queue>

using namespace std;

int n, answer;
int house[16][16];	//0: 빈칸, 1: 벽
//동, 남, 대각선
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };
queue<pair<pair<int, int>, int>> q;

//bfs로 탐색 (메모리와 성능이 별로...)
void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curDir = q.front().second;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			//끝까지 도착했으면 탐색끝. 가능한 방법을 1 추가
			answer++;
			continue;
		}

		if (curDir == 0) {	//동쪽으로 향하는 방향
			//동쪽방향을 향할때 가능한 방향은 동쪽과 대각선이다.
			//남쪽은 불가능함.

			//1. (x,y) -> (nx,ny) : 동쪽으로 향하는 중
			int nx = x + dx[curDir];
			int ny = y + dy[curDir];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0) {
					q.push({ {nx,ny}, curDir });
				}
			}

			//2. 대각선으로 향할 수 있음 2번째 idx는 대각선을 가리킴
			nx = x + dx[2];
			ny = y + dy[2];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0 && house[x + 1][y] == 0 && house[x][y + 1] == 0) {
					//대각선으로 이동할 때는 동, 남, 그리고 대각선이 비어야한다. (조건)
					q.push({ {nx,ny}, 2 });	//방향을 대각선으로 설정하는 좌표를 넣어줌
				}
			}
		}
		else if (curDir == 1) {	//남쪽으로 향할 때
			//동쪽과 같은 로직.
			//남쪽으로향하는데 동쪽으로는 이동을 하지 못함
			//따라서 nx, ny 는 남쪽 방향 또는 대각선만 가능하다
			//1. 남쪽 -> 남쪽으로
			int nx = x + dx[curDir];
			int ny = y + dy[curDir];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0) {
					q.push({ {nx,ny}, curDir });
				}
			}
			//2. 남쪽 -> 대각선으로
			nx = x + dx[2];
			ny = y + dy[2];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0 && house[x + 1][y] == 0 && house[x][y + 1] == 0) {
					q.push({ {nx,ny}, 2 });
				}
			}
		}
		else if (curDir == 2) { //대각선으로 향할 때
			//대각선은 방향이 세가지이다.
			//1. 대각선에서 대각선으로
			int nx = x + dx[curDir];
			int ny = y + dy[curDir];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0 && house[x + 1][y] == 0 && house[x][y + 1] == 0) {
					q.push({ {nx,ny}, curDir });
				}
			}
			//2. 대각선에서 동쪽으로
			nx = x + dx[0];
			ny = y + dy[0];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0) {
					q.push({ {nx,ny}, 0 });
				}
			}
			//3. 대각선에서 남쪽으로
			nx = x + dx[1];
			ny = y + dy[1];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (house[nx][ny] == 0) {
					q.push({ {nx,ny}, 1 });
				}
			}
		}
	}
}

//갈수 있는 방향인지 재귀로 탐색 메모리는 많이 단축. 시간도 조금 줄어들었음
void dfs(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) {
		answer++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if ((i == 0 && dir == 1) || (i == 1 && dir == 0)) {
			//i = 0,1,2로 동 남 북을 나타냄
			//dir = 1이면 남쪽 dir = 0이면 동쪽
			//즉 나아갈 방향(i)이 동쪽(0)인데 현재 파이프가 보고있는 방향이
			//남쪽(1)이면 이동이 불가능하다.
			//마찬가지로 남쪽(1)인데 현재 파이프가 가려는 방향이
			//동쪽(0)이라면 이동 불가이므로 넘어가준다
			continue;
		}
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= n || ny >= n || house[nx][ny] == 1) continue;
		
		if (i == 2 && (house[x][y + 1] == 1 || house[x + 1][y] == 1 || house[nx][ny] == 1)) {
			//대각선 방향으로 파이프를 이동시킬 때 3방향이 모두 갈 수 있는지
			//즉 빈칸(house = 0)인지 확인해야함.
			//벽이라면 이동 불가
			continue;
		}
		dfs(nx, ny, i);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
		}
	}
	q.push({ {0,1}, 0 });	//시작점 (0,1), 방향 동
	//bfs();
	dfs(0, 1, 0);
	cout << answer << '\n';
	return 0;
}
