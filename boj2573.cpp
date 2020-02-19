#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int n, m;
int map[300][300], c_map[300][300];
bool check[300][300];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void landCnt(int i, int j) {
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
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0) continue;
			if (check[nx][ny] == 1) continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
		}
	}
}

int cntWater(int i, int j) {
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int x = i + dx[dir];
		int y = j + dy[dir];
		if (map[x][y] == 0) {
			cnt++;
		}
	}
	//cout << "좌표 x: " << i << " y: " << j << "의 주변 물 수: " << cnt << '\n';
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int year = 0;
	while (true) {
		int divide = 0;
		memset(check, 0, sizeof(check));
		memset(c_map, 0, sizeof(c_map));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && check[i][j] == 0) {
					landCnt(i, j);
					divide++;
				}
			}
		}
		//cout << "divide: " << divide << '\n';
		if (divide >= 2) {
			cout << year << '\n';
			break;
		}
		if (divide == 0) {
			cout << 0 << '\n';
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					c_map[i][j] = map[i][j] - cntWater(i, j);
					if (c_map[i][j] < 0) c_map[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = c_map[i][j];
			}
		}
		year++;
	}
	return 0;
}



//시간초과 난 코드. 첫 시도의 로직. vector로 처음에 섬의 좌표와 높이를 다 받아놓고
//거기서 물에 닿은 빙산의 계산 등 모든 작업을 계속 돌려서 초과난듯하다.
/*
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, m;
int map[300][300], c_map[300][300];
bool check[300][300];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<pair<pair<int, int>, int>> v;


int cntWater(int i, int j) {
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int x = i + dx[dir];
		int y = j + dy[dir];
		if (x < 0 || y < 0 || x >= n || x >= m) continue;
		if (map[x][y] == 0) {
			cnt++;
		}
	}
	//cout << "주변 물: " << cnt << '\n';
	return cnt;
}

void afterMelting(int water) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] -= water;
			if (map[i][j] < 0) map[i][j] = 0;
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bfs(int i, int j, int labeling) {
	queue<pair<int, int>> q;
	check[i][j] = 1;
	q.push({ i,j });
	c_map[i][j] = labeling;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] == 1) continue;
			if (map[nx][ny] == 0) continue;
			q.push({ nx,ny });
			check[nx][ny] = 1;
			c_map[nx][ny] = labeling;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) v.push_back({ {i, j}, map[i][j] });
		}
	}
	int year = 1;
	while (true) {
		for (int i = 0; i < v.size(); i++) {
			//cout << "좌표: " << v[i].first.first << ' ' << v[i].first.second << " 높이: " << v[i].second << '\n';
			int water = cntWater(v[i].first.first, v[i].first.second);
			v[i].second -= water;
			if (v[i].second < 0) v[i].second = 0;
		}
		for (int k = 0; k < v.size(); k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (v[k].first.first == i && v[k].first.second == j) {
						map[i][j] = v[k].second;
					}
				}
			}
		}
		cout << "====물로 빙하가 녹았습니다.\n";
		print();
		cout << "===========================\n";
		int divide = 0;
		memset(check, 0, sizeof(check));
		memset(c_map, 0, sizeof(c_map));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && check[i][j] == 0) {
					bfs(i, j, ++divide);
				}
			}
		}
		cout << "###### " <<year << " 년이 지난 후 빙하 연결#####\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << c_map[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "###############################\n";

		if (divide >= 2) {
			cout << year << '\n';
			break;
		}
		if (divide == 0) {
			cout << 0 << '\n';
			break;
		}
		year++;
	}

	return 0;
}
*/

