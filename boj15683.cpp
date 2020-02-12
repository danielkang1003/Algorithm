#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, cctvCount, answer;
int map[8][8], c_map[8][8];
vector<pair<pair<int, int>, pair<int, int>>> cctv;	//각 5개의 cctv가 담겨있음 cctv((x,y),(번호,방향)) 초기 방향 -1


////////////////////////////////////////////////////////////
//cctv가 보는 방향대로 맵에 확인 남기기
void Right(int x, int y) {
	for (int j = y + 1; j < m; j++) {
		if (c_map[x][j] == 6) break;	//벽에 막힘
		if (c_map[x][j] >= 1 && c_map[x][j] <= 5) continue;
		c_map[x][j] = -1;	//빈칸만 -1로 보았다고 표시
	}
}

void Left(int x, int y) {
	for (int j = y - 1; j >= 0; j--) {
		if (c_map[x][j] == 6) break;
		if (c_map[x][j] >= 1 && c_map[x][j] <= 5) continue;
		c_map[x][j] = -1;
	}
}

void up(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (c_map[i][y] == 6) break;
		if (c_map[i][y] >= 1 && c_map[i][y] <= 5) continue;
		c_map[i][y] = -1;
	}
}

void down(int x, int y) {
	for (int i = x + 1; i < n; i++) {
		if (c_map[i][y] == 6) break;
		if (c_map[i][y] >= 1 && c_map[i][y] <= 5) continue;
		c_map[i][y] = -1;
	}
}

//////////////////////////////////////////////////////////
void checkBlockedPoint() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c_map[i][j] = map[i][j];
		}
	}
	int size = cctv.size();
	for (int i = 0; i < size; i++) {
		//각 cctv 마다 설정
		if (cctv[i].second.first == 1) {
			//1번 cctv는 모든 방향으로 돌 수 있음
			if (cctv[i].second.second == 0) Right(cctv[i].first.first, cctv[i].first.second);
			else if (cctv[i].second.second == 1) Left(cctv[i].first.first, cctv[i].first.second);
			else if (cctv[i].second.second == 2) down(cctv[i].first.first, cctv[i].first.second);
			else if (cctv[i].second.second == 3) up(cctv[i].first.first, cctv[i].first.second);
		}
		else if (cctv[i].second.first == 2) {
			//2번 cctv는 양쪽 또는 위 아래로 돌 수 있음
			if (cctv[i].second.second == 0 || cctv[i].second.second == 1) {
				Right(cctv[i].first.first, cctv[i].first.second);
				Left(cctv[i].first.first, cctv[i].first.second);
			}
			else if (cctv[i].second.second == 2 || cctv[i].second.second == 3) {
				up(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
			}
		}
		else if (cctv[i].second.first == 3) {
			//3번 cctv는 직각 방향으로 감시
			if (cctv[i].second.second == 0) {
				up(cctv[i].first.first, cctv[i].first.second);
				Right(cctv[i].first.first, cctv[i].first.second);
			}
			if (cctv[i].second.second == 1) {
				Right(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
			}
			if (cctv[i].second.second == 2) {
				down(cctv[i].first.first, cctv[i].first.second);
				Left(cctv[i].first.first, cctv[i].first.second);
			}
			if (cctv[i].second.second == 3) {
				Left(cctv[i].first.first, cctv[i].first.second);
				up(cctv[i].first.first, cctv[i].first.second);
			}
		}
		else if (cctv[i].second.first == 4) {
			if (cctv[i].second.second == 0) {
				Left(cctv[i].first.first, cctv[i].first.second);
				up(cctv[i].first.first, cctv[i].first.second);
				Right(cctv[i].first.first, cctv[i].first.second);
			}
			else if (cctv[i].second.second == 1) {
				up(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
				Right(cctv[i].first.first, cctv[i].first.second);
			}
			else if (cctv[i].second.second == 2) {
				Left(cctv[i].first.first, cctv[i].first.second);
				Right(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
			}
			else if (cctv[i].second.second == 3) {
				Left(cctv[i].first.first, cctv[i].first.second);
				up(cctv[i].first.first, cctv[i].first.second);
				down(cctv[i].first.first, cctv[i].first.second);
			}
		}
		else if (cctv[i].second.first == 5) {
			up(cctv[i].first.first, cctv[i].first.second);
			down(cctv[i].first.first, cctv[i].first.second);
			Left(cctv[i].first.first, cctv[i].first.second);
			Right(cctv[i].first.first, cctv[i].first.second);
		}
	}
}

int blockedArea() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_map[i][j] == 0) sum++;
		}
	}
	return sum;
}

void dfs(int cnt) {
	//cctv를 순열로 돌리며 방향 바꾸어주며 답을 도출
	if (cnt == cctvCount) {
		checkBlockedPoint();
		answer = min(answer, blockedArea());
		return;
	}
	for (int i = 0; i < 4; i++) {
		//0: 동, 1: 서, 2: 남, 3: 북
		cctv[cnt].second.second = i;
		dfs(cnt + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				//1~5까지 cctv 싹다 저장
				cctv.push_back({ {i,j}, {map[i][j], -1} });
			}
		}
	}
	cctvCount = cctv.size();
	answer = 987654321;
	dfs(0);
	cout << answer;
	return 0;
}