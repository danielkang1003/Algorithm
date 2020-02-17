#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int n;
int map[25][25];
bool check[25][25];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> v;

void print() {
	cout << "################\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "################\n";
}

void bfs(int sx, int sy, int cnt) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	check[sx][sy] = 1;
	int area = 0;
	while (!q.empty()) {
		area++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//cout << "ÇöÀç x: " << x << " y: " << y << '\n';

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == 0) continue;
			if (check[nx][ny] == 1) continue;
			q.push({ nx,ny });
			map[nx][ny] = cnt;
			check[nx][ny] = 1;
		}
	}
	//cout << area << '\n';
	v.push_back(area);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				bfs(i, j, cnt++);
			}
		}
	}
	//print();
	sort(v.begin(), v.end());
	cout << cnt - 1 << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}