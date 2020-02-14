#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int n, k, l;	//map 크기, 사과 개수, 뱀의 방향 변환 횟수
int map[100][100];
deque<pair<int, int>> dq;
vector<pair<int, char>> info;

//동 서 남 북
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int changeDir(int dir, char way) {
	if (way == 'L') {	//왼쪽으로 90도 회전
		if (dir == 0) return 3;			//동쪽에서 북쪽으로
		else if (dir == 1) return 2;	//서쪽은 남쪽으로
		else if (dir == 2) return 0;	//남쪽에서 동쪽으로
		else if (dir == 3) return 1;	//북쪽이면 서쪽으로
	}
	else if (way == 'D') {
		if (dir == 0) return 2;			//동쪽에서 남쪽으로
		else if (dir == 1) return 3;	//서쪽이면 북쪽으로
		else if (dir == 2) return 1;	//남쪽이면 서쪽으로
		else if (dir == 3) return 0;	//북쪽이면 동쪽으로
	}
}

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x = x - 1, y = y - 1;
		map[x][y] = 1;	//사과는 1로 표시
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int sec;
		char dir;
		cin >> sec >> dir;
		info.push_back({ sec, dir });	//뱀이 움직여야할 정보 저장
	}

	int x = 0, y = 0, dir = 0, time = 0, idx = 0;
	dq.push_back({ x,y });
	map[x][y] = 2;
	while (true) {
		time++;
		int nx = x + dx[dir];	//오른쪽 방향으로 처음에 이동
		int ny = y + dy[dir];
		if ((nx < 0 || ny < 0 || nx >= n || ny >= n) || map[nx][ny] == 2) break;
		else if (map[nx][ny] == 0) {
			//빈칸이라면
			map[nx][ny] = 2;
			map[dq.back().first][dq.back().second] = 0;	//기존 자리를 0으로
			dq.pop_back();	//처음에 넣어두었던 뱀의 자리 빼주기
			dq.push_front({ nx,ny });	//이동한 뱀의 자리 넣어주기
		}
		else if (map[nx][ny] == 1) {
			//사과가 있다면
			map[nx][ny] = 0;
			dq.push_front({ nx,ny });	//머리를 늘려서 다음칸에 위치. 꼬리는 그대로
		}

		if (idx < info.size()) {
			if (time == info[idx].first) {
				//현재 시간과 뱀이 이동하라고 지시한 시간만큼의 시간이 같으면
				if (info[idx].second == 'L') dir = changeDir(dir, 'L');
				else if (info[idx].second == 'D') dir = changeDir(dir, 'D');
				idx++;
			}
		}
		x = nx;
		y = ny;
	}
	cout << time << '\n';


	return 0;
}