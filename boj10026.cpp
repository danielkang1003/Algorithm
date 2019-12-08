#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n;
char paper[100][100];
int check[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int rgb, rrb;	//일반인(rgb), 색맹(rrb) 으로 구별

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (check[nx][ny] == 1 || paper[nx][ny] != paper[x][y]) continue;
			//방문했거나, 이전 값과 지금 비교하는값이 다르다면 넘어가고
			//방문하지 않고 비교하는 값이 같으면 push
			q.push({ nx,ny });
			check[nx][ny] = 1;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	//일반인 bfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				bfs(i, j);
				rgb++;
			}
		}
	}
	
	//초기화를 해서 색약 답 구별
	memset(check, 0, sizeof(check));
	
	//Green을 Red로 변경
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i][j] == 'G')
				paper[i][j] = 'R';
		}
	}
	//bfs한번 더 돌리기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				bfs(i, j);
				rrb++;
			}
		}
	}
	cout << rgb << ' ' << rrb;


	return 0;
}