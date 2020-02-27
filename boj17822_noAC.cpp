#include<iostream>

using namespace std;

int n, m, t, xi, di, ki;
int map[51][51];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void rotate(int x, int dir, int jump) {
	if (dir == 0) {
		//�ð� ����
		for (int i = x; i <= n; i *= 2) {
			//x������ ����� �� ������. ( 1 ����)
			for (int t = 0; t < jump; t++) {
				int temp = map[i][m];
				for (int j = m; j > 1; j--) {
					map[i][j] = map[i][j - 1];
				}
				map[i][1] = temp;
			}
			if (i == 1) break;
		}
	}
	else {
		//�� �ð� ����
		for (int i = x; i <= n; i *= 2) {
			for (int t = 0; t < jump; t++) {
				int temp = map[i][1];
				for (int j = 1; j < m; j++) {
					map[i][j] = map[i][j + 1];
				}
				map[i][m] = temp;
			}
			if (i == 1) break;
		}
	}
}

void print() {
	cout << "==================\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "==================\n";
}

bool bfs(int i, int j) {
	bool flag = false;
	int x = i;
	int y = j;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		//if (nx >= 1 && ny >= 1 && nx < n + 1 && ny < m + 1) {
		//	//���� ������ Ž��
		//	if (map[x][y] == map[nx][ny]) {
		//		//���� ���ٸ�
		//		map[x][y] = 0;
		//		map[nx][ny] = 0;
		//		flag = true;
		//	}
		//}
		if (nx <= 0) continue;
		if (nx > n) continue;
		if (ny <= 0) ny = m;
		if (ny > m) ny = 1;
		if (map[nx][ny] == map[x][y]) {
			map[x][y] = 0;
			map[nx][ny] = 0;
			flag = true;
		}
	}
	return flag;
}

bool lookAround() {
	bool flag = false;	//������ ���� �ִ��� ������ Ȯ��. ���ٸ� �״�� false�� ��ȯ�ɰ���
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != 0) {	//0�� �ƴ� ���鸸 ������
				if (bfs(i, j) == 1) flag = true;
			}
		}
	}
	return flag;
}

double getAvg() {
	double sum = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != 0) {
				sum += map[i][j];
				++cnt;
			}
		}
	}
	double avg = sum / cnt;
	//cout << "����� " << sum << "/" << cnt << "�� " << avg << "�Դϴ�\n";
	return avg;
}

void countTotal() {
	int total = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != 0) {
				total += map[i][j];
			}
		}
	}
	cout << total << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < t; i++) {
		cin >> xi >> di >> ki;
		rotate(xi, di, ki);
		bool flag = lookAround();
		if (flag == 0) {
			double avg = getAvg();
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (map[i][j] >= 1) {
						if (map[i][j] < avg) {
							//���ߴ� ����� �� ũ��. �� ������ ���ڰ� ���� 1 ���ϱ�
							map[i][j] = map[i][j] + 1;
						}
						//if (map[i][j] > avg) {
						else {
							//������ ���ڰ� �� ŭ. 1 ����
							map[i][j] = map[i][j] - 1;
						}
					}
				}
			}
		}
	}
	//print();
	countTotal();
	return 0;
}