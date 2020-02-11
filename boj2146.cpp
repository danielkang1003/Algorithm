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
		//cout << "(" << x << ',' << y << ") 좌표 차례입니다\n";
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
	//cout << "섬의 크기: " << q.size() << '\n';

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {	//위에서 집어넣은 원소 수 만큼만 실행
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				//바다가 아니고 같은 섬이 아니라면
				if (map[nx][ny] != 0 && map[nx][ny] != num) {
					return result;
				}
				//바다이고, 방문하지 않았다면
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
	//입력받고 섬 벡터 배열에 따로 저장
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				land.push_back({ i,j });
			}
		}
	}
	//인접한 섬에 같은 번호 부여하기
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

	//다리 붙이기
	answer = 987654321;
	for (int i = 1; i < islandNum; i++) {
		//cout << "섬 번호: " << i << '\n';
		memset(bfscheck, 0, sizeof(bfscheck));
		answer = min(answer, bridgebfs(i));
		//cout << "다리 길이: " << answer << '\n';
	}
	cout << answer;

	return 0;
}