#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int INF = 987654321;
int v, e, k, u1, u2, w;
vector<pair<int, int>> adj[20001];

vector<int> dijkstra() {
	vector<int> dist(v, INF);
	dist[k] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ k, 0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int next = adj[cur][i].first;
			int nextCost = cost + adj[cur][i].second;
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, -nextCost });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> v >> e >> k;
	v++;
	for (int i = 1; i <= e; i++) {
		cin >> u1 >> u2 >> w;
		adj[u1].push_back({ u2, w });
	}

	vector<int> answer = dijkstra();

	for (int i = 1; i < v; i++) {
		if (answer[i] == INF) cout << "INF\n";
		else cout << answer[i] << '\n';
	}
	return 0;
}