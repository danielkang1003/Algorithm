#include<iostream>
#include<queue>

using namespace std;

int m, n;
int sx, sy, sdir;	//시작 위치와 방향
int destinationX, destinationY, destinationDir;	//도착 위치와 방향
int map[101][101];
bool check[101][101];

//동 서 남 북	0번째 사용 x
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };

void input() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sx >> sy >> sdir;
	cin >> destinationX >> destinationY >> destinationDir;
}

void Move(int dir) {	//바라보는 방향으로 1,2,3칸 중 하나 이동

}

int turnDir(int dir) {	//왼쪽으로 방향 전환
	if (dir == 1) return 3;	//동 -> 남
	else if (dir == 2) return 4;	//서 -> 북
	else if (dir == 3) return 2;	//남 -> 서
	else if (dir == 4) return 1;	//북 -> 동
}

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {sx,sy}, {sdir, 0} });	//위치 x,y, 방향, 명령 수
	check[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curDir = q.front().second.first;	//현재 바라보는 방향
		int orderCnt = q.front().second.second;
		q.pop();
		if (x == destinationX && y == destinationY) {
			bool flag = false;
			while (true) {
				if (curDir != destinationDir) {
					int nextDir = turnDir(curDir);
					curDir = nextDir;
					flag = true;
					if (curDir == destinationDir) break;
				}
			}
			if (flag == true) cout << orderCnt + 1;
			else cout << orderCnt;
			return;
		}
		//바라보는 방향으로 이동 또는 방향 전환만 가능
		for (int dir = 1; dir <= 4; dir++) {	//다음 방향을 본다
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 1 || ny < 1 || nx >= m + 1 || ny >= n + 1) continue; //범위 밖
			if (check[nx][ny] == 1) continue;	//방문한 곳
			if (map[nx][ny] == 1) continue;	//궤도 없어서 이동 불가
			if (dir == curDir) {	//현재 바라보는 방향이랑 이동하려는 방향이 같다면
				Move(dir);
			}
			else {	//방향이 달라 이동을 못해 방향을 전환해주어야한다면
				while (true) {
					//cout << "현재 좌표: " << x <<", "<< y <<"에서 방향을 전환합니다 " << curDir <<" ";
					int nextDir = turnDir(curDir);
					curDir = nextDir;
					//cout << "에서 " << nextDir << "로 전환 완료!\n";
					if (curDir == dir) break;
				}
			}
			//cout << "현재 좌표 (" << x << "," << y << ")" << "바라보는 방향: " << curDir << " 다음 좌표 (" << nx << "," << ny << ")\n";
			q.push({ {nx,ny},{curDir, orderCnt + 1} });
			check[nx][ny] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	input();
	bfs();
	return 0;
}