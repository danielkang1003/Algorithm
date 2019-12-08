#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
/*
������ ��Ȯ�� ���� �ʾƼ� ����� ����
�������� �Էµ� ���̿��� max���� ���ؼ� max�� ��ŭ�� ������ 70%�������� Ʋ�ȴٰ� ����.

������ �ٽ� �о�� ���̴� 1 ~100���� �������־���.
���� �迭�� �ϳ� �� ������ְ�, ���̰� ������ �� ���� �Էµ� ���̶� ���ؼ�
���� �����̶�� cArea�迭�� �־��ְ� bfs�� ���ȴ�.
�� ���� ������ �ٽ� �迭�� �ʱ�ȭ ���ְ� ������ ���̸�ŭ �ٽ� �ִ� ����������
���ϰ� res�� �־��־���.
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