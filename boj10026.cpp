#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n;
char map[101][101];	//RGB
bool check[100][100];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

//void print() {
//	cout << "########################\n";
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << map[i][j];
//		}
//		cout << '\n';
//	}
//	cout << "########################\n";
//}

void bfs(int sx, int sy, char color) {
	queue<pair<pair<int, int>, char>> q;
	q.push({ {sx,sy}, color });
	check[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		char curColor = q.front().second;
		q.pop();
		//cout << "현재 x: " << x << " y: " << y << " 색깔: " << curColor << '\n';
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] != curColor) continue;
			//if (map[nx][ny] != map[x][y]) continue;	매개변수로 색 빼고 이렇게도 가능
			if (check[nx][ny] == 1)continue;
			q.push({ {nx,ny}, curColor });
			check[nx][ny] = 1;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		int len = input.length();
		for (int j = 0; j < len; j++) {
			if (input[j] == 'R') {
				map[i][j] = 'R';
			}
			else if (input[j] == 'B') {
				map[i][j] = 'B';
			}
			else if (input[j] == 'G') {
				map[i][j] = 'G';
			}
		}
	}
	//print();
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {

				++answer;
				//cout << "현재 색: " << map[i][j] << " 찾은 색 개수: " << answer <<'\n';
				bfs(i, j, map[i][j]);
			}
		}
	}
	cout << answer << ' ';
	memset(check, 0, sizeof(check));
	answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				++answer;
				//cout << "현재 색: " << map[i][j] << " 찾은 색 개수: " << answer << '\n';
				bfs(i, j, map[i][j]);
			}
		}
	}
	cout << answer;
	return 0;
}