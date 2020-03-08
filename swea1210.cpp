#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int map[100][100];
//북 동 서. 위로 올라가므로 남쪽 필요 x
int dx[4] = { -1,0,0 };
int dy[4] = { 0,-1,1 };

pair<int, int> goal;

void dfs(int x, int y) {	//골 포인트 x y
	int dir = 0;
	while (true) {
		if (x == 0) {
			cout << y << '\n';	//종료 점
			return;
		}
		if (dir == 0) {
			x--;
			while (true) {
				if (x == 0) break;	//시작점에 도착함
				if (y + 1 < 100) {	//범위 내에서
					if (map[x][y + 1] == 1) {	//동쪽에 길이 있다면
						dir = 1;
						break;
					}
				}
				if (y - 1 >= 0) {	//범위 내
					if (map[x][y - 1] == 1) {//서쪽에 길이 있다면
						dir = 2;
						break;
					}
				}
				x--;	//둘다 해당 안되면 올라감
			}
		}
		else if (dir == 1) {	//동쪽으로 이동
			y++;	//오른쪽으로 이동시켜주기
			while (true) {
				if (x - 1 >= 0) {	//시작점에 도착하지 않았다면
					if (map[x - 1][y] == 1) {//위에 길이 있으면 더이상 동쪽에 길이 없다는 거므로 종료
						dir = 0;
						break;
					}
				}
				y++;	//그렇지 않으면
			}
		}
		else if (dir == 2) {	//서쪽으로 이동. 위와 동일
			y--;
			while (true) {
				if (x - 1 >= 0) {
					if (map[x - 1][y] == 1) {
						dir = 0;
						break;
					}
				}
				y--;
			}
		}
	}
}

//끝점에서 올라오도록 구현
int main() {
	for (int t = 0; t < 10; t++) {
		int tnum;
		cin >> tnum;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) goal.first = i, goal.second = j; //도착지점에서 출발하기
			}
		}
		cout << "#" << tnum << " ";
		dfs(goal.first, goal.second);
	}
	return 0;
}


/*
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 1 1 1
1 0 0 0 1 0 1 0 0 1
1 1 1 1 1 0 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 1 0 1 0 0 2

output = 4
*/