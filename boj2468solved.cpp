#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
/*
문제를 정확히 읽지 않아서 생겼던 문제
기존에는 입력된 높이에서 max값을 정해서 max값 만큼만 돌려서 70%정도에서 틀렸다고 떳다.

문제를 다시 읽어보니 높이는 1 ~100으로 정해져있었다.
따라서 배열을 하나 더 만들어주고, 높이가 증가할 떄 마다 입력된 값이랑 비교해서
안전 영역이라면 cArea배열에 넣어주고 bfs를 돌렸다.
다 돌고 나서는 다시 배열을 초기화 해주고 높아진 높이만큼 다시 최대 안전영역을
구하고 res에 넣어주었다.
*/

int n;
int safeArea[100][100];
int cArea[100][100];
int check[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt;

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
			if (check[nx][ny] == 1 || cArea[nx][ny] == 0) continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> safeArea[i][j];
		}
	}

	int res = 1;
	for (int k = 1; k <= 100; k++) {
		cnt = 0;
		memset(check, 0, sizeof(check));
		memset(cArea, 0, sizeof(cArea));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (safeArea[i][j] > k) {
					cArea[i][j] = safeArea[i][j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0 && cArea[i][j] != 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		res = max(res, cnt);
	}
	cout << res;
	return 0;
}