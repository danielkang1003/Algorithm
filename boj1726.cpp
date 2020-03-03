#include<iostream>
#include<queue>

using namespace std;

int m, n, a, b, c, ea, eb, ec;
int map[101][101];
bool check[101][101][5];	//방향에 따라 저장

//0번째 인덱스 제외하고 1부터 차례대로 동서남북
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };

pair<pair<int, int>, int> robot, desti;

void input() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> a >> b >> c;
	//시작점과 방향 입력받기
	robot.first.first = a;
	robot.first.second = b;
	robot.second = c;

	//끝점과 방향 입력받기
	cin >> ea >> eb >> ec;
	desti.first.first = ea;
	desti.first.second = eb;
	desti.second = ec;
}

//180도로 방향 돌리기
int turnDir(int dir, int ndir) {
	switch (dir) {
	case 1:	//현재 방향이 동쪽일 때
		if (ndir == 2) return 2;	//서쪽이라면 두번 명령수행해야 서쪽으로 이동가능
		break;
	case 2:	//현재 방향이 서쪽일 때
		if (ndir == 1) return 2;	//동쪽으로 가려면 두번 명령 수행해야함
		break;
	case 3:	//남쪽 일때
		if (ndir == 4) return 2;	//남에서 북으로 이동도 2번의 명령이 필요
		break;
	case 4:	//북쪽일 때
		if (ndir == 3) return 2;	//북에서 남으로도 2번의 명령으로 방향 전환 가능
		break;
	}
	return 1;	//나머지는 한칸. 왼 90 또는 오른 90으로 방향 변환가능
}

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	//시작점 x,y, 방향 그리고 명령 수 관리
	q.push({ {robot.first.first, robot.first.second},{robot.second, 0} });
	//시작점에 대해 방문처리
	check[robot.first.first][robot.first.second][robot.second] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curDir = q.front().second.first;
		int order = q.front().second.second;
		q.pop();

		if (x == desti.first.first && y == desti.first.second && curDir == desti.second) {
			//마지막 명령과 x,y 그리고 방향이 같다면 종료
			//cout << "최종 정답: (" << x << "," << y << ") 방향: " << curDir <<"이동 횟수: " << order << '\n';
			cout << order << '\n';
			return;
		}

		for (int i = 1; i <= 3; i++) {	//현재 방향으로 직진
			int nx = x + dx[curDir] * i;
			int ny = y + dy[curDir] * i;
			if (nx < 1 || ny < 1 || nx > m || ny > n) break;//범위 밖이라면 더이상 진행안해도됨
			if (map[nx][ny] == 1) break;	//궤도 이탈도 더이상 나아갈 필요 x
			if (check[nx][ny][curDir] == 1) continue;	//방문했던 점. 다른점은 방문안했을 수 있으므로 continue로
			//if (nx == desti.first.first && ny == desti.first.second) break;	//도착점이면 끝
			check[nx][ny][curDir] = 1;	//모든 조건 만족하면 방문처리
			q.push({ {nx,ny},{curDir, order + 1} });
			//cout << "(" << x << ',' << y << ")에서 (" << nx << "," << ny << ")로 이동. 방향: " << curDir << "명령 횟수: " << order + 1 << '\n';
		}
		for (int dir = 1; dir <= 4; dir++) {	//방향 탐색
			if (dir == curDir) continue;	//같은방향이라면 넘어감
			if (check[x][y][dir] == 0) {
				int orderCnt = order + turnDir(curDir, dir);
				q.push({ {x,y},{dir, orderCnt} });	//좌표는 변하지 않는다. 변한 방향과 명령횟수만큼만 넣어주기
				check[x][y][dir] = 1;
				//cout << "(" << x << ',' << y << ")에서 방향전환 실시. 변한 방향: " << curDir << " -> " <<dir  << " 명령 횟수: " << orderCnt << '\n';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	input();
	bfs();
	return 0;
}