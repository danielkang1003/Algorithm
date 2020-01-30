#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n, m;
int iceberg[300][300], c_iceberg[300][300];	//0�� ��, ���ڴ� ���� ũ��
bool check[300][300];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

int landCnt, yearCnt, nearWaterCnt;	//����и�����, �ð�, �ֺ� ��
queue<pair<int, int>> q;

void printC() {
	cout << "\nC���� ���� ����\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << c_iceberg[i][j] << ' ';
		}
		cout << '\n';
	}
}

void print() {
	cout << "\niceberg ���� ����\n";
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
		//bfs�ȿ��� Ž���� �Ϸ��� ����. �ٵ� �̷��� �ϸ� �ϳ��� ��� �ٲ�⿡ �̷��� �ϸ� �ȉ�..
		/*nearWaterCnt = 0;
		cout << "���� Q���� ���� ��ǥ: ["<< x << "," << y << "] \n";
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny > m) continue;
			if (iceberg[nx][ny] == 0) {
				cout << "��ǥ [" << nx << ',' << ny << "]�� ���Դϴ�\n";
				nearWaterCnt++;
			}
		}
		cout << "Ž�� �� �ֺ� ���� ��: " << nearWaterCnt << '\n';
		if (iceberg[x][y] <= nearWaterCnt) {
			c_iceberg[x][y] = 0;
		}
		else {
			c_iceberg[x][y] -= nearWaterCnt;
		}
		cout << "1���� ���� �� ��ǥ [" << x << "," << y << "] �� ������ ũ��" << c_iceberg[x][y] <<'\n';
		cout << yearCnt << "���� ";
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