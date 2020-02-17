#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int m, n, k;
int map[100][100];
bool check[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> v;
void print() {
	cout << "################\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "################\n";
}

void bfs(int sx, int sy, int label) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	check[sx][sy] = 1;
	map[sx][sy] = label;
	int area = 0;
	while (!q.empty()) {
		area++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (map[nx][ny] == -1) continue;
			if (check[nx][ny] == 1) continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
			map[nx][ny] = label;
		}
	}
	//cout << area << '\n';
	v.push_back(area);
}

int main() {
	cin >> m >> n >> k;
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				map[i][j] = -1;
			}
		}
	}
	//print();

	int label = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && check[i][j] == 0) {
				bfs(i, j, ++label);
			}
		}
	}
	//print();
	cout << label << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	return 0;
}