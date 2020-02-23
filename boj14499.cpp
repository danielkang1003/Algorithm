#include<iostream>
#include<vector>

using namespace std;

int n, m, x, y, k;
int map[20][20];
int dice[7];
vector<int>v;

//차례대로 동서북남(0123)
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void moveDice(int dir) {
	//d1: 위, d2: 앞, d3 = 오, d4 = 왼, d5 = 뒤 , d6 = 밑
	int d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4], d5 = dice[5], d6 = dice[6];
	if (dir == 0) {	//동쪽 방향으로
		//2,5 (앞 뒤) 는 그대로
		dice[1] = d4;	//위
		dice[3] = d1;	//오
		dice[4] = d6;	//왼
		dice[6] = d3;	//밑
	}
	else if (dir == 1) {	//서쪽으로
		dice[1] = d3;
		dice[3] = d6;
		dice[4] = d1;
		dice[6] = d4;
	}
	else if (dir == 2) {	//북쪽으로
		//3,4(오,왼) 그대로
		dice[1] = d2;
		dice[2] = d6;
		dice[5] = d1;
		dice[6] = d5;
	}
	else if (dir == 3) {	//남쪽으로
		dice[1] = d5;
		dice[2] = d1;
		dice[5] = d6;
		dice[6] = d2;
	}
}

void getDir(int x, int y) {
	for (int i = 0; i < v.size(); i++) {
		int nx = x + dx[v[i]];
		int ny = y + dy[v[i]];
		int dir = v[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		moveDice(dir);
		if (map[nx][ny] == 0) {
			map[nx][ny] = dice[6];
		}
		else {
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice[1] << '\n';
		x = nx;
		y = ny;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	while (k--) {
		int order;
		cin >> order;
		order -= 1;	//0123으로 이동방향 판단하므로
		v.push_back(order);
	}
	getDir(x, y);
	return 0;
}