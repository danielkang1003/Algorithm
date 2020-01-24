#include<iostream>

using namespace std;

int n, m, x, y, k;	//세로, 가로, 지도 좌표, 명령 수
int map[20][20];

int dice[6];	//1: 윗면, 3 아래면, 4: 왼쪽 면, 5: 오른쪽 면, 0: 앞쪽 면, 2: 뒤쪽면
//차례로 동 서 북 남(주어진 입력에서는 1,2,3,4)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

// 주사위
// 기존
//	0		동		0		서		0
//4 1 5		-->	  3 4 1		-->	  1 5 3
//	2				2				2
//	3				5				4
//
//	북		남
//	1		3
//4 2 5	  4 0 5
//	3		1
//	0		2

void move_dice(int dir) {
	int ndice[6];
	switch (dir) {
	case 0:
		//동쪽 방향 이면
		ndice[0] = dice[0];
		ndice[1] = dice[4];
		ndice[2] = dice[2];
		ndice[3] = dice[5];
		ndice[4] = dice[3];
		ndice[5] = dice[1];
		break;
	case 1:
		//서쪽이면
		ndice[0] = dice[0];
		ndice[1] = dice[5];
		ndice[2] = dice[2];
		ndice[3] = dice[4];
		ndice[4] = dice[1];
		ndice[5] = dice[3];
		break;
	case 2:
		//북쪽이면
		ndice[0] = dice[1];
		ndice[1] = dice[2];
		ndice[2] = dice[3];
		ndice[3] = dice[0];
		ndice[4] = dice[4];
		ndice[5] = dice[5];
		break;
	case 3:
		//남쪽이면
		ndice[0] = dice[3];
		ndice[1] = dice[0];
		ndice[2] = dice[1];
		ndice[3] = dice[2];
		ndice[4] = dice[4];
		ndice[5] = dice[5];
		break;
	default:
		break;
	}
	for (int i = 0; i < 6; i++) {
		dice[i] = ndice[i];
	}
}

int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int dir;
		cin >> dir;
		dir--;	//dx,dy를 위해 -1을 해주어서 처리함
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		move_dice(dir);	//방향으로 움직이는 함수 실행
		if (map[nx][ny] == 0) {
			map[nx][ny] = dice[3];	//맵이 0이라면 밑면(dice 3)을 복사하라고 문제에서 제시
		}
		else {
			dice[3] = map[nx][ny];
			map[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		cout << dice[1] << '\n';	//윗면 출력
	}

	return 0;
}