#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;	//헛간 개수, 헛간과 연결된 길
int a, b;	//연결된 헛간들
vector<int> hide[20001];
int dist[20001];

//헛간의 거리 체크
void bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int size = hide[cur].size();
		for (int i = 0; i < size; i++) {
			int nxt = hide[cur][i];
			if (dist[nxt] == 0) {
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		hide[a].push_back(b);
		hide[b].push_back(a);
	}

	bfs(1);

	//가장 먼거리와 숨어있는 장소 고르기
	int max_dist = 0, place = 0;
	for (int i = 2; i <= n; i++) {
		if (dist[i] > max_dist) {
			max_dist = dist[i];
			place = i;
		}
	}
	//같은 거리의 헛간 개수를 세줌
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (dist[i] == max_dist) {
			cnt++;
		}
	}

	cout << place << ' ' << max_dist - 1 << ' ' << cnt;
	return 0;
}