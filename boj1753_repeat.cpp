#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

//다시 풀어본 문제!
using namespace std;

int V, E, K, u, v, w;
int dist[20001];
vector<vector<pair<int, int>>> adj;
int main() {
	cin >> V >> E >> K;
	adj.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
	}

	memset(dist, -1, sizeof(dist));
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,K });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] != -1) continue;
		dist[cur] = cost;
		int size = adj[cur].size();
		for (int i = 0; i < size; i++) {
			int nxt = adj[cur][i].first;
			int nxtCost = adj[cur][i].second + cost;
			if (dist[nxt] != -1) continue;
			pq.push({ -nxtCost, nxt });
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == -1) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	return 0;
}

