#include<iostream>
#include<cstring>
#include<vector>

#define endl '\n';
using namespace std;

char puyo[12][7];	//뒤의 널값도 처리위해 6 + 1
bool check[12][7];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int possibleCnt = 0; //같은색이 네개 이상이 되면 터트리기 위한 변수


vector<pair<int, int>> temp, vec;

void dfs(int x, int y) {

	cout << "\n(DFS 내부) 현재 dfs를 도는 색은 : " << puyo[x][y] << "이고, 좌표는" << x << " " << y << endl;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		//예외 조건 처리 (1. 범위 벗어남, 2. 방문했으면 패스, 3. 색 다르면 패스, 4.빈칸이면 패스
		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
		if (check[nx][ny] == 1) continue;
		if (puyo[nx][ny] != puyo[x][y]) continue;
		if (puyo[nx][ny] == '.') continue;
		//조건에 부합하면 실행
		possibleCnt++;
		check[nx][ny] = 1;
		temp.push_back({ nx,ny });

		cout << "\t 조건에 부합하므로 temp 벡터에 삽입합니다.\n";
		cout << "\t temp 벡터에 넣은 좌표는 nx: " << nx << " ny: " << ny << "이고 들어있는 총 개수는 " << temp.size() << endl;
		cout << "temp 벡터의 현재 상태:" << endl;
		for (int i = 0; i < temp.size(); i++) {
			cout << "\tx: " << temp[i].first << " y: " << temp[i].second << endl;
		}

		dfs(nx, ny);
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> puyo[i][j];
		}
	}

	bool flag;
	int answer = 0;
	while (true) {
		flag = 0;
		memset(check, 0, sizeof(check));
		vec.clear();
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (puyo[i][j] != '.' && check[i][j] == 0) {
					possibleCnt = 1;
					temp.push_back({ i,j });
					check[i][j] = 1;
					cout << "temp 벡터에 들어간 색: " << puyo[i][j] << " 이고 i와 j는 " << temp.front().first << "와 " << temp.front().second << endl;
					dfs(i, j);

					if (possibleCnt >= 4) {
						cout << "tempCnt가 4이상이여서 진입\n현재 tempCnt :" << possibleCnt << endl;
						flag = 1;	//색이 네개 이상 주변에 모여있으면 터트리기 위해 표시남김
						int size = temp.size();	//dfs를 돌며 같은색인 것들

						cout << "현재 색의 개수: " << size << endl;

						for (int i = 0; i < size; i++) {
							vec.push_back(temp[i]);	//터트릴 것 넣어주기
						}

						cout << "터트릴 좌표들: " << endl;
						for (int i = 0; i < size; i++) {
							cout << vec[i].first << " " << vec[i].second << endl;
						}

					}
					temp.clear();
				}
			}
		}

		int size = vec.size();
		for (int i = 0; i < size; i++) {
			int x = vec[i].first;
			int y = vec[i].second;
			puyo[x][y] = '.';	//바꾸어주기
		}

		for (int i = 10; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (puyo[i][j] == '.') continue;
				int temp = i;
				while (true) {
					if (temp == 11 || puyo[temp + 1][j] != '.') break;
					puyo[temp + 1][j] = puyo[temp][j];
					puyo[temp][j] = '.';
					temp++;
				}
			}
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cout << puyo[i][j] << ' ';
			}
			cout << '\n';
		}

		if (flag == true) answer++;
		else break;
	}
	cout << answer << endl;

	return 0;
}