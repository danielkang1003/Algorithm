#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n, m;
int iceberg[300][300], c_iceberg[300][300];	//0은 물, 숫자는 빙산 크기
bool check[300][300];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

int landCnt, yearCnt, nearWaterCnt;	//빙산분리개수, 시간, 주변 물
queue<pair<int, int>> q;

void printC() {
	cout << "\nC빙산 현재 상태\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << c_iceberg[i][j] << ' ';
		}
		cout << '\n';
	}
}

void print() {
	cout << "\niceberg 현재 상태\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << iceberg[i][j] << ' ';
		}
		cout << '\n';
	}
}

void copyIceberg() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			iceberg[i][j] = c_iceberg[i][j];
		}
	}
}

void bfs(int i, int j) {
	q.push({ i,j });
	check[i][j] = 1;

	while (!q.empty()) {
		//memset(check, 0, sizeof(check));
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] == 0 && iceberg[nx][ny] != 0) {
				q.push({ nx,ny });
				check[nx][ny] = 1;
			}
		}
		//bfs안에서 탐색을 하려고 했음. 근데 이렇게 하면 하나씩 모두 바뀌기에 이렇게 하면 안됌..
		/*nearWaterCnt = 0;
		cout << "현재 Q에서 꺼낸 좌표: ["<< x << "," << y << "] \n";
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny > m) continue;
			if (iceberg[nx][ny] == 0) {
				cout << "좌표 [" << nx << ',' << ny << "]는 물입니다\n";
				nearWaterCnt++;
			}
		}
		cout << "탐색 후 주변 물의 수: " << nearWaterCnt << '\n';
		if (iceberg[x][y] <= nearWaterCnt) {
			c_iceberg[x][y] = 0;
		}
		else {
			c_iceberg[x][y] -= nearWaterCnt;
		}
		cout << "1년이 지난 후 좌표 [" << x << "," << y << "] 의 빙산의 크기" << c_iceberg[x][y] <<'\n';
		cout << yearCnt << "년후 ";
		printC();*/
	}
}

int nearWater(int x, int y) {
	nearWaterCnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (iceberg[nx][ny] == 0) {
			nearWaterCnt++;
		}
	}
	return nearWaterCnt;
}

void landCheck() {
	yearCnt = 0;
	while (true) {
		landCnt = 0;
		memset(check, 0, sizeof(check));
		memset(c_iceberg, 0, sizeof(c_iceberg));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (iceberg[i][j] != 0 && check[i][j] == 0) {
					landCnt++;
					bfs(i, j);
				}
			}
		}
		if (landCnt == 0) {
			cout << "0\n";
			break;
		}
		if (landCnt >= 2) {
			cout << yearCnt << '\n';
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (iceberg[i][j] != 0) {
					c_iceberg[i][j] = iceberg[i][j] - nearWater(i, j);
					if (c_iceberg[i][j] < 0) c_iceberg[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				iceberg[i][j] = c_iceberg[i][j];
			}
		}
		yearCnt++;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> iceberg[i][j];
	landCheck();
	return 0;
}