#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int f, s, g, u, d;
bool check[1000001];

int bfs() {
	queue<pair<int, int>> q;
	q.push({ s,0 });	//현위치와 카운트
	check[s] = 1;
	while (!q.empty()) {
		int floor = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (floor == g) return cnt;

		if (floor + u <= f && check[floor + u] == 0) {
			q.push({ floor + u, cnt + 1 });
			check[floor + u] = 1;
		}
		if (floor - d > 0 && check[floor - d] == 0) {
			q.push({ floor - d, cnt + 1 });
			check[floor - d] = 1;
		}
	}
	return -1;
}

int main() {
	cin >> f >> s >> g >> u >> d;
	int answer = bfs();
	if (answer == -1) cout << "use the stairs" << '\n';
	else cout << answer << '\n';
	return 0;
}