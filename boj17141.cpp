#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, m, answer = 987654321;
int map[50][50], c_map[50][50];
bool check[50][50], dfsCheck[10];	//바이러스가 10개 최대므로 dfscheck = 10크기

//인접 방향 동서남북으로 탐색
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<pair<int, int>> v, virus;	//조합을 위해 v에 바이러스 놓을 수 있는 자리 저장, virus는 조합으로 골라진 바이러스 퍼트리기위함
queue<pair<int, int>> q;			//조합으로 골라진 바이러스 돌리기

int minimum(int a, int b) {
	return a < b ? a : b;
}

bool checkPossible() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c_map[i][j] == -1) continue;
			if (check[i][j] == 0) return false;
		}
	}
	return true;
}

void bfs() {
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int s = 0; s < size; s++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;	//범위 밖
				if (c_map[nx][ny] == -1) continue;						//벽
				if (check[nx][ny] == 1) continue;						//이미 방문
				q.push({ nx,ny });
				c_map[nx][ny] = c_map[x][y] + 1;	//이동시간 + 1
				check[nx][ny] = 1;
				//cout << "현재 (" << x << ',' << y << ") 에서 (" << nx << ',' << ny << ")로 이동\n";
			}
		}
		if (size != 0) cnt++;
	}
	if (checkPossible() == true) answer = min(answer, cnt);
}

void copyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c_map[i][j] = map[i][j];
		}
	}
}

void print() {
	cout << "==========결과========\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c_map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "======================\n";
}

void dfs(int idx, int cnt) {
	if (cnt == m) {	//조합으로 뽑아낸 갯수가 지정해준 갯수라면 실행
		memset(check, 0, sizeof(check));	//최소시간을 구할 것이기에 매번 초기화해주기
		copyMap();							//맵도 새로운 맵에서 다시해야하므로 초기화
		//cout << "조합 시도:";
		for (int i = 0; i < virus.size(); i++) {
			//cout << "(" << virus[i].first << " " << virus[i].second << ") ";
			//큐에 넣어줘서 돌리기
			q.push({ virus[i] });
			check[virus[i].first][virus[i].second] = 1;	//현재 지점 방문 표시
			c_map[virus[i].first][virus[i].second] = 1;	//시작점 1로 만들고 시작. 나중에 최소시간에서 -1 해주기
		}
		bfs();
		//print();
		//cout << '\n';
		return;
	}
	for (int i = idx; i < v.size(); i++) {	//v에는 바이러스 놓을 수 있는 곳의 좌표가 담겨있음. 조합
		if (dfsCheck[i] == 0) {
			dfsCheck[i] = 1;
			virus.push_back({ v[i].first, v[i].second });
			dfs(i + 1, cnt + 1);
			virus.pop_back();
			dfsCheck[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
				map[i][j] = 0;	//바이러스가 있던 자리도 선택되지않아 놓지않는다면 0으로 만들어줘서 이동할 수 있도록 만듬
			}
			else if (map[i][j] == 1) {
				map[i][j] = -1;	//-1로 만들어서 최소시간과 겹치지 않도록
			}
		}
	}
	dfs(0, 0);	//바이러스 조합으로 최소 시간 출력할 것
	if (answer == 987654321) cout << "-1\n";
	else cout << answer - 1 << '\n';
	return 0;
}