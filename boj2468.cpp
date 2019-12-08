#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int safeArea[100][100];
int check[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<int> v;
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
			if (check[nx][ny] == 1 || safeArea[nx][ny] == 0) continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
		}
	}
}

int main() {
	cin >> n;
	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> safeArea[i][j];
			if (safeArea[i][j] > max) {
				max = safeArea[i][j];
			}
		}
	}
	//cout <<"max: " << max<<'\n';
	for (int k = 0; k <= max; k++) {
		//cout << "시도 = " << k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (safeArea[i][j] > 0) {
					safeArea[i][j] = safeArea[i][j] - 1;
				}
				else continue;
			}
		}
		//cout << '\n';
		cnt = 0;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0 && safeArea[i][j] != 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		v.push_back(cnt);

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << safeArea[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "안전영역: " <<cnt << '\n';*/

	}
	sort(v.begin(), v.end());
	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}*/
	cout << '\n' << v[v.size() - 1];
	return 0;
}