#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int r, c;
bool meet;
char map[1500][1500];
bool check[1500][1500];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> swanQ, swanNQ, Q, NQ;	//백조 현재 큐, 다음 큐, 물의 현재 큐, 다음 큐
pair<int, int> swan;
//시간초과난 백조의 호수 문제.
//이전의 풀이를 보면 bool type 배열 두개 (각각 물이 녹은 곳과 백조의 이동을 확인함)
//물이 녹은 곳을 맵에서 한번에 변환시켜주기 위해 물이 녹은 위치를 담은 vector
//세가지에 대해 반복문을 돌 때마다 초기화시켜서 시간초과가 뜰 수밖에 없었다.
//풀이를 찾아보니 물의 큐와 백조의 이동 Q를 따로 만들어서 조건마다 다음 방문 점에 대하여 넣어주는 방식으로 푼다고 해서 참고하여서 풀었다.
void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				swan.first = i;
				swan.second = j;
			}
			if (map[i][j] != 'X') {
				Q.push({ i,j });	//물을 다 넣어준다
			}
		}
	}
	//cout << "백조의 위치: " << swan.first << " " << swan.second << '\n';
}

void swanMove() {
	while (!swanQ.empty() && meet == false) {
		int x = swanQ.front().first;
		int y = swanQ.front().second;
		swanQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (check[nx][ny] == 1) continue;
			if (map[nx][ny] == '.') {	//물이면 이동하고 방문표시하기
				swanQ.push({ nx,ny });
				check[nx][ny] = 1;
			}
			else if (map[nx][ny] == 'X') {	//빙하라면 다음에 녹았을 때 이동위해 백조의 다음 이동에 넣어주기
				swanNQ.push({ nx,ny });
				check[nx][ny] = 1;
			}
			else if (map[nx][ny] == 'L') {	//다른 백조만나면 종료
				check[nx][ny] = 1;
				meet = true;
				break;
			}
		}
	}
}

void meltingIce() {
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (map[nx][ny] == 'X') {
				map[nx][ny] = '.';	//녹은것으로 만들기
				NQ.push({ nx,ny });
			}
		}
	}
}

void print(int day) {
	cout << "========Day " << day << "=======\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << "===================\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	input();
	int day = 0;
	meet = false;
	swanQ.push({ swan.first, swan.second });
	check[swan.first][swan.second] = 1;

	while (meet == false) {
		swanMove();	//빙하가 녹기전에 만날수 있음
		if (meet == false) {
			meltingIce();	//물을 녹여줌
			Q = NQ;			//인접한 빙하가 물로 녹은 데이터로 넣어줌
			swanQ = swanNQ;	//백조가 이동할 다음 좌표로 넣어줌
			while (!NQ.empty()) NQ.pop();	//넣어주고 난 후 데이터 비워주기
			while (!swanNQ.empty()) swanNQ.pop();
			//print(day);
			day++;
		}
	}
	cout << day << '\n';

	return 0;
}