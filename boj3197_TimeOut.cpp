#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int r, c;
char map[1500][1500];
bool check[1500][1500], swanMoveCheck[1500][1500];
vector<pair<int, int>> swan, meltingPos;	//백조 위치 저장, 물이 녹을 곳 저장
bool notMeet = true;
int year;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				swan.push_back({ i,j });
				map[i][j] = '.';	//백조 자리도 물이므로 위치 저장하고 바꾸어줌
			}
		}
	}
}

void meltingIce(int i, int j) {
	check[i][j] = 1;
	int x = i, y = j;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (map[nx][ny] == '.') continue;
		if (check[nx][ny] == 1) continue;
		meltingPos.push_back({ nx,ny });
		check[nx][ny] = 1;
	}
	int size = meltingPos.size();
	for (int i = 0; i < size; i++) {
		int a = meltingPos[i].first, b = meltingPos[i].second;
		map[a][b] = '.';
	}
}

void print() {
	cout << "======" << year << "======\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << "==========================\n";
}

void swanMove() {
	queue<pair<int, int>> q;
	//swan은 두마리임.
	//cout <<"백조 위치: "<< swan[0].first << " " << swan[0].second <<'\n';
	q.push({ swan[0].first, swan[0].second });	//이동할 0번 백조
	swanMoveCheck[swan[0].first][swan[0].second] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == swan[1].first && y == swan[1].second) {
			notMeet = false;
			//cout << "("<<x <<","<< y<<") 에서 만났음\n";
			return;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (swanMoveCheck[nx][ny] == 1) continue;
			if (map[nx][ny] == 'X')continue;
			q.push({ nx,ny });
			swanMoveCheck[nx][ny] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	input();
	while (notMeet) {
		year++;
		memset(check, 0, sizeof(check));
		memset(swanMoveCheck, 0, sizeof(check));
		meltingPos.clear();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (check[i][j] == 0 && map[i][j] == '.') {
					meltingIce(i, j);
				}
			}
		}
		//print();
		swanMove();

	}
	cout << year << '\n';
	return 0;
}