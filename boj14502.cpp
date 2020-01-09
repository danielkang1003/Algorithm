#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

int n, m, answer;
int lab[8][8];	//0은 빈칸, 1 은 벽, 2는 바이러스
int clab[8][8];
int visit[8][8];
int check[64];	//8 * 8 크기
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<pair<int, int>> Empty, Virus;
queue<pair<int, int>> q;
//bfs와 완탐 필요한 문제

void bfs(int a, int b) {
	q.push({ a,b });
	visit[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (visit[nx][ny] == 0 && clab[nx][ny] == 0) {
					clab[nx][ny] = 2;
					visit[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
//빈칸(안전 지역)을 셈
int safeArea() {
	int Cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (clab[i][j] == 0) {
				Cnt++;
			}
		}
	}
	return Cnt;
}

//벽이 3개가 되면 바이러스가 퍼지고 확인을 시작함
void spreadVirus() {
	int Cnt = 0;
	for (int i = 0; i < n; i++) {//카피해놓은 배열에서 사용하기
		for (int j = 0; j < m; j++) {
			clab[i][j] = lab[i][j];
		}
	}
	memset(visit, 0, sizeof(visit));
	int Esize = Empty.size();
	for (int i = 0; i < Esize; i++) {
		if (Cnt == 3) break;	//빈 공간만큼 돌면서 벽을 만들어줌
		if (check[i] == 1) {
			int x = Empty[i].first;
			int y = Empty[i].second;
			clab[x][y] = 1;	//벽을 지어주고
			Cnt++;			//몇개인지 확인하기 위해 사용한 벽을 하나씩 증가
		}
	}
	//그리고 바이러스를 퍼트리기 시작
	int size = Virus.size();
	for (int i = 0; i < size; i++) {
		int x = Virus[i].first;
		int y = Virus[i].second;
		bfs(x, y);	//바이러스 자리에서 bfs시작
	}
	int safeAreaCnt = safeArea();	//bfs를 다 돌고 빈칸을 세서 최대값을 구함
	answer = max(safeAreaCnt, answer);
}

//벽의 개수가 3이 되면 바이러스 퍼트려보기
void buildWall(int idx, int cnt) {
	if (cnt == 3) {
		spreadVirus();
		return;
	}
	//조합으로 벽 3개로 만들기
	int size = Empty.size();
	for (int i = idx; i < size; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			buildWall(i, cnt + 1);
			check[i] = 0;
		}
	}
}

//빈 칸과 바이러스를 확인하기위해 두 벡터에 0(빈칸) 과 2(바이러스)이면 넣어주기
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0) {
				Empty.push_back({ i,j });
			}
			if (lab[i][j] == 2) {
				Virus.push_back({ i,j });
			}
		}
	}

	//백트래킹 시작 (인덱스와 카운트는 0부터)
	buildWall(0, 0);
	cout << answer;
	return 0;
}