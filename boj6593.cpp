#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

int L, R, C;
//int sf, sx, sy, ef, ex, ey;
//pair<pair<int, int>, int> me, door;
vector<pair<pair<int, int>, int>> me, door;
char building[30][30][30];
bool check[30][30][30];
//		   µ¿ ¼­ ³² ºÏ »ó ÇÏ
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int df[6] = { 0,0,0,0,1,-1 };

void bfs(int sf, int sx, int sy) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {sf, sx}, {sy, 0} });	//Ãþ, x,y, ½Ã°£
	check[sf][sx][sy] = 1;
	while (!q.empty()) {
		int floor = q.front().first.first;
		int x = q.front().first.second;
		int y = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (x == door[0].first.second && y == door[0].second && floor == door[0].first.first) {
			cout << "Escaped in " << cnt << " minute(s).\n";
			return;
		}

		for (int dir = 0; dir < 6; dir++) {
			int nf = floor + df[dir];
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nf < 0 || nx < 0 || ny < 0 || nf >= L || nx >= R || ny >= C) continue;
			if (building[nf][nx][ny] == '#') continue;
			if (check[nf][nx][ny] == 1) continue;
			check[nf][nx][ny] = 1;
			q.push({ {nf,nx},{ny,cnt + 1} });
		}
	}
	cout << "Trapped!\n";
	return;
}

int main() {
	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		memset(check, 0, sizeof(check));
		me.clear(), door.clear();
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') {
						//sf = i, sx = j, sy = k;
						/*me.first.first = i;
						me.first.second = j;
						me.second = k;*/
						me.push_back({ {i,j}, k });
					}
					else if (building[i][j][k] == 'E') {
						//ef = i, ex = j, ey = k;
						/*door.first.first = i;
						door.first.second = j;
						door.second = k;*/
						door.push_back({ {i,j}, k });
					}
				}
			}
		}
		//bfs(me.first.first, me.first.second, me.second);
		bfs(me.front().first.first, me.front().first.second, me.front().second);
	}
	return 0;
}