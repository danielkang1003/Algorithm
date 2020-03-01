#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, m, answer;
int map[8][8], c_map[8][8]; //0 빈칸 1 벽 2 바이러스
bool check[8][8];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<pair<int, int>> virus, blank, block;
queue<pair<int, int>> q;
void bfs() {
	//바이러스 넣고 bfs로 돌려주기
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		c_map[virus[i].first][virus[i].second] = 1;
		check[virus[i].first][virus[i].second] = 1;
	}

	while (!q.empty()) {
		int size = q.size();
		for (int s = 0; s < size; s++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (check[nx][ny] == 1) continue;
				if (c_map[nx][ny] == -1) continue;
				q.push({ nx,ny });
				check[nx][ny] = 1;
				c_map[nx][ny] = c_map[x][y] + 1;
			}
		}
	}
}

void copyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c_map[i][j] = map[i][j];
		}
	}
}

int checkArea() {
	int blankArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_map[i][j] == 0)blankArea++;
		}
	}
	return blankArea;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		memset(check, 0, sizeof(check));
		copyMap();
		for (int i = 0; i < block.size(); i++) {
			//cout <<"("<< block[i].first << " " << block[i].second << ") ";
			c_map[block[i].first][block[i].second] = -1;	//뽑아낸 벽 세개를 -1로 해서 이동못하도록
		}
		bfs();
		int temp = checkArea();
		if (temp > answer) answer = temp;
		//cout << '\n';
		return;
	}
	for (int i = idx; i < blank.size(); i++) {
		block.push_back(blank[i]);
		dfs(i + 1, cnt + 1);
		block.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;	//벽을 -1로 변경해줌
			else if (map[i][j] == 2) {
				virus.push_back({ i,j });
				map[i][j] = 1;	//바이러스의 위치를 파악하기 위해 0으로 만듦
				//check[i][j] = 1;
			}
			else if (map[i][j] == 0) {
				//빈칸을 골라내기 위해
				blank.push_back({ i,j });
			}
		}
	}
	//벽 세우기
	dfs(0, 0);
	cout << answer;
	return 0;
}