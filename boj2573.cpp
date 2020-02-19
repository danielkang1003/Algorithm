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
	//cout << "��ǥ x: " << i << " y: " << j << "�� �ֺ� �� ��: " << cnt << '\n';
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



//�ð��ʰ� �� �ڵ�. ù �õ��� ����. vector�� ó���� ���� ��ǥ�� ���̸� �� �޾Ƴ���
//�ű⼭ ���� ���� ������ ��� �� ��� �۾��� ��� ������ �ʰ������ϴ�.
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
	//cout << "�ֺ� ��: " << cnt << '\n';
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
			//cout << "��ǥ: " << v[i].first.first << ' ' << v[i].first.second << " ����: " << v[i].second << '\n';
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
		cout << "====���� ���ϰ� ��ҽ��ϴ�.\n";
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
		cout << "###### " <<year << " ���� ���� �� ���� ����#####\n";
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

