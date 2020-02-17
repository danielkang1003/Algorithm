#include<iostream>
#include<queue>

using namespace std;

int m, n, answer;
int map[1000][1000];
bool check[1000][1000];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<pair<int, int>, int>> q;


void print() {
	cout << "##############\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "##############\n";
}
//�丶�� �ʹ� �� ������ �ѹ� ���Ƽ� �� ������ �մ��� Ȯ��
bool checkMatured() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		//cout << "���� BFS ���� ��ǥ x: " << x << " y: " << y << " cnt: " << cnt <<'\n';

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;	//���� ���
			if (map[nx][ny] == -1) continue;	//��
			if (check[nx][ny] == 1) continue;	//�湮�ߴٸ�
			//cout << "���ǿ� �����ϴ� ���� ��ǥ nx: " << nx << " ny: " << ny << '\n';
			map[nx][ny] = map[x][y] + 1;
			check[nx][ny] = 1;
			q.push({ {nx,ny}, cnt + 1 });
			//print();
		}
		answer = cnt;
	}
	if (checkMatured() == 0) cout << "-1\n";
	else cout << answer << '\n';
}



int main() {
	cin >> m >> n;
	bool matured = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) matured = false;
		}
	}
	//�̹� ��� �丶�䰡 �;��ִ� ����
	if (matured == true) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				q.push({ {i,j}, 0 });
				check[i][j] = 1;
			}
		}
	}
	bfs();

	return 0;
}