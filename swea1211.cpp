#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int tnum, minCnt, answer;
int map[100][100];

////내려가기, 오른쪽, 왼쪽
//int dx[3] = { 1,0,0 };
//int dy[3] = { 0,1,-1 };

vector<pair<int, int>> start;

void init() {
	minCnt = 987654321;	//최소 거리
	answer = -1;	//사다리 번호
	start.clear();
}

void input() {
	cin >> tnum;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> map[i][j];
			if (i == 0 && map[i][j] == 1) start.push_back({ i,j });
		}
	}
}

int ladderGame(int sx, int sy) {	//시작점 끝점
	int dir = 0;
	int x = sx, y = sy;
	int cnt = 0;
	while (true) {
		if (dir == 0) {//아래로 내려가기
			x++;
			cnt++;
			while (true) {
				if (x == 99) return cnt;//도착
				if (y + 1 < 100) {	//배열 범위내
					if (map[x][y + 1] == 1) { //오른쪽에 길이 있음
						dir = 1;
						break;
					}
				}
				if (y - 1 >= 0) {
					if (map[x][y - 1] == 1) {	//왼쪽에 길이 있음
						dir = 2;
						break;
					}
				}
				//좌우에 길이 없다면 밑으로 내려가줌
				x++;
				cnt++;
			}
		}
		else if (dir == 1) {
			y++;
			cnt++;
			while (true) {
				if (x + 1 < 100) {
					if (map[x + 1][y] == 1) {//아래로 내려가는 길이 생김
						dir = 0;
						break;
					}
				}
				//계속 오른쪽 방향이면 계속 가기
				y++;
				cnt++;
			}
		}
		else if (dir == 2) {
			y--;
			cnt++;
			while (true) {
				if (x + 1 < 100) {
					if (map[x + 1][y] == 1) {
						dir = 0;
						break;
					}
				}
				//위 조건 아닐 시 왼쪽 방향으로 계속 이동
				y--;
				cnt++;
			}
		}
	}
}

void simulation() {
	for (int i = 0; i < start.size(); i++) {
		int x = start[i].first, y = start[i].second;
		//cout << x << ' ' << y << '\n';
		int temp = ladderGame(x, y);	//카운트 세기위함
		if (minCnt > temp) {
			minCnt = temp;
			answer = y;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	for (int t = 1; t <= 10; t++) {
		init();
		input();
		simulation();
		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}

/*
1
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 1
*/