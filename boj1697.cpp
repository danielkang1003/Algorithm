#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100001;

int n, k;
bool check[MAX];
int dx[3] = { 1,-1,2 };

void bfs(int pos) {
	queue<pair<int, int>> q;
	q.push({ pos, 0 });
	check[pos] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == k) {
			cout << cnt << '\n';
			return;
		}
		for(int dir = 0; dir < 3; dir++){
			int nx;
			if (dir == 2) nx = x * dx[dir];
			 else nx = x + dx[dir];
			
			if (nx < 0 || nx >= MAX) continue;
			if (check[nx] == 0) {
				q.push({ nx, cnt + 1 });
				check[nx] = 1;
			}
		}
		/*if (x * 2 < MAX) {
			if (check[x * 2] == 0) {
				q.push({ x * 2, cnt + 1 });
				check[x * 2] = 1;
			}
		}
		if (x + 1 >= 0 && x + 1 < MAX) {
			if (check[x + 1] == 0) {
				q.push({ x + 1, cnt + 1 });
				check[x + 1] = 1;
			}
		}
		if (x - 1 >= 0 && x - 1 < MAX) {
			if (check[x - 1] == 0) {
				q.push({ x - 1, cnt + 1 });
				check[x - 1] = 1;
			}
		}*/
	}
}

int main() {
	cin >> n >> k;
	bfs(n);
	return 0;
}