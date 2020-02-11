#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int map[100][100];
int bfscheck[100][100];
vector<pair<int, int>> land;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int answer;

void labeling(int i, int j, int num) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	bfscheck[i][j] = 1;
	map[i][j] = num;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		//cout << "(" << x << ',' << y << ") ��ǥ �����Դϴ�\n";
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (bfscheck[nx][ny] == 1) continue;
			if (map[nx][ny] == 0) continue;
			q.push({ nx,ny });
			map[nx][ny] = num;
			bfscheck[nx][ny] = 1;
		}
	}
}

void print() {
	cout << "##########################\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "##########################\n";
}

int bridgebfs(int num) {
	int result = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == num) {
				bfscheck[i][j] = 1;
				q.push({ i,j });
			}
		}
	}
	//cout << "���� ũ��: " << q.size() << '\n';

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {	//������ ������� ���� �� ��ŭ�� ����
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				//�ٴٰ� �ƴϰ� ���� ���� �ƴ϶��
				if (map[nx][ny] != 0 && map[nx][ny] != num) {
					return result;
				}
				//�ٴ��̰�, �湮���� �ʾҴٸ�
				if (map[nx][ny] == 0 && bfscheck[nx][ny] == 0) {
					bfscheck[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
		result++;
	}
}

int main() {
	//�Է¹ް� �� ���� �迭�� ���� ����
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				land.push_back({ i,j });
			}
		}
	}
	//������ ���� ���� ��ȣ �ο��ϱ�
	int islandNum = 1;
	for (int i = 0; i < land.size(); i++) {
		int x = land[i].first;
		int y = land[i].second;
		if (bfscheck[x][y] == 0) {
			labeling(x, y, islandNum);
			islandNum++;
		}
	}

	//print();

	//�ٸ� ���̱�
	answer = 987654321;
	for (int i = 1; i < islandNum; i++) {
		//cout << "�� ��ȣ: " << i << '\n';
		memset(bfscheck, 0, sizeof(bfscheck));
		answer = min(answer, bridgebfs(i));
		//cout << "�ٸ� ����: " << answer << '\n';
	}
	cout << answer;

	return 0;
}